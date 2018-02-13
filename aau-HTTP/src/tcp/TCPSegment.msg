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

packet TCPSegment {
    int srcPort = -1;     // source port
    int destPort = -1;     // destination port 
    int seqNr = 0;		// sequence number 32 bit
    int ackNr = 0;		// acknowledgement number 32 bit
    bool ack = false;	// ACK flag indicating the ackNr is valid
    bool syn = false;	// SYN flag for connection establishment
    bool fin = false;	// FIN flag for connection release

    // not needed :)
    bool rst = false;	// RST flag for connection reset
    int headerLength = 0;	// 4 bit header length -> number of 32 bit words
    int receiveWindow = 0;	// 16 bit receive window
    bool psh = false;	// PSH flag for indicting immediate passing on of information
    bool urg = false;	// URG flag for indicating 'urgent' segments (by app layer)
}
