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

#include "RegDist.h"
#include <vector>
#include "MainCont.h"

class CRegisteredDistances : public CMainCont 
{
public:
	CRegisteredDistances();
	virtual ~CRegisteredDistances();

	void simulationAboutToStart();
	void simulationEnded();
	void renderYour3DStuff(CViewableBase* renderingObject,int displayAttrib);
	int addNewObject(int obj1ID,int obj2ID,std::string objName);
	void addObject(CRegDist* newDistObj,bool objectIsACopy);
	void addObjectWithSuffixOffset(CRegDist* newDistObj,bool objectIsACopy,int suffixOffset);
	void getMinAndMaxNameSuffixes(int& minSuffix,int& maxSuffix);
	bool canSuffix1BeSetToSuffix2(int suffix1,int suffix2);
	void setSuffix1ToSuffix2(int suffix1,int suffix2);
	bool removeObject(int objID);
	CRegDist* getObject(int objID);
	CRegDist* getObject(std::string objName);
	void removeAllDistanceObjects();
	void resetAllDistances(bool exceptExplicitHandling);
	void announceObjectWillBeErased(int objID);
	void announceGroupWillBeErased(int groupID);
	void setUpDefaultValues();
	float handleAllDistances(bool exceptExplicitHandling);
	bool setObjectName(int objID,std::string newName);
	void displayDistanceSegments();

	// Variable that need to be serialized on an individual basis:
	std::vector<CRegDist*> distanceObjects;
};

