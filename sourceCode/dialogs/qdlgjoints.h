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

#ifndef QDLGJOINTS_H
#define QDLGJOINTS_H

#include "DlgEx.h"

namespace Ui {
    class CQDlgJoints;
}

class CQDlgJoints : public CDlgEx
{
    Q_OBJECT

public:
    explicit CQDlgJoints(QWidget *parent = 0);
    ~CQDlgJoints();

	void refresh();

	void cancelEvent();

	bool inMainRefreshRoutine;

	static bool showDynamicWindow;

private slots:
	void on_qqMotionHandlingEnabled_clicked();

	void on_qqCyclic_clicked();

	void on_qqPitch_editingFinished();

	void on_qqMinimum_editingFinished();

	void on_qqRange_editingFinished();

	void on_qqPosition_editingFinished();

	void on_qqAlpha_editingFinished();

	void on_qqBeta_editingFinished();

	void on_qqGamma_editingFinished();

	void on_qqIkWeight_editingFinished();

	void on_qqMaxStepSize_editingFinished();

	void on_qqApplyConfig_clicked();

	void on_qqJointModeCombo_currentIndexChanged(int index);

	void on_qqHybrid_clicked();

	void on_qqApplyMode_clicked();

	void on_qqAdjustDependency_clicked();

	void on_qqAdjustMotion_clicked();

	void on_qqAdjustDynamicParameters_clicked();

	void on_qqLength_editingFinished();

	void on_qqDiameter_editingFinished();

	void on_qqAdjustColorA_clicked();

	void on_qqAdjustColorB_clicked();

	void on_qqApplyAppearance_clicked();

private:
    Ui::CQDlgJoints *ui;
};

#endif // QDLGJOINTS_H
