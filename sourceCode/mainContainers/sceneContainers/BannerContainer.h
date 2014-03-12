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
#include "BannerObject.h"
#include "MainCont.h"
#include "7Vector.h"
#include "4X4Matrix.h"

class CBannerContainer : public CMainCont
{
public:
	CBannerContainer();
	virtual ~CBannerContainer();

	void newSceneProcedure();
	void simulationAboutToStart();
	void simulationEnded();
	void renderYour3DStuff_nonTransparent(CViewableBase* renderingObject,int displayAttrib,int windowSize[2],float verticalViewSizeOrAngle,bool perspective);
	void renderYour3DStuff_transparent(CViewableBase* renderingObject,int displayAttrib,int windowSize[2],float verticalViewSizeOrAngle,bool perspective);
	void renderYour3DStuff_overlay(CViewableBase* renderingObject,int displayAttrib,int windowSize[2],float verticalViewSizeOrAngle,bool perspective);
	int addObject(CBannerObject* it);
	CBannerObject* getObject(int objectID);
	void removeAllObjects(bool onlyThoseCreatedFromScripts);
	void announceObjectWillBeErased(int objID);
	void removeObject(int objectID);
	void adjustForFrameChange(int objectID,const C7Vector& preCorrection);
	void adjustForScaling(int objectID,float xScale,float yScale,float zScale);
	void drawAll3DStuff(bool overlay,bool transparentObject,int displayAttrib,const C4X4Matrix& cameraCTM,int windowSize[2],float verticalViewSizeOrAngle,bool perspective);
	void renderAll2DBanners();
	bool mouseDownOn2DWindow(int mouseX,int mouseY);

private:
	std::vector<CBannerObject*> _allObjects;
};
