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
#include "LuaTableObject.h"

CLuaTableObject::CLuaTableObject()
{

}
CLuaTableObject::CLuaTableObject(CLuaObject* tVal)
{
	addElement(tVal);
}
CLuaTableObject::CLuaTableObject(CLuaObject* tVal1,CLuaObject* tVal2)
{
	addElement(tVal1);
	addElement(tVal2);
}
CLuaTableObject::CLuaTableObject(CLuaObject* tVal1,CLuaObject* tVal2,CLuaObject* tVal3)
{
	addElement(tVal1);
	addElement(tVal2);
	addElement(tVal3);
}

CLuaTableObject::~CLuaTableObject()
{
	clearTable();
}
void CLuaTableObject::clearTable()
{
	for (int i=0;i<int(tableValues.size());i++)
		delete tableValues[i];
	tableValues.clear();
}
void CLuaTableObject::addElement(CLuaObject* tVal)
{
	tableValues.push_back(tVal);
}
CLuaObject* CLuaTableObject::getElement(int index)
{
	if ( (index<0)||(index>=int(tableValues.size())) )
		return(NULL);
	return(tableValues[index]);
}
int CLuaTableObject::getTableSize()
{
	return(tableValues.size());
}

bool CLuaTableObject::areAllElementsNumbers(int range)
{ // range is -1 by default
	int top=tableValues.size();
	if ( (range>0)&&(range<=int(tableValues.size())) )
		top=range;
	for (int i=0;i<top;i++)
	{
		if (!tableValues[i]->isNumber())
			return(false);
	}
	return(true);
}
bool CLuaTableObject::areAllElementsTablesWithNumbers()
{
	for (int i=0;i<int(tableValues.size());i++)
	{
		if (tableValues[i]->getObjectType()!=LUA_TABLE_OBJECT)
			return(false);
		if (!tableValues[i]->tableValue->areAllElementsNumbers())
			return(false);
	}
	return(true);
}
void CLuaTableObject::pushObjectOnStack(lua_State* L)
{
	lua_newtable(L);						
	int tablePos=lua_gettop(L);
	for (int i=0;i<int(tableValues.size());i++)
	{
		tableValues[i]->pushObjectOnStack(L);
		lua_rawseti(L,tablePos,i+1);
	}
}

CLuaTableObject* CLuaTableObject::copyYourself()
{
	CLuaTableObject* it=new CLuaTableObject();
	for (int i=0;i<int(tableValues.size());i++)
		it->addElement(tableValues[i]->copyYourself());
	return(it);
}
