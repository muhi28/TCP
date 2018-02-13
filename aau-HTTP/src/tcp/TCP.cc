//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
// (c) 2017 Christian Timmerer, Alpen-Adria-Universität Klagenfurt / Bitmovin Inc.
//          christian.timmerer@itec.aau.at / christian.timmerer@bitmovin.com
//
// 621.800 (17W) Computer Networks and Network Programming

/* TCP: Protokollnummer 6
 *
 * TCPControlinfo tcpinfo -> Set fields in HTTPClient::initialize()
 * msg->setControllinfo(TCPinfo)
 * send(msg, out);
 *
 * HTTPServer Initialize()
 * Init ClientIpv4 = new Ipv4Address();
 *
 * HandleMessage
 * -> cPacket *smsg = check and cast <cPacket*> (msg);
 * TCPControllinfo *tcpInfo = Check_and_cast<TCPControlinfo*>(serverMsg->getControlInfo);
 *
 * Sync-Bit:
 * OppositeSeqNum = tcpSeg -> getSeqnr();
 * TcpSeg -> set
 * incommingTransmission = true;
 * send(newTCPSegment, out);
 *
 * if(receivedAckNum == (mySeqNum+1))
 * tcpControlinfo->setTcpStatus(TCP_STATUS_OPEN);
 * send(cInfo, out);
 *
 * tcp-seg_c -> tcp-seg_s
 * TCPControllinfo -> App
 */

#include "TCP.h"
#include <stdio.h>
#include "../3rdParty/IPv4Address.h"
#include "../3rdParty/IPv6Address.h"
#include "TCPControlInfo_m.h"
#include "TCPSegment_m.h"

Define_Module(TCP);

int seqNr, ackNr, seqNew, ackNew, headerLength, payload;
bool connection_setup, dataTransmission, connection_teardown;

std::vector<TCPSegment*> messageVector;

void TCP::initialize()
{
    seqNr = 100;
    ackNr = 0;
    payload = 1;
    headerLength = 20;
    connection_setup = true;

    if(getParentModule()->getFullName() == "Server") // FIXME Server !== Server
    {
        // Redundant due to default-vals
        bubble("listen()!");
        TCPControlInfo* tci = new TCPControlInfo;
        tci->setDestPort(80);
        send(tci, "toUpperLayer");
    }
}

void TCP::handleMessage(cMessage *msg){
    if (msg->arrivedOn("fromUpperLayer")) {
        // Comes from appliction.
        this->handleAppMessage((cPacket*)msg);

    }else if (msg->arrivedOn("fromLowerLayer")) {
        // Comes from lower layer <-> TCPSeg
        // Packet Loss
        messageVector.push_back(check_and_cast<TCPSegment*>(msg->dup()));


        if (uniform(0, 1) < 0.45) {
        // Lost Message
           bubble("message lost");
           delete msg;
           scheduleAt(simTime(),  messageVector.back());
        }else{
        // Msg not Lost
        this->handleTCPSegment((cPacket*) msg);
        }

    }else if (msg->isSelfMessage()) {
        TCPSegment* ts = check_and_cast<TCPSegment*>(msg);
        this->handleTCPSegment((cPacket*) ts);

    }
}

void TCP::handleAppMessage(cPacket *msg)
{
    TCPControlInfo* tci = check_and_cast<TCPControlInfo*>(msg->getControlInfo());

    if(tci->getTcpStatus() == 2 && tci->getTcpCommand() == 1)   // Con is closed && required to open con
    {
        bubble("connection started");

        TCPSegment* ts_out = new TCPSegment;
        ts_out->setSyn(true);
        ts_out->setSeqNr(seqNr);

        send(ts_out, "toLowerLayer");
    }
    if(tci->getTcpStatus() == 1 && tci->getTcpCommand() == 0 ) // TCP do nothing -- Connection is open
    {
        TCPSegment* ts_out = new TCPSegment;
                ts_out->setAck(true);
                ts_out->setSeqNr(seqNr);
                ts_out->setAckNr(ackNr);

                ts_out->encapsulate(msg);               // HTTP*Message encapsulated & to next operator

                send(ts_out, "toLowerLayer");
    }
    if(tci->getTcpStatus() == 1 && tci->getTcpCommand() == 2) // TCP close Con -- Con is open
    {
        connection_teardown = false;

        TCPSegment* ts_out = new TCPSegment;
        ts_out->setFin(true);
        ts_out->setAck(true);
        ts_out->setSeqNr(seqNr);
        ts_out->setAckNr(ackNr);

        send(ts_out, "toLowerLayer");
    }
}

