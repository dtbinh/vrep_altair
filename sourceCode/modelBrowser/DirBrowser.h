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
#include "DirBrowserElement.h"
#include "VMenubar.h"

class CDirBrowser  
{
public:
	CDirBrowser();
	virtual ~CDirBrowser();

	void newSceneProcedure();
	void setRenderingSizeAndPosition(int xSize,int ySize,int xPos,int yPos);
	bool render();
	void removeAll();
	void setUpDefaultValues();
	void rebuildHierarchy();
	bool leftMouseDown(int x,int y,int selectionStatus);
	void leftMouseUp(int x,int y);
	bool rightMouseDown(int x,int y);
	void rightMouseUp(int x,int y,int absX,int absY,QWidget* mainWindow);
	void mouseMove(int x,int y,bool passiveAndFocused);
	bool mouseWheel(int deltaZ,int x,int y);
	bool leftMouseDblClick(int x,int y,int selectionStatus);
	void validateViewPosition();
	void setRefreshViewFlag();
	void addMenu(VMenu* menu);
	bool evaluateMenuSelection(int commandID);
	void looseFocus();
	void keyPress(int key);
	int getSliderPositions(int vSliderTopLeft[2],int vSliderBottomRight[2],int hSliderTopLeft[2],int hSliderBottomRight[2],float prop[2]);

	std::string getEditedLabel();
	void setEditionLabel(std::string txt);
	int getInflateActionObjectID(int mousePositionX,int mousePositionY);
	int getScriptActionObjectID(int mousePositionX,int mousePositionY);
	int getScriptParameterActionObjectID(int mousePositionX,int mousePositionY);
	int getTextActionObjectID(int mousePositionX,int mousePositionY);
	int getSimulationActionObjectID(int mousePositionX,int mousePositionY);

	int getActionObjectID(int mousePositionY,int tolerance);
	int getActionObjectID_icon(int mousePositionX,int mousePositionY);
	void getActionObjectIDs(int mouseDownPositionY,int mouseUpPositionY,int tolerance,std::vector<int>* toBeSelected);
	void drawEditionLabel(int textCenterOffset,int verticalShift,int textPosX,int textPosY);

	int getCaughtElements();
	void clearCaughtElements(int keepMask);

	std::vector<int> inflateIconPosition;
	std::vector<int> objectPosition;

private:
	int _caughtElements;
	int renderingSize[2];
	int renderingPosition[2];
	int mouseDownRelativePosition[2];
	int mouseRelativePosition[2];
	int previousMouseRelativePosition[2];
	int viewPosition[2];
	bool shiftingAllowed;
	int minRenderedPosition[2];
	int maxRenderedPosition[2];
	int refreshViewFlag;
	bool resetViewFlag;
	int verticalScrollbarWidth;
	int horizontalScrollbarHeight;
	int sliderMoveMode;
	int viewPosWhenMouseOnSliderDown[2];
};
