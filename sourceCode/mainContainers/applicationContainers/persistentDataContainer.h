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
#include "VArchive.h"

#define FILENAME_OF_USER_SETTINGS_IN_BINARY_FILE "settings.dat"
class CPersistentDataContainer 
{
public:
	CPersistentDataContainer();
	CPersistentDataContainer(const std::string& filename);
	virtual ~CPersistentDataContainer();

	int removeAllData();

	void initializeWithDataFromFile();

	void writeData(const char* dataName,const std::string& value,bool toFile);
	bool readData(const char* dataName,std::string& value);

protected:
	void _writeData(const char* dataName,const std::string& value);
	int _getDataIndex(const char* dataName);

	void _readFromFile(std::vector<std::string>& dataNames,std::vector<std::string>& dataValues);
	void _writeToFile(std::vector<std::string>& dataNames,std::vector<std::string>& dataValues);
	void _serialize(VArchive& ar,std::vector<std::string>& dataNames,std::vector<std::string>& dataValues);

	std::string _filename;
	std::vector<std::string> _dataNames;
	std::vector<std::string> _dataValues;
};
