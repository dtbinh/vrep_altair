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

// Those routines should be replaced with the Reflexxes RML libraries!!!!

#pragma once

class CLinMotionRoutines
{
public:
	CLinMotionRoutines();
	virtual ~CLinMotionRoutines();

	static double getTimeToVelocity(double speed,double accel,double nextSpeed);

	static double getTimeToVelocity_lvp(double currentVelocity,double accel,double targetVelocity);
	static double getDistanceToDeceleration(double currentVelocity,double absAccel,double targetVelocity,double distanceToLimit);

	static bool getNextValues(double& position,double& velocity,
		double targetVelocity,double accelAbs,
		double lowerLimitPosition,double upperLimitPosition,
		double lowerMaxAbsVel,double upperMaxAbsVel,
		double& deltaTime);
	static double getMaxVelocityAtPosition(double position,double accelAbs,double lowerLimitPosition,double upperLimitPosition,double lowerMaxAbsVel,double upperMaxAbsVel);

	static double getDistanceForTimeStep_lvp(double currentVelocity,double accel,double deltaTime);
	static double getTimeToPosition_negOk(double pos,double speed,double accel,double nextPos);
	static double getNextVelocityForTimeStep_lvp(double currentVelocity,double accel,double deltaTime);

	static bool getNextValuesForPath(double& position,
		double& nominalVelocity,double targetNominalVelocity,double acceleration,
		double lowerLimitPosition,double upperLimitPosition,
		double lowerMaxRelVel,double upperMaxRelVel,
		double& deltaTime);

	static bool getNextValuesForPath(double& position,
		double nominalVelocity,
		double lowerLimitPosition,double upperLimitPosition,
		double lowerMaxRelVel,double upperMaxRelVel,
		double& deltaTime);
	static void adjustNominalVelocity(double& nominalVelocity,double targetNominalVelocity,double acceleration,double deltaTime);


	static double getCurrentVelocityOnPath(double position,double nominalVelocity,double lowerLimitPosition,double upperLimitPosition,
		double lowerMaxRelVel,double upperMaxRelVel);

};
