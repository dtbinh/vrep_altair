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

#include <string>
#include <vector>
#include "Ser.h"

class CConstraintSolverObject
{
public:
	CConstraintSolverObject();
	virtual ~CConstraintSolverObject();

	void initializeInitialValues(bool simulationIsRunning);
	void simulationAboutToStart();
	void simulationEnded();

	void setObjectID(int newID);
	int getObjectID();
	void setObjectName(const char* newName);
	std::string getObjectName();


	void performObjectLoadingMapping(std::vector<int>* map);
	bool announceObjectWillBeErased(int objID,bool copyBuffer);

	CConstraintSolverObject* copyYourself();
	void serialize(CSer& ar);

	void setMaximumIterations(int maxIt);
	int getMaximumIterations();
	void setInterpolation(float interpol);
	float getInterpolation();
	void setGeneralDamping(float damping);
	float getGeneralDamping();
	void setMaxAngleVariation(float maxVar);
	float getMaxAngleVariation();
	void setMaxLinearVariation(float maxVar);
	float getMaxLinearVariation();
	void setLoopClosurePositionTolerance(float tol);
	float getLoopClosurePositionTolerance();
	void setLoopClosureOrientationTolerance(float tol);
	float getLoopClosureOrientationTolerance();
	void setBase3DObject(int objID);
	int getBase3DObject();
	void setExplicitHandling(bool explHandl);
	bool getExplicitHandling();
	void selectAllObjectsInMechanism();
	float getCalculationTime();

	bool computeGcs();

private:
	int _objectID;
	std::string _objectName;
	int _base3DObject;
	bool _explicitHandling;
	int _maxIterations;
	float _interpolation;
	float _generalDamping;
	float _maxAngleVariation;
	float _maxLinearVariation;
	float _loopClosurePositionTolerance;
	float _loopClosureOrientationTolerance;
	int _calcTimeInMs;

	bool _initialValuesInitialized;
	bool _initialExplicitHandling;
};
