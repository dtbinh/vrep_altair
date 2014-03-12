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

#ifndef QDLGUI_H
#define QDLGUI_H

#include "DlgEx.h"
#include <QListWidgetItem>
#include <QShortcut>

namespace Ui {
    class CQDlgUi;
}

class CQDlgUi : public CDlgEx
{
    Q_OBJECT

public:
    explicit CQDlgUi(QWidget *parent = 0);
    ~CQDlgUi();

	void refresh();

	void cancelEvent();


	void updateObjectsInList();
	void selectObjectInList(int objectID);

	bool inMainRefreshRoutine;
	bool inListSelectionRoutine;
	bool noListSelectionAllowed;

	QShortcut* delKeyShortcut;
	QShortcut* backspaceKeyShortcut;

	private slots:
	void onDeletePressed();

	void on_qqAddNew_clicked();

	void on_qqList_itemSelectionChanged();

	void on_qqList_itemChanged(QListWidgetItem *item);

	void on_qqCellCountH_editingFinished();

	void on_qqCellCountV_editingFinished();

	void on_qqCellSizeH_editingFinished();

	void on_qqCellSizeV_editingFinished();

	void on_qqUiPosH_editingFinished();

	void on_qqUiPosV_editingFinished();

	void on_qqUiBorderL_clicked();

	void on_qqUiBorderT_clicked();

	void on_qqVisible_clicked();

	void on_qqMoveable_clicked();

	void on_qqVisibleDuringSimulation_clicked();

	void on_qqFixedWidthFont_clicked();

	void on_qqVisibleWhenObjectSelected_clicked();

	void on_qqSelectObject_clicked();

	void on_qqPageCombo_currentIndexChanged(int index);

	void on_qqAssociatedObject_currentIndexChanged(int index);

	void on_qqSetTexture_clicked();

	void on_qqAdjustRolledUpSizes_clicked();

private:
    Ui::CQDlgUi *ui;
};

#endif // QDLGUI_H
