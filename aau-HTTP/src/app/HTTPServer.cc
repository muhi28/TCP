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

#include "HTTPServer.h"
#include "HTTPClientMsg_m.h"
#include "HTTPServerMsg_m.h"
#include "../tcp/TCPControlInfo_m.h"

Define_Module(HTTPServer);

int tcpServerCommand, tcpServerStatus;
inet::IPv4Address ipv4_clientIP, ipv4_serverIP;
inet::IPv6Address ipv6_clientIP, ipv6_serverIP;


std::vector<std::string> data{("<html>\n"
        "\t<head><title>Test</title></head>\n"
        "\t<body>\n"
        "\t\t<img src=\"logo.gif\" />\n"
        "\t\t<h1>Welcome</h1>\n"
        "\t\t<img src=\"TechnikErleben.png\" />\n"
        "\t</body>\n"
        "</html>\n"),
        "logo.gif",
        "TechnikErleben.png"};

void HTTPServer::initialize()
{
    tcpServerCommand = 0;
    tcpServerStatus = 2;
    //ipv4_client = inet::IPv4Address("209.173.21.12");             -- We do not know these at current
    //ipv6_client = inet::IPv6Address("0:0:0:0:0:ffff:d1ad:150c");  -- We do not know these at current
    ipv4_serverIP = inet::IPv4Address("209.173.21.12");
    ipv6_serverIP = inet::IPv6Address("0:0:0:0:0:ffff:d1ad:150c");
    destPort = par("destPort");
    //srcPort = par("srcPort");                                     -- We do not know these at current


}

void HTTPServer::handleMessage(cMessage *msg)
{
    // FIXME Blind code below

    TCPControlInfo *tci = check_and_cast<TCPControlInfo*>(msg->getControlInfo());

    if (tci->getTcpStatus() == 1) {
        HTTPClientMsg* hcm = check_and_cast<HTTPClientMsg*>(msg);



                // Read request
                std::string request = hcm->getRequest();
                std::string method = hcm->getMethod();

                if(method == "GET")
                {
                    bubble("send response");

                    //+++++++++++++++++ Message 1 +++++++++++++++
                    HTTPServerMsg *sm1 = new HTTPServerMsg;
                    TCPControlInfo *tci1 = new TCPControlInfo;

                    tci1->setTcpCommand(0);
                    tci1->setTcpStatus(1);

                    sm1->setResponse(data[0].c_str());
                    sm1->setControlInfo(tci1);

                    EV << sm1->getResponse() << std::endl;

                    send(sm1, "toLowerLayer");


                    //+++++++++++++++ Message 2 ++++++++++++++++++
                    HTTPServerMsg *sm2 = new HTTPServerMsg;
                    TCPControlInfo *tci2 = new TCPControlInfo;
                    tci2->setTcpCommand(0);
                    tci2->setTcpStatus(1);

                    sm2->setResponse(data[1].c_str());
                    sm2->setControlInfo(tci2);


                    EV << sm2->getResponse() << std::endl;
                    send(sm2, "toLowerLayer");


                    //+++++++++++++++ Message 3 ++++++++++++++++++
                    HTTPServerMsg *sm3 = new HTTPServerMsg;
                    TCPControlInfo *tci3 = new TCPControlInfo;

                    tci3->setTcpCommand(0);
                    tci3->setTcpStatus(1);

                    sm3->setResponse(data[2].c_str());
                    sm3->setControlInfo(tci3);

                    EV << sm3->getResponse() << std::endl;
                    send(sm3, "toLowerLayer");



                }else{
                    bubble("Wrong Method. Terminating.");
                    EV << "Wrong Method. Terminating." << std::endl;
                }
    }
    else if(tci->getTcpStatus() == 2){ // CLOSE CONNECTION

            tcpServerCommand = 0;
            tcpServerStatus = 2;



    }

}
