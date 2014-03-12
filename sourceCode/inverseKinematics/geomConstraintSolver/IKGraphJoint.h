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

#include "IKGraphNode.h"
#include "IKGraphObject.h"

class CIKGraphJoint : public CIKGraphNode
{
public:
	CIKGraphJoint(bool isRevolute,float theParameter,float theMinVal,float theRange,float theScrewPitch,bool isCyclic,float theWeight);
	CIKGraphJoint(C4Vector& theSphericalTr,float theRange,float theWeight);
	virtual ~CIKGraphJoint();

	C7Vector getDownToTopTransformation();
	CIKGraphObject* getTopIKGraphObject();
	CIKGraphObject* getDownIKGraphObject();
	void constrainJointToOtherJoint(CIKGraphJoint* it,float constantVal,float coefficient);
	CIKGraphObject* topObject;
	CIKGraphObject* downObject;
	int jointType;// IK_GRAPH_REVOLUTE_JOINT_TYPE,IK_GRAPH_PRISMATIC_JOINT_TYPE,IK_GRAPH_SPHERICAL_JOINT_TYPE,IK_GRAPH_SCREW_JOINT_TYPE
	float parameter;
	float screwPitch;
	C4Vector sphericalTransformation;
	float minValue;
	float range;
	bool cyclic;
	float weight;
	bool disabled;

	float constantValue;
	float coefficientValue;
	CIKGraphJoint* followedJoint;

	CIKGraphNode* getUnexplored(int pos);
	CIKGraphNode* getNeighbour(int pos,bool noLinkNeighbour);
	CIKGraphNode* getExploredWithSmallestExplorationID();
	CIKGraphNode* getNeighbourWithExplorationID(int theID);
	int getNumberOfUnexplored();
	int getConnectionNumber();
};
