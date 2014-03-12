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

#include "vrepPrecompiledHeader.h"
#include "qdlgsimplefilter_coordExtraction.h"
#include "ui_qdlgsimplefilter_coordExtraction.h"
#include "GV.h"
#include "Tt.h"

CQDlgSimpleFilter_coordExtraction::CQDlgSimpleFilter_coordExtraction(QWidget *parent) :
	CQDlgSimpleFilter(parent),
	ui(new Ui::CQDlgSimpleFilter_coordExtraction)
{
    ui->setupUi(this);
}

CQDlgSimpleFilter_coordExtraction::~CQDlgSimpleFilter_coordExtraction()
{
    delete ui;
}

void CQDlgSimpleFilter_coordExtraction::refresh()
{
	ui->qqX->setText(tt::FNb(0,_intParameters[0],false).c_str());
	ui->qqY->setText(tt::FNb(0,_intParameters[1],false).c_str());
}

void CQDlgSimpleFilter_coordExtraction::on_qqOkCancel_accepted()
{
	defaultModalDialogEndRoutine(true);
}

void CQDlgSimpleFilter_coordExtraction::on_qqOkCancel_rejected()
{
	defaultModalDialogEndRoutine(false);
}

void CQDlgSimpleFilter_coordExtraction::on_qqX_editingFinished()
{
	bool ok;
	int newVal=ui->qqX->text().toInt(&ok);
	if (ok)
	{
		tt::limitValue(1,2048,newVal);
		_intParameters[0]=newVal;
	}
	refresh();
}

void CQDlgSimpleFilter_coordExtraction::on_qqY_editingFinished()
{
	bool ok;
	int newVal=ui->qqY->text().toInt(&ok);
	if (ok)
	{
		tt::limitValue(1,2048,newVal);
		_intParameters[1]=newVal;
	}
	refresh();
}

