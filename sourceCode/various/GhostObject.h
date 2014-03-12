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

#include <7Vector.h>

class CGhostObject
{
public:
	CGhostObject(); // only for serialization
	CGhostObject(int theGroupId,int theObjectHandle,C7Vector theTr,int theOptions,float theStartTime,float theEndTime,const float theColor[12]);
	virtual ~CGhostObject();

	void render(int displayAttributes,float simulationTime,float realTime);
	void modifyAttributes(int theOptions,int theOptionsMask);
	CGhostObject* copyYourself();

	int groupId;
	int ghostId;
	int objectHandle;
	int options;
	float startTime;
	float endTime;
	unsigned char transparencyFactor; // 0=opaque, 255=totally transparent
	float color[12];
	C7Vector tr;
};
