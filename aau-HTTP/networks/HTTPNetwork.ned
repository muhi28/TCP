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

package networks;

import networks.ClientHost;
import networks.ServerHost;

channel connection extends ned.DatarateChannel	// Hardwareconnection between devices
{
 	delay = 5ms;
 	datarate = 10Mbps;   
}

network HTTPNetwork
{
    parameters:
        // TODO add global parameters if needed
    
    @display("bgb=400, 300");
    submodules:
	Client: ClientHost{
	 	@display("p=100, 150"); 
	}
	Server: ServerHost{
	 	@display("p=300, 150");   
	}
        
    connections:
		Client.outNet-->connection-->Server.inNet;
		Server.outNet-->connection-->Client.inNet;
}
