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
#include "IKObject.h"
#include "IKJoint.h"
#include "IKDummy.h"
#include "GCSDefs.h"

CIKObject::CIKObject()
{
	parent=NULL;
	data=-1;
}

CIKObject::~CIKObject()
{

}

C7Vector CIKObject::getLocalTransformation(bool useTempVals)
{
	if (objectType==IK_JOINT_TYPE)
	{
		C7Vector jointTr;
		jointTr.setIdentity();
		float param=((CIKJoint*)this)->parameter;
		if (useTempVals)
			param=((CIKJoint*)this)->tempParameter;
		if (((CIKJoint*)this)->revolute)
			jointTr.Q.setAngleAndAxis(param,C3Vector(0.0f,0.0f,1.0f));
		else
			jointTr.X(2)=param;
		return(transformation*jointTr);
	}
	else
		return(transformation);
}
C7Vector CIKObject::getLocalTransformationPart1(bool useTempVals)
{
	return(transformation);
}
C7Vector CIKObject::getCumulativeTransformation(bool useTempVals)
{
	if (objectType==IK_JOINT_TYPE)
	{
		C7Vector jointTr;
		jointTr.setIdentity();
		float param=((CIKJoint*)this)->parameter;
		if (useTempVals)
			param=((CIKJoint*)this)->tempParameter;
		if (((CIKJoint*)this)->revolute)
			jointTr.Q.setAngleAndAxis(param,C3Vector(0.0f,0.0f,1.0f));
		else
			jointTr.X(2)=param;
		return(getParentCumulativeTransformation(useTempVals)*transformation*jointTr);
	}
	else
		return(getParentCumulativeTransformation(useTempVals)*transformation);
}
C7Vector CIKObject::getCumulativeTransformationPart1(bool useTempVals)
{
	return(getParentCumulativeTransformation(useTempVals)*transformation);	
}
C7Vector CIKObject::getParentCumulativeTransformation(bool useTempVals)
{
	if (parent==NULL)
	{
		C7Vector tr;
		tr.setIdentity();
		return(tr);
	}
	else
		return(parent->getCumulativeTransformation(useTempVals));
}
