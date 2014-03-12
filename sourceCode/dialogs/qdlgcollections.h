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

#ifndef QDLGCOLLECTIONS_H
#define QDLGCOLLECTIONS_H
#include "DlgEx.h"
#include <QListWidgetItem>

namespace Ui {
	class CQDlgCollections;
}

class CQDlgCollections : public CDlgEx
{
    Q_OBJECT

public:
    explicit CQDlgCollections(QWidget *parent = 0);
	~CQDlgCollections();

	void refresh();

	void initializationEvent();

	int operationType;
	bool baseInclusive;
	bool tipInclusive;
	void refreshGroupList();
	void refreshSubGroupList();
	void refreshButtons();
	int getSelectedGroupID();
	void selectGroup(int groupID);
	int getAllowedOpType(int desiredOp);
	void doTheOperation(int opType,bool additive);

private slots:

	void on_qqNewCollection_clicked();

	void on_qqOverride_clicked();

	void on_qqCollectionList_itemSelectionChanged();

	void onDeletePressed();

	void on_qqVisualizeCollection_clicked();

	void on_qqCollectionList_itemChanged(QListWidgetItem *item);

	void on_qqAllObjects_clicked();

	void on_qqLooseObjects_clicked();

	void on_qqTrees_clicked();

	void on_qqBaseIncluded_clicked();

	void on_qqChains_clicked();

	void on_qqTipIncluded_clicked();

	void on_qqAdd_clicked();

	void on_qqSubtract_clicked();

private:
    Ui::CQDlgCollections *ui;
};

#endif // QDLGCOLLECTIONS_H
