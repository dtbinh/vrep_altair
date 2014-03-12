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
#include "StatCollObj.h"
#include "collDistInterface.h"
#include "CollisionRoutine.h"

CStatCollObj::CStatCollObj(CShape* theShapeA,CShape* theShapeB)
{
	shapeA=theShapeA;
	shapeB=theShapeB;
	shapeACTM=shapeA->getCumulativeTransformation().getMatrix();
	shapeBCTM=shapeB->getCumulativeTransformation().getMatrix();
	shapeA->initializeCalculationStructureIfNeeded();
	shapeB->initializeCalculationStructureIfNeeded();
}

CStatCollObj::~CStatCollObj()
{

}

bool CStatCollObj::check(int theCaching[2],bool getIntersections)
{ // Return value true means shapeA and shapeB collided.
	// caching can be NULL.
	intersection.clear();
	intersection.reserve(2048);

	// We first check if the transformation matrices are valid:
	if (!shapeACTM.isValid())
		return(false);
	if (!shapeBCTM.isValid())
		return(false);
	std::vector<float>* intersections=NULL;
	if (getIntersections)
		intersections=&intersection;
	C4X4Matrix collObjMatr[2]={shapeACTM,shapeBCTM};
	const void* collInfos[2]={shapeA->geomData->collInfo,shapeB->geomData->collInfo};

	if ( CCollDistInterface::getMeshMeshCollision(shapeA->geomData->collInfo,shapeB->geomData->collInfo,collObjMatr,collInfos,false,intersections,theCaching))
	{ // There was a collision
		return(true);
	}
	return(false);
}
