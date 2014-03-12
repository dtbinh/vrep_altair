// This file is part of V-REP, the Virtual Robot Experimentation Platform.
// 
// Copyright 2006-2014 Dr. Marc Andreas Freese. All rights reserved. 
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
// 
// V-REP is dual-licensed, under the terms of EITHER (at your option):
//   1. V-REP commercial license (contact us for details)
//   2. GNU GPL (see below)
// 
// GNU GPL license:
// -------------------------------------------------------------------
// V-REP is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// V-REP is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with V-REP.  If not, see <http://www.gnu.org/licenses/>.
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.1.0 on January 20th 2014

#pragma once

#include <string>
#include <vector>

class CCommTube
{

public:
	CCommTube(int header,const std::string& identifier,int firstPartner,bool killAtSimulationEnd,int readBufferSize);
	~CCommTube();

	bool isConnected();
	void connectPartner(int secondPartner,bool killAtSimulationEnd,int readBufferSize);
	bool disconnectPartner(int partner); // return value true means this object needs destruction
	bool simulationEnded(); // return value true means this object needs destruction
	bool writeData(int partner,char* data,int dataSize); // data is not copied!
	char* readData(int partner,int& dataSize); // data is not copied!
	bool isPartnerThere(int partner);
	bool isSameHeaderAndIdentifier(int header,const std::string& identifier);
	int getTubeStatus(int tubeHandle,int& readBufferFill,int& writeBufferFill); // -1: not existant, 0: not connected, 1: connected

protected:

	void _removeAllPackets();
	void _removePacketsOfPartner(int partnerIndex);
	void _swapPartners();

	int _header;
	std::string _identifier;
	int _partner[2];
	bool _killPartnerAtSimulationEnd[2]; // false --> don't kill
	int _readBufferSizes[2];
	std::vector<char*> _packets[2]; // _packets[0] is from partner2 to partner1, packets[1] is from partner1 to partner2
	std::vector<int> _packetSizes[2];
};