void TCP::handleTCPSegment(cPacket *msg)
{
    TCPSegment* ts = check_and_cast<TCPSegment*>(msg);
    ackNr = ts->getAckNr();
    seqNr = ts->getSeqNr();

    // Case 1
    if(ts->getSyn()  && !ts->getAck()  && connection_setup)
    {
              TCPSegment* ts = new TCPSegment;
              ackNew = seqNr + payload;    // Seq+Payload
              seqNew = rand() % 301;

              ts->setSyn(true);
              ts->setAck(true);
              ts->setSeqNr(seqNew);
              ts->setAckNr(ackNew);

              send(ts, "toLowerLayer");
    }

    //CASE 2
    if(ts->getSyn() && ts->getAck() && connection_setup)
    {
            bubble("connection finished!");
              cPacket* p = new cPacket;
              TCPControlInfo* tci = new TCPControlInfo;
              // connection open()
              tci->setTcpStatus(1);
              tci->setTcpCommand(0);

              p->setControlInfo(tci);
              send(p, "toUpperLayer");

              connection_setup = false;
              dataTransmission = true;

              // Response for server
              TCPSegment* ts = new TCPSegment;
              ackNew = seqNr + payload;    // Seq+Payload
              seqNew = ackNr;
              ts->setAck(true);
              ts->setAckNr(ackNew);
              ts->setSeqNr(seqNew);

              send(ts, "toLowerLayer");

    }
    //CASE 3
    if(ts->getAck()  && !ts->getSyn()  && dataTransmission)
    {

        cPacket *cp = msg->decapsulate();

        if (cp == nullptr) {

        }else{

            TCPControlInfo *tci = new TCPControlInfo;
            tci->setTcpCommand(0); // 0 --> do nothing
            tci->setTcpStatus(1); // 1 --> open connection

            cp->setControlInfo(tci);

            send(cp, "toUpperLayer");
        }

    }

    // DISCONNCET CASE 1
    if(ts->getFin() && ts->getAck() && !connection_teardown)
    {
       connection_teardown = true; // disconnection setup

       TCPSegment *ts = new TCPSegment;

       ts->setFin(true);
       ts->setAck(true);
       ts->setAckNr(seqNr + payload);
       ts->setSeqNr(ackNr);

       send(ts, "toLowerLayer");
    }

    //DISCONNECT CASE 2
    if(ts->getFin() && ts->getAck() && connection_teardown)
    {
           TCPSegment *ts = new TCPSegment;

           ts->setFin(true);
           ts->setAck(false);
           ts->setAckNr(seqNr + payload);
           ts->setSeqNr(ackNr);

           send(ts, "toLowerLayer");
     }

    //DISCONNECT CASE 3
    if (ts->getFin() && !ts->getAck() && connection_teardown)
    {
        cPacket *cp = new cPacket;
        TCPControlInfo *tci = new TCPControlInfo;

        tci->setTcpCommand(0);
        tci->setTcpStatus(2);

        cp->setControlInfo(tci);

        send(cp, "toUpperLayer");
    }

    //DISCONNECT CASE 4
    if(ts->getFin() && !ts->getAck() && !connection_teardown)
    {
       connection_teardown = true;

       cPacket *cp = new cPacket;

       TCPControlInfo *tci = new TCPControlInfo;

       tci->setTcpCommand(0); //0 --> do nothing
       tci->setTcpStatus(2); // 2 --> connection closed
       cp->setControlInfo(tci);
       send(cp, "toUpperLayer");

    }
}



