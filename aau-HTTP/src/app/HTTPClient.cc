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

#include "HTTPClient.h"
#include "HTTPClientMsg_m.h"
#include "HTTPServerMsg_m.h"
#include "../tcp/TCPControlInfo_m.h"


#define MAX_MESSAGE_COUNT 3

Define_Module(HTTPClient);

char const* request = "";
char const* method = "GET";
int tcpCommand, tcpStatus;
int messageCounter = 0;
bool clientDataTransmission, clientConnectionSetup;

inet::IPv4Address ipv4_client, ipv4_server;
inet::IPv6Address ipv6_client, ipv6_server;

std::vector<std::string> received_resources;


void HTTPClient::initialize()
{
    ipv4_client = inet::IPv4Address("209.173.21.12");
    ipv6_client = inet::IPv6Address("0:0:0:0:0:ffff:d1ad:150c");
    ipv4_server = inet::IPv4Address("209.173.21.12");
    ipv6_server = inet::IPv6Address("0:0:0:0:0:ffff:d1ad:150c");
    destPort = par("destPort");
    srcPort = par("srcPort");


    scheduleAt(simTime(), new HTTPClientMsg);
}

void HTTPClient::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage())
    {
        bubble("open connection!");
        // CONNECT
        tcpCommand = 1;     // Open Connection
        tcpStatus = 2;      // Connection is closed

        HTTPClientMsg* hcm = new HTTPClientMsg;

        TCPControlInfo* tci = new TCPControlInfo;
        tci->setDestIPv4(ipv4_server);
        tci->setDestIPv6(ipv6_server);
        tci->setDestPort(destPort);
        tci->setSrcIPv4(ipv4_client);
        tci->setSrcIPv6(ipv6_client);
        tci->setSrcPort(srcPort);
        tci->setTcpCommand(tcpCommand);
        tci->setTcpStatus(tcpStatus);

        hcm->setControlInfo(tci);
        send(hcm, "toLowerLayer");

        clientConnectionSetup = true;

    }else{
        TCPControlInfo* tci = check_and_cast<TCPControlInfo*>(msg->getControlInfo());
        HTTPServerMsg* hsm = (HTTPServerMsg*)msg;

        tcpCommand = tci->getTcpCommand();
        tcpStatus = tci->getTcpStatus();
        if(tcpCommand == 0 && tcpStatus == 1 && clientConnectionSetup)  // TCP do nothing -- Connection is open
            {
                clientConnectionSetup = false;
                clientDataTransmission = true;

                // connection open -> HTTPMessage(get)
                request = "index.html";
                HTTPClientMsg* hcm = new HTTPClientMsg;
                hcm->setRequest(request);
                hcm->setMethod(method);
                TCPControlInfo* tci = new TCPControlInfo;
                        tci->setDestIPv4(ipv4_server);
                        tci->setDestIPv6(ipv6_server);
                        tci->setDestPort(destPort);
                        tci->setSrcIPv4(ipv4_client);
                        tci->setSrcIPv6(ipv6_client);
                        tci->setSrcPort(srcPort);
                        tci->setTcpCommand(tcpCommand);
                        tci->setTcpStatus(tcpStatus);

                        hcm->setControlInfo(tci);


                bubble("send request!");
                send(hcm, "toLowerLayer");
            }

            if (tcpCommand == 0 && tcpStatus == 1 && clientDataTransmission)
            {


                messageCounter++;

                if (messageCounter == MAX_MESSAGE_COUNT) {


                    bubble("close connection");
                    tcpCommand = 2;
                    tcpStatus = 1;

                    HTTPClientMsg* hcm = new HTTPClientMsg;
                    TCPControlInfo* tci = new TCPControlInfo;
                        tci->setDestIPv4(ipv4_server);
                         tci->setDestIPv6(ipv6_server);
                       tci->setDestPort(destPort);
                         tci->setSrcIPv4(ipv4_client);
                          tci->setSrcIPv6(ipv6_client);
                            tci->setSrcPort(srcPort);
                          tci->setTcpCommand(tcpCommand);
                          tci->setTcpStatus(tcpStatus);

                          hcm->setControlInfo(tci);

                      send(hcm, "toLowerLayer");

                }

            }

    }
}
