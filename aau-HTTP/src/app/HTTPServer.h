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

#ifndef __AAU_HTTP_LSG_HTTPSERVER_H_
#define __AAU_HTTP_LSG_HTTPSERVER_H_

#include <omnetpp.h>
#include "../3rdParty/IPv4Address.h"
#include "../3rdParty/IPv6Address.h"

using namespace omnetpp;

class HTTPServer : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    inet::IPv4Address *serverIPv4;
    inet::IPv4Address *clientIPv4;
    inet::IPv6Address *serverIPv6;
    inet::IPv6Address *clientIPv6;
    int srcPort;
    int destPort;
};

#endif
