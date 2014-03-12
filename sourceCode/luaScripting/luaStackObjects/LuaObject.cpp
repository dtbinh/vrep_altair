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
#include "v_rep_internal.h"
#include "LuaObject.h"
#include "LuaTableObject.h"

CLuaObject::CLuaObject()
{
	objectType=LUA_NIL_OBJECT;
	tableValue=NULL;
}

CLuaObject::CLuaObject(double dVal)
{
	doubleValue=dVal;
	objectType=LUA_NUMBER_OBJECT;
	tableValue=NULL;
}
CLuaObject::CLuaObject(bool bVal)
{
	boolValue=bVal;
	objectType=LUA_BOOLEAN_OBJECT;
	tableValue=NULL;
}
CLuaObject::CLuaObject(const std::string& sVal)
{
	stringValue=sVal;
	objectType=LUA_STRING_OBJECT;
	tableValue=NULL;
}
CLuaObject::CLuaObject(CLuaTableObject* tVal)
{
	tableValue=tVal;
	objectType=LUA_TABLE_OBJECT;
}

CLuaObject::~CLuaObject()
{
	removeTable();
}

int CLuaObject::getObjectType()
{
	return(objectType);
}

bool CLuaObject::isNumber()
{
	return(objectType==LUA_NUMBER_OBJECT);
}

bool CLuaObject::isString()
{
	return(objectType==LUA_STRING_OBJECT);
}

void CLuaObject::removeTable()
{
	delete tableValue;
	tableValue=NULL;
	objectType=LUA_NIL_OBJECT;
}

void CLuaObject::pushObjectOnStack(lua_State* L)
{
	if (objectType==LUA_NUMBER_OBJECT)
		lua_pushnumber(L,doubleValue);
	if (objectType==LUA_STRING_OBJECT)
		lua_pushlstring(L,stringValue.c_str(),stringValue.length()); // from lua_pushstring to lua_pushlstring on 2011/01/23
	if (objectType==LUA_BOOLEAN_OBJECT)
		lua_pushboolean(L,boolValue);
	if (objectType==LUA_NIL_OBJECT)
		lua_pushnil(L);
	if (objectType==LUA_TABLE_OBJECT)
		tableValue->pushObjectOnStack(L);
}

CLuaObject* CLuaObject::copyYourself()
{
	CLuaObject* it=new CLuaObject();
	it->doubleValue=doubleValue;
	it->boolValue=boolValue;
	it->stringValue=stringValue;
	if (tableValue!=NULL)
		it->tableValue=tableValue->copyYourself();
	it->objectType=objectType;
	return(it);
}
