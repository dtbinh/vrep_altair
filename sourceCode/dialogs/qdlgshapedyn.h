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

#ifndef QDLGSHAPEDYN_H
#define QDLGSHAPEDYN_H

#include "DlgEx.h"

namespace Ui {
    class CQDlgShapeDyn;
}

class CQDlgShapeDyn : public CDlgEx
{
    Q_OBJECT

public:
    explicit CQDlgShapeDyn(QWidget *parent = 0);
    ~CQDlgShapeDyn();

	void refresh();
	void cancelEvent();

	static bool showDynamicWindow;
	static bool inertiaFrameRelativeToParent;
	bool inMainRefreshRoutine;

private slots:
	void on_qqStatic_clicked();

	void on_qqSleepModeStart_clicked();

	void on_qqParentFollows_clicked();

	void on_qqAdjustEngineProperties_clicked();

	void on_qqRespondable_clicked();

	void on_a_1_clicked();
	void on_a_2_clicked();
	void on_a_3_clicked();
	void on_a_4_clicked();
	void on_a_5_clicked();
	void on_a_6_clicked();
	void on_a_7_clicked();
	void on_a_8_clicked();
	void on_a_9_clicked();
	void on_a_10_clicked();
	void on_a_11_clicked();
	void on_a_12_clicked();
	void on_a_13_clicked();
	void on_a_14_clicked();
	void on_a_15_clicked();
	void on_a_16_clicked();

	void on_qqMass_editingFinished();

	void on_qqMassT2_clicked();

	void on_qqMassD2_clicked();

	void on_qqIX_editingFinished();

	void on_qqIY_editingFinished();

	void on_qqIZ_editingFinished();

	void on_qqIT2_clicked();

	void on_qqID2_clicked();

	void on_qqPX_editingFinished();

	void on_qqPY_editingFinished();

	void on_qqPZ_editingFinished();

	void on_qqAlpha_editingFinished();

	void on_qqBeta_editingFinished();

	void on_qqGamma_editingFinished();

	void on_qqApplyAll_clicked();

	void on_qqTensorMatrix_clicked();

	void on_qqCoordWorld_clicked();

	void on_qqCoordParent_clicked();

	void on_qqMaterial_currentIndexChanged(int index);

//	void on_qqDuplicateMaterial_clicked();

	void on_qqAutomaticToNonStatic_clicked();

private:
    Ui::CQDlgShapeDyn *ui;
};

#endif // QDLGSHAPEDYN_H
