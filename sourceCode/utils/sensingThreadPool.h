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

#include "VMutex.h"
#include "VThread.h"
#include <vector>

struct SParallelWorkDat
{
	void* object;
	int objectType; // 0=coll, 1=dist, 2=prox sensor 
	bool exceptExplicit;
	bool handlingStarted;
	bool freeSlot;
};

// FULLY STATIC CLASS
class CSensingThreadPool  
{
public:
	static void launchThreads(int desiredThreadCount);
	static void killThreads();
	static void addTask(const SParallelWorkDat& task);
	static void waitUntilAllThreadsIdleAndTasksDone();
	static std::vector<SParallelWorkDat>* getTasks();
	static void clearAllTasks();
	static int getThreadCount();

	static void setProtectedAccess(bool p);
private:
	static VTHREAD_RETURN_TYPE _parallelWorkEntry(VTHREAD_ARGUMENT_TYPE lpData);

	static std::vector<SParallelWorkDat> _tasks;
	static volatile int _threadDeinitCnt;
	static volatile int _threadIdleCnt;
	static volatile bool _simulationEndedFlag;
	static volatile int _taskAddID;
	static VMutex _mutex;
	static int _threadCount;
	static int _nextThreadIndex;
	static VMutex _protectedAccessMutex;
};
