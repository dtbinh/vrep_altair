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

#ifndef QDLGROTATIONS_H
#define QDLGROTATIONS_H

#include "DlgEx.h"
#include "7Vector.h"

namespace Ui {
	class CQDlgRotations;
}

class CQDlgRotations : public CDlgEx
{
    Q_OBJECT

public:
	explicit CQDlgRotations(QWidget *parent = 0);
	~CQDlgRotations();

	void refresh();

	void cancelEvent();

	static bool forbidManipWhenRunning;
	static bool forbidManipWhenNotRunning;
	static int manipulationModePermission;
	static int manipulationRotationRelativeTo;
	static float manipulationRotationStepSize;

protected:
	void _enableCoordinatePart(bool enableState,bool anglePart,bool enableButtons,bool alsoRadioButtons);
	void _enableTransformationPart(bool enableState,int partIndex,bool enableButtons,bool alsoRadioButtons);
	void _setDefaultValuesCoordinatePart(bool anglePart,bool alsoRadioButtons);
	void _setDefaultValuesTransformationPart(int partIndex,bool alsoRadioButtons);
	void _setValuesTransformationPart(int partIndex,bool alsoRadioButtons);

	// Coord part
	void _setCoord_userUnit(float newValueInUserUnit,bool orientation,int index);
	C7Vector _getNewTransf(const C7Vector& transf,float newValueInUserUnit,bool orientation,int index);
	void _applyCoord(bool orientation,int mask);
	void _copyTransf(const C7Vector& tr,C7Vector& trIt,bool orientation,int mask);

	// Transf part
	void _applyTransformation(int t);
	void _transform(C7Vector& tr,int t,bool self);

	static int coordMode; //0=abs,1=rel to parent
	static float rotAngles[3];
	static float translationValues[3];
	static float scalingValues[3];
	static int transfMode; //0=abs,1=rel to parent,2=rel to self

	int lastLastSelectionID;

private slots:
	void on_qqCoordWorld_clicked();

	void on_qqCoordParent_clicked();

	void on_qqCoordAlpha_editingFinished();

	void on_qqCoordBeta_editingFinished();

	void on_qqCoordGamma_editingFinished();

	void on_qqCoordApplyOr_clicked();

	void on_qqTransfWorld_clicked();

	void on_qqTransfParent_clicked();

	void on_qqTransfOwn_clicked();

	void on_qqTransfAlpha_editingFinished();

	void on_qqTransfBeta_editingFinished();

	void on_qqTransfGamma_editingFinished();

	void on_qqTransfApplyOr_clicked();


	void on_qqDisabledWhenNotRunning_clicked();

	void on_qqDisabledWhenRunning_clicked();

	void on_qqOrWorld_clicked();

	void on_qqOrParent_clicked();

	void on_qqOrOwn_clicked();

	void on_qqOrA_clicked();

	void on_qqOrB_clicked();

	void on_qqOrG_clicked();

	void on_qqOrCombo_activated(int index);


	void on_qqRememberManipulationSettings_clicked();

private:
	Ui::CQDlgRotations *ui;
};

#endif // QDLGROTATIONS_H
