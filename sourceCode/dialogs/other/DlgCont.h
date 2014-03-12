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

#include "ToolDlgWrapper.h"
#include "DlgEx.h"
#include "VMenubar.h"
#include <vector>

class CDlgCont  
{
public:
	CDlgCont(QWidget* pWindow);
	virtual ~CDlgCont();

	void initialize(QWidget* pWindow);
	void setRefreshDegree(int d);
	void refresh();
	void destroyWhatNeedsDestruction();
	void visibleInstanceAboutToSwitch();

	bool openOrBringToFront(int dlgID);
	void close(int dlgID);
	bool toggle(int dlgID);

	void showDialogsButDontOpenThem();
	void hideDialogsButDontCloseThem();


	CToolDlgWrapper* _getDialogWrapper(int dlgID);
	VDialog* getDialog(int dlgID);
	bool isVisible(int dlgID);
	void killAllDialogs(); // Need initialization again after that
	void getWindowPos(int dlgID,int pos[2],bool& visible);
	void setWindowPos(int dlgID,int pos[2],bool visible);

	void addMenu(VMenu* menu);
	bool evaluateMenuSelection(int commandID);
	std::vector<CToolDlgWrapper*> dialogs;

	bool _destroyingContainerNow;
private:
	QWidget* parentWindow;
};
