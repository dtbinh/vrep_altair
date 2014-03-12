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

#ifndef QDLGFILTERS_H
#define QDLGFILTERS_H

#include "DlgEx.h"
#include <QListWidgetItem>

namespace Ui {
    class CQDlgFilters;
}

class CQDlgFilters : public CDlgEx
{
    Q_OBJECT

public:
    explicit CQDlgFilters(QWidget *parent = 0);
    ~CQDlgFilters();

	void refresh();
	void cancelEvent();

	void updateObjectsInList();
	int getSelectedObjectID();
	void selectObjectInList(int objectID);
	bool _editFilter(int index);

	bool inMainRefreshRoutine;
	int currentComboIndex;

private slots:
	void onDeletePressed();

	void on_qqFilterCombo_currentIndexChanged(int index);

	void on_qqFilterList_itemDoubleClicked(QListWidgetItem *item);

	void on_qqAddFilter_clicked();

	void on_qqUp_clicked();

	void on_qqDown_clicked();

	void on_qqComponentEnabled_clicked();

	void on_qqFilterList_itemSelectionChanged();

	void on_qqApply_clicked();

private:
    Ui::CQDlgFilters *ui;
};

#endif // QDLGFILTERS_H
