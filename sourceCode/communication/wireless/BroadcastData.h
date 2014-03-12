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

class CBroadcastData  
{
public:
	CBroadcastData(int emitterID,int targetID,int dataHeader,std::string& dataName,float timeOutSimulationTime,float actionRadius,int antennaHandle,float emissionAngle1,float emissionAngle2,const char* data,int dataLength);
	virtual ~CBroadcastData();

	char* receiveData(int receiverID,float simulationTime,int dataHeader,std::string& dataName,int antennaHandle,int& dataLength,int& senderID,int& dataHeaderR,std::string& dataNameR,bool removeMessageForThisReceiver);
	bool doesRequireDestruction(float simulationTime);
	bool receiverPresent(int receiverID);
	int getAntennaHandle();

protected:
	int _emitterID;
	int _dataHeader;
	std::string _dataName;
	int _receiverID;
	float _timeOutSimulationTime;
	float _actionRadius;
	int _antennaHandle;
	float _emissionAngle1;
	float _emissionAngle2;
	char* _data;
	int _dataLength;
	std::vector<int> _receivedReceivers;
};
