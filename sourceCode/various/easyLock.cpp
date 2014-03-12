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

#include "easyLock.h"
#include "VThread.h"
#include "IloIlo.h"
#include "debugLogFile.h"

bool CEasyLock::_showActivity=false;

CEasyLock::CEasyLock(VMutex& mutex,const char* functionName)
{
	_wasAlreadyUnlocked=false;
	_mutex=&mutex;
	_functionName=functionName;
	_lock();
}

CEasyLock::~CEasyLock()
{
	if (!_wasAlreadyUnlocked)
		_unlock();
}

void CEasyLock::unlock()
{
	if (!_wasAlreadyUnlocked)
		_unlock();
	_wasAlreadyUnlocked=true;
}

void CEasyLock::lock()
{
	if (_wasAlreadyUnlocked)
		_lock();
	_wasAlreadyUnlocked=false;
}

void CEasyLock::_unlock()
{
	if (_showActivity)
	{
		std::string arrow("... ");
		if (VThread::isUiThreadIdSet())
		{
			if (VThread::isCurrentThreadTheUiThread())
				arrow+="(GUI) (";
			else
				arrow+="(SIM) (";
		}
		else
			arrow+="(GUI) (";
		CDebugLogFile::addDebugText(false,arrow.c_str(),_functionName.c_str(),") 'easy locking'\n");
	}

	_mutex->unlock();

	if (_showActivity)
	{
		std::string arrow("... ");
		if (VThread::isUiThreadIdSet())
		{
			if (VThread::isCurrentThreadTheUiThread())
				arrow+="(GUI) (";
			else
				arrow+="(SIM) (";
		}
		else
			arrow+="(GUI) (";
		CDebugLogFile::addDebugText(false,arrow.c_str(),_functionName.c_str(),") 'easy locked'\n");
	}
}

void CEasyLock::_lock()
{
	if (_showActivity)
	{
		std::string arrow("... ");
		if (VThread::isUiThreadIdSet())
		{
			if (VThread::isCurrentThreadTheUiThread())
				arrow+="(GUI) (";
			else
				arrow+="(SIM) (";
		}
		else
			arrow+="(GUI) (";
		CDebugLogFile::addDebugText(false,arrow.c_str(),_functionName.c_str(),") 'easy unlocking'\n");
	}

	_mutex->lock();

	if (_showActivity)
	{
		std::string arrow("... ");
		if (VThread::isUiThreadIdSet())
		{
			if (VThread::isCurrentThreadTheUiThread())
				arrow+="(GUI) (";
			else
				arrow+="(SIM) (";
		}
		else
			arrow+="(GUI) (";
		CDebugLogFile::addDebugText(false,arrow.c_str(),_functionName.c_str(),") 'easy unlocked'\n");
	}
}

void CEasyLock::setShowActivity(bool show)
{
	_showActivity=show;
}

bool CEasyLock::getShowActivity()
{
	return(_showActivity);
}
