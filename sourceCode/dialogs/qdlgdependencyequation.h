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

#ifndef QDLGDEPENDENCYEQUATION_H
#define QDLGDEPENDENCYEQUATION_H

#include "VDialog.h"

namespace Ui {
    class CQDlgDependencyEquation;
}

class CQDlgDependencyEquation : public VDialog
{
    Q_OBJECT

public:
    explicit CQDlgDependencyEquation(QWidget *parent = 0);
    ~CQDlgDependencyEquation();

	void cancelEvent();
	void okEvent();

	void refresh();

	bool inMainRefreshRoutine;

private slots:
	void on_qqClose_clicked(QAbstractButton *button);

	void on_qqOffset_editingFinished();

	void on_qqCoeff_editingFinished();

	void on_qqCombo_currentIndexChanged(int index);

private:
    Ui::CQDlgDependencyEquation *ui;
};

#endif // QDLGDEPENDENCYEQUATION_H
