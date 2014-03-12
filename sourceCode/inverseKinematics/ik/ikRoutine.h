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


#include "MyMath.h"
#include "jointObject.h"
#include "Dummy.h"
#include "ikEl.h"
#include "ikGroup.h"

// FULLY STATIC CLASS
class CIkRoutine  
{
public:
	static void multiply(C4X4FullMatrix& d0,C4X4FullMatrix& dp,int index,
						std::vector<C4X4FullMatrix*>& allMatrices);
	static void buildDeltaZRotation(C4X4FullMatrix& d0,C4X4FullMatrix& dp,float screwCoeff);
	static void buildDeltaZTranslation(C4X4FullMatrix& d0,C4X4FullMatrix& dp);
	static CMatrix* getJacobian(CikEl* ikElement,C4X4Matrix& tooltipTransf,std::vector<int>* rowJointIDs=NULL,std::vector<int>* rowJointStages=NULL);
	static void performGroupIK(CikGroup* ikGroup);

	static CMatrix* getAvoidanceJacobian(C3DObject* base,C3DObject* avoidingObject,const C4X4Matrix& relPos,std::vector<int>* rowJointIDs=NULL,std::vector<int>* rowJointStages=NULL);
};
