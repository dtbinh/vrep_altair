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

#include "VMenubar.h"
#include <vector>

//FULLY STATIC CLASS
class CFileMenu  
{
public:
	static void addMenu(VMenu* menu);
	static bool evaluateMenuSelection(int commandID);
	static bool loadScene(const char* pathAndFilename,bool displayMessages,bool setCurrentDir);
	static bool loadModel(const char* pathAndFilename,bool displayMessages,bool setCurrentDir,bool noScreenRefresh,std::string* acknowledgmentPointerInReturn,bool doUndoThingInHere);
	static bool saveScene(const char* pathAndFilename,bool displayMessages,bool setCurrentDir);
	static bool saveModel(int modelBaseDummyID,const char* pathAndFilename,bool displayMessages,bool setCurrentDir);

	static bool saveUserInterfaces(const char* pathAndFilename,bool displayMessages,bool setCurrentDir,std::vector<int>* uiHandlesOrNullForAll);
	static bool loadUserInterfaces(const char* pathAndFilename,bool displayMessages,bool setCurrentDir,std::vector<int>* uiHandles,bool doUndoThingInHere);


	static bool apiImportRoutine(int importType,const std::string& pathName,int options,float identicalVerticesTolerance,float sizeFactor,std::vector<std::vector<float>*>& listOfVertices,std::vector<std::vector<int>*>& listOfIndices,std::vector<std::string>& groupNames);
	static int apiAddHeightfieldToScene(int xSize,float pointSpacing,const std::vector<std::vector<float>*>& readData,float shadingAngle,int options);
	static void createNewScene(bool displayMessages,bool forceForNewInstance);
	static void closeScene(bool displayMessages);

private:
	static void _addToRecentlyOpenedScenes(std::string filenameAndPath);
	static void _removeFromRecentlyOpenedScenes(std::string filenameAndPath);
	static bool _saveSceneWithDialogAndEverything();
	static bool _saveSceneAsWithDialogAndEverything();
	static bool commonImportRoutine(int importType,const std::string& pathName,bool showDlg,float& sf);
	static bool pathImportRoutine(const std::string& pathName);
	static bool pathExportPoints(const std::string& pathName,int pathID,bool bezierPoints);
	static bool heightfieldImportRoutine(const std::string& pathName);
	static std::string _getStringOfVersionAndLicenseThatTheFileWasWrittenWith(WORD vrepVer,int licenseType);
};
