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

import src.app.HTTPClient;
import src.tcp.TCP;

module ClientHost
{
    @display("bgb=350, 300");

    gates:
        input inNet;
        output outNet;

    submodules:
		ApplicationLayer: HTTPClient{
           @display("p=175,75");
        }
        NetworkLayer: TCP {
            @display("p=175,200");
        }

    connections:
        inNet --> {delay = 5ms;} --> NetworkLayer.fromLowerLayer;

        NetworkLayer.toUpperLayer --> {delay = 5ms;} --> ApplicationLayer.fromLowerLayer;
        ApplicationLayer.toLowerLayer --> {delay = 5ms;} --> NetworkLayer.fromUpperLayer;

		NetworkLayer.toLowerLayer--> {delay = 5ms;} --> outNet;
}