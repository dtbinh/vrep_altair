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

#include <vector>

class COutsideCommandQueueForScript  
{
public:
	COutsideCommandQueueForScript();
	virtual ~COutsideCommandQueueForScript();

	bool addCommand(int commandID,int auxVal1,int auxVal2,int auxVal3,int auxVal4,const float* aux2Vals,int aux2Count);
//	int extractOneCommand(int auxVals[4]);
	int extractOneCommand(int auxVals[4],float aux2Vals[8],int& aux2Count);
	void initializeInitialValues(bool simulationIsRunning);
	void simulationEnded();

private:
	void _checkSelections();
	std::vector<int> commands; // for each command, there are 4 auxiliary values, and 8 aux2 values!
	std::vector<int> auxValues;
	std::vector<float> aux2Values;
	std::vector<int> aux2Cnt;

	std::vector<int> previousObjectSelection; // In order to generate the sim_message_object_selection_changed
	bool flagToCompareSelections;
};
