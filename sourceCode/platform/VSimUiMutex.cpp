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
#include "VSimUiMutex.h"

VSimUiMutex::VSimUiMutex()
{
	_lockLevel=0;
}

VSimUiMutex::~VSimUiMutex()
{
}

void VSimUiMutex::lock(int threadType)
{
	tryLock(threadType,-1); // negative time out --> no time out!
}

bool VSimUiMutex::tryLock(int threadType,int timeOut/*=0*/)
{ // if timeOut is negative, there is no time out!
	bool retVal=false;

	_cs_aux.lock();

	bool doTheRealLock=false;
	if (_lockLevel==0)
	{ // not locked
		doTheRealLock=true;
	}
	else
	{
		if (threadType==_threadType)
		{ // already locked by self
			_lockLevel++;
			retVal=true;
		}
		else
		{ // already locked by other
			doTheRealLock=true;
		}
	}

	if (doTheRealLock)
	{
		_cs_aux.unlock();
		retVal=_cs.tryLock(timeOut);
		_cs_aux.lock();
		if (retVal)
		{
			_lockLevel=1;
			_threadType=threadType;
		}
	}

	_cs_aux.unlock();

	return(retVal);
}

void VSimUiMutex::unlock()
{
	_cs_aux.lock();
	_lockLevel--;
	if (_lockLevel==0)
		_cs.unlock();
	_cs_aux.unlock();
}

