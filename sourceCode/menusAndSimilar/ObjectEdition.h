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
#include "3DObject.h"
#include "VMenubar.h"

//FULLY STATIC CLASS
class CObjectEdition  
{
public:
	static void copyObjects(std::vector<int>* selection);
	static void pasteCopyBuffer();
	static void cutObjects(std::vector<int>* selection);
	static void deleteObjects(std::vector<int>* selection);
	static void addMenu(VMenu* menu);
	static bool evaluateMenuSelection(int commandID);
	static void scaleObjects(const std::vector<int>& selection,float scalingFactor,bool scalePositionsToo);

	static void addRootObjectChildrenToSelection(std::vector<int>& selection);
	static int groupSelection(std::vector<int>* selection,bool showWarningMessages);
	static void ungroupSelection(std::vector<int>* selection);
	static bool mergeSelection(std::vector<int>* selection,bool showWarningMessages);
	static void divideSelection(std::vector<int>* selection);
	static void mergePathSelection(std::vector<int>* selection);
	static int generateConvexDecomposed(int shapeHandle,size_t nClusters,double maxConcavity,bool addExtraDistPoints,bool addFacesPoints,double maxConnectDist,size_t maxTrianglesInDecimatedMesh,size_t maxHullVertices,double smallClusterThreshold,bool individuallyConsiderMultishapeComponents,bool randomColors,int maxIterations);
};
