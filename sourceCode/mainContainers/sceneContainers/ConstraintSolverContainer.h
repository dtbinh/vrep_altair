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

#include "MainCont.h"
#include "ConstraintSolverObject.h"
#include <vector>

class CConstraintSolverContainer : public CMainCont 
{
public:
	CConstraintSolverContainer();
	virtual ~CConstraintSolverContainer();
	void newSceneProcedure();

	void simulationAboutToStart();
	void simulationEnded();
	void renderYour3DStuff(CViewableBase* renderingObject,int displayAttrib);


	CConstraintSolverObject* getObject(int objectID);
	CConstraintSolverObject* getObject(const char* objectName);
	CConstraintSolverObject* getObjectFromMechanismID(int mechanismID);
	void addObject(CConstraintSolverObject* anObject,bool objectIsACopy);
	void addObjectWithSuffixOffset(CConstraintSolverObject* anObject,bool objectIsACopy,int suffixOffset);
	void getMinAndMaxNameSuffixes(int& minSuffix,int& maxSuffix);
	bool canSuffix1BeSetToSuffix2(int suffix1,int suffix2);
	void setSuffix1ToSuffix2(int suffix1,int suffix2);
	void removeObject(int objectID);
	void removeAllObjects();
	void removeMultipleDefinedObjects();
	void announceObjectWillBeErased(int objID);

	int computeAllMechanisms(bool exceptExplicitHandling);

	// Variable that need to be serialized on an individual basis:
	std::vector<CConstraintSolverObject*> allGcsObjects;
};
