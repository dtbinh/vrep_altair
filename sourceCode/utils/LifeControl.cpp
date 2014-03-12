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

#include "vrepPrecompiledHeader.h"
#include "v_rep_internal.h"
#include "LifeControl.h"
#include <algorithm>

CLifeControl::CLifeControl()
{

}

CLifeControl::~CLifeControl()
{

}

int CLifeControl::getLifeID()
{
	livingThings.push_back(nextID);
	nextID++;
	return(nextID-1);
}
void CLifeControl::announceDeath(std::vector<int>& lifeIDs)
{
	for (int i=0;i<int(lifeIDs.size());i++)
		announceDeath(lifeIDs[i]);
}
void CLifeControl::announceDeath(int lifeID)
{
	if (lifeID!=-1)
		livingThings.erase(std::remove(livingThings.begin(),livingThings.end(),lifeID),livingThings.end());
}
bool CLifeControl::isAlive(int lifeID)
{
	if (lifeID==-1)
		return(true); // -1 is always alive!
	return(std::find(livingThings.begin(),livingThings.end(),lifeID)!=livingThings.end());
}


int CLifeControl::nextID=0;
std::vector<int> CLifeControl::livingThings;
