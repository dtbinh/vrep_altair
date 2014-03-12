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

#ifndef QDLGMODELTHUMBNAIL_H
#define QDLGMODELTHUMBNAIL_H

#include "VDialog.h"
#include "visionSensor.h"
#include "Thumbnail.h"

namespace Ui {
    class CQDlgModelThumbnail;
}

class CQDlgModelThumbnail : public VDialog
{
    Q_OBJECT

public:
    explicit CQDlgModelThumbnail(QWidget *parent = 0);
    ~CQDlgModelThumbnail();

	void cancelEvent();
	void okEvent();

	void initialize();
	void actualizeBitmap();

	CVisionSensor* rs;
	float rotX;
	float rotY;
	float zoom;
	float shiftX;
	float shiftY;
	bool hideEdges;
	bool antialiasing;
	std::vector<int> sel;

	CThumbnail thumbnail;
	int modelBaseDummyID;
	bool thumbnailIsFromFile;

private slots:
	void on_qqFromFile_clicked();

	void on_qqZoomP_clicked();

	void on_qqZoomM_clicked();

	void on_qqVShiftP_clicked();

	void on_qqVShiftM_clicked();

	void on_qqVRotP_clicked();

	void on_qqVRotM_clicked();

	void on_qqHShiftM_clicked();

	void on_qqHShiftP_clicked();

	void on_qqHRotM_clicked();

	void on_qqHRotP_clicked();

	void on_qqOkCancel_accepted();

	void on_qqOkCancel_rejected();

	void on_qqHideEdges_clicked(bool checked);

	void on_qqAntialiasing_clicked(bool checked);

private:
    Ui::CQDlgModelThumbnail *ui;
};

#endif // QDLGMODELTHUMBNAIL_H
