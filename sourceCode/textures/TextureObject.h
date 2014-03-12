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

#include "Ser.h"
#include <vector>

class CTextureObject
{
public:
	CTextureObject(); // for serialization
	CTextureObject(int sizeX,int sizeY);
	virtual ~CTextureObject();

	void setObjectID(int newID);
	int getObjectID();
	bool isSame(CTextureObject* obj);
	void setObjectName(const char* newName);
	std::string getObjectName();
	void getTextureSize(int& sizeX,int& sizeY);
	void setImage(bool rgba,bool horizFlip,bool vertFlip,unsigned char* data);
	CTextureObject* copyYourself();
	void serialize(CSer& ar);
	void setTextureBuffer(const std::vector<unsigned char>& tb);
	void getTextureBuffer(std::vector<unsigned char>& tb);
	void lightenUp();

	void startTextureDisplay(bool interpolateColor,bool decal,bool repeatX,bool repeatY);
	void endTextureDisplay();

	bool announceGeneralObjectWillBeErased(int objectID,int subObjectID);
	void addDependentObject(int objectID,int subObjectID);
	void clearAllDependencies();
	void transferDependenciesToThere(CTextureObject* receivingObject);
	
protected:
	void _generateTextureName();
	void _deleteGlTexture();

	std::vector<unsigned char> _textureBuffer;
	unsigned int _oglTextureName;
	int _objectID;
	std::string _objectName;
	int _textureSize[2];
	bool _providedImageWasRGBA;		// just needed to reduce serialization size!
	bool _changedFlag;

	std::vector<int> _dependentObjects;
	std::vector<int> _dependentSubObjects;
};
