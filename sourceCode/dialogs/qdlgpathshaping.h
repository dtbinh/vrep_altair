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

#ifndef QDLGPATHSHAPING_H
#define QDLGPATHSHAPING_H

#include "DlgEx.h"
#include "Path.h"

namespace Ui {
    class CQDlgPathShaping;
}

class CQDlgPathShaping : public CDlgEx
{
    Q_OBJECT

public:
    explicit CQDlgPathShaping(QWidget *parent = 0);
    ~CQDlgPathShaping();

	void refresh();
	void cancelEvent();

	bool inMainRefreshRoutine;

	CPath* getPath();
	bool _extractOneFloat(std::string& txt,float& val);

	static bool showWindow;

private slots:
	void on_qqEnabled_clicked();

	void on_qqFollowOrientation_clicked();

	void on_qqConvexHull_clicked();

	void on_qqAdjustColor_clicked();

	void on_qqGenerateShape_clicked();

	void on_qqMaxLength_editingFinished();

	void on_qqTypeCombo_currentIndexChanged(int index);

	void on_qqCyclic_clicked();

	void on_qqScalingFactor_editingFinished();

	void on_qqCoordinates_textChanged();

private:
    Ui::CQDlgPathShaping *ui;
};

#endif // QDLGPATHSHAPING_H
