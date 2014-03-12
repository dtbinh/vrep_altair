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

#ifndef QDLGDETECTIONVOLUME_H
#define QDLGDETECTIONVOLUME_H

#include "DlgEx.h"
#include "ConvexVolume.h"
#include "proximitySensor.h"
#include "Mill.h"

namespace Ui {
    class CQDlgDetectionVolume;
}

class CQDlgDetectionVolume : public CDlgEx
{
    Q_OBJECT

public:
    explicit CQDlgDetectionVolume(QWidget *parent = 0);
    ~CQDlgDetectionVolume();

	void refresh();
	void cancelEvent();

	CConvexVolume* getCurrentConvexVolume();
	CProxSensor* getCurrentProxSensor();
	CMill* getCurrentMill();

	bool inMainRefreshRoutine;

	static bool showVolumeWindow;

private slots:
	void on_qqType_currentIndexChanged(int index);

	void on_qqOffset_editingFinished();

	void on_qqRadius_editingFinished();

	void on_qqRange_editingFinished();

	void on_qqRadiusFar_editingFinished();

	void on_qqSizeX_editingFinished();

	void on_qqAngle_editingFinished();

	void on_qqSizeY_editingFinished();

	void on_qqFaceCount_editingFinished();

	void on_qqSizeFarX_editingFinished();

	void on_qqFaceCountFar_editingFinished();

	void on_qqSizeFarY_editingFinished();

	void on_qqSubdivisions_editingFinished();

	void on_qqInsideGap_editingFinished();

	void on_qqSubdivisionsFar_editingFinished();

	void on_qqApplyAll_clicked();

private:
    Ui::CQDlgDetectionVolume *ui;
};

#endif // QDLGDETECTIONVOLUME_H
