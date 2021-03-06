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

#include "Ser.h"
#include "3DObject.h"
#include "3Vector.h"
#include "7Vector.h"
#include <vector>
#include <string>

class CDummy : public C3DObject  
{
public:

	CDummy();
	virtual ~CDummy();

	// Following functions are inherited from 3DObject
	void display(CViewableBase* renderingObject,int displayAttrib);
	C3DObject* copyYourself();
	void scaleObject(float scalingFactor);
	void serialize(CSer& ar);
	void serializeWExtIk(CExtIkSer& ar);
	static void serializeWExtIkStatic(CExtIkSer& ar);
	void announceGroupWillBeErased(int groupID,bool copyBuffer);
	void announceCollisionWillBeErased(int collisionID,bool copyBuffer);
	void announceDistanceWillBeErased(int distanceID,bool copyBuffer);
	void announceGcsObjectWillBeErased(int gcsObjectID,bool copyBuffer);
	void performIkLoadingMapping(std::vector<int>* map);
	void performGroupLoadingMapping(std::vector<int>* map);
	void performCollisionLoadingMapping(std::vector<int>* map);
	void performDistanceLoadingMapping(std::vector<int>* map);
	void performGcsLoadingMapping(std::vector<int>* map);
	void performTextureObjectLoadingMapping(std::vector<int>* map);
	void performDynMaterialObjectLoadingMapping(std::vector<int>* map);
	void bufferMainDisplayStateVariables();
	void bufferedMainDisplayStateVariablesToDisplay();
	void simulationAboutToStart();
	void simulationEnded();
	void initializeInitialValues(bool simulationIsRunning);
	bool getFullBoundingBox(C3Vector& minV,C3Vector& maxV);
	bool getMarkingBoundingBox(C3Vector& minV,C3Vector& maxV);
	bool getExportableMeshAtIndex(int index,std::vector<float>& vertices,std::vector<int>& indices);
	std::string getObjectTypeInfo();
	std::string getObjectTypeInfoExtended();

	// SPECIAL FUNCTION TO GUARANTEE FORWARD COMPATIBILITY WHEN LOADING OBJECT TYPES THAT DON'T EXIST YET!
	void loadUnknownObjectType(CSer& ar);

	// Various functions
	void setSize(float theNewSize);
	float getSize();

	void setAssignedToParentPath(bool assigned);
	bool getAssignedToParentPath();
	void setAssignedToParentPathOrientation(bool assigned);
	bool getAssignedToParentPathOrientation();
	void setFreeOnPathTrajectory(bool isFree);
	bool getFreeOnPathTrajectory();
	void setVirtualDistanceOffsetOnPath(float off);
	float getVirtualDistanceOffsetOnPath();

	void setVirtualDistanceOffsetOnPath_variationWhenCopy(float off);
	float getVirtualDistanceOffsetOnPath_variationWhenCopy();

	// Variables which need to be copied and serialized:
	CVisualParam color;

protected:
	// Variables which need to be serialized & copied 
	float size;

	bool _assignedToParentPath;
	bool _assignedToParentPathOrientation;
	bool _freeOnPathTrajectory;
	float _virtualDistanceOffsetOnPath;
	float _virtualDistanceOffsetOnPath_variationWhenCopy;


public:
	bool announceObjectWillBeErased(int objID,bool copyBuffer);
	void announceIkObjectWillBeErased(int ikGroupID,bool copyBuffer);

	void performObjectLoadingMapping(std::vector<int>* map);

	void setLinkedDummyID(int id,bool setDirectly);
	void setLinkType(int lt,bool setDirectly);
	int getLinkedDummyID();
	int getLinkType();

	C7Vector getTempLocalTransformation();
	void setTempLocalTransformation(const C7Vector& tr);

protected:
	C7Vector _localTransformation_temp; // used for IK (needed when the dummy is freely sliding on a path object!)

	// Variables which need to be serialized & copied 
	int _linkedDummyID;
	int _linkType;

};
