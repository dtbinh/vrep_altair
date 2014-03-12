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

extern "C" {
    #include "lua.h"
    #include "lualib.h"
}

class CLuaTableObject; // Forward declaration

enum {LUA_TABLE_OBJECT=0,LUA_STRING_OBJECT,LUA_NUMBER_OBJECT,LUA_BOOLEAN_OBJECT,LUA_NIL_OBJECT};

class CLuaObject  
{
public:
	CLuaObject();
	CLuaObject(double dVal);
	CLuaObject(bool bVal);
	CLuaObject(const std::string& sVal);
	CLuaObject(CLuaTableObject* tVal);
	virtual ~CLuaObject();

	bool isNumber();
	bool isString();
	int getObjectType();
	void removeTable();
	void pushObjectOnStack(lua_State* L);
	CLuaObject* copyYourself();

	double doubleValue;
	bool boolValue;
	std::string stringValue;
	CLuaTableObject* tableValue;
protected:
	int objectType;
};
