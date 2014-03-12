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

#include "GraphData.h"

class CGraphingRoutines
{
public:
	CGraphingRoutines();
	virtual ~CGraphingRoutines();

	static void resetAllGraphs(bool exceptExplicitHandling);
	static void handleAllGraphs(bool exceptExplicitHandling,float time);

	static std::string getDataUnit(CGraphData* it);
	static void adjustDataToUserMetric(CGraphData* it,float& v,int derivativeIntegralOrCumulative);
	static void getCyclicAndRangeValues(CGraphData* it,bool& cyclic,float& range);

	static bool getDataName(int objectType,int dataIndex,std::string& dataName);
	static bool getDataValue(int objectType,int dataIndex,int objectID,float& value,const C7Vector* graphCTM=NULL);
	static bool getGraphObjectName(int objectType,int dataIndex,int objectID,std::string& objName);
	static bool getObjectsFromGraphCategory(int objectType,int index,int dataIndex,int& objectID);

	// general:
	static bool loopThroughAllAndGetDataName(int dataIndex,std::string& dataName);
	static bool loopThroughAllAndGetDataValue(int dataIndex,int objectID,float& value,const C7Vector* graphCTM=NULL);

	static bool loopThroughAllAndGetGraphObjectName(int dataIndex,int objectID,std::string& objName);
	static bool loopThroughAllAndGetObjectsFromGraphCategory(int index,int dataIndex,int& objectID);
};
