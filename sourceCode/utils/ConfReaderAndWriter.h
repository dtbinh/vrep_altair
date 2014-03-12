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

#include <vector>

class CConfReaderAndWriter  
{
public:
	CConfReaderAndWriter();
	virtual ~CConfReaderAndWriter();

	bool readConfiguration(const char* filename);
	bool writeConfiguration(const char* filename);

	bool getString(const char* variableName,std::string& variable);
	bool getInteger(const char* variableName,int& variable);
	bool getFloat(const char* variableName,float& variable);
	bool getVector(const char* variableName,float variable[3]);
	bool getBoolean(const char* variableName,bool& variable);

	bool addString(const char* variableName,std::string variable,const char* comment="");
	bool addInteger(const char* variableName,int variable,const char* comment="");
	bool addFloat(const char* variableName,float variable,const char* comment="");
	bool addVector(const char* variableName,float variable[3],const char* comment="");
	bool addBoolean(const char* variableName,bool variable,const char* comment="");
	bool addRandomLine(const char* lineText);

private:
	int _getVariableIndex(const char* variableName);
	std::vector<std::string> _variables;
	std::vector<std::string> _values;
	std::vector<std::string> _comments;
};
