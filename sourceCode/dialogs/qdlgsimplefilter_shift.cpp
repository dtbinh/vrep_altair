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
#include "qdlgsimplefilter_shift.h"
#include "ui_qdlgsimplefilter_shift.h"
#include "GV.h"
#include "Tt.h"

CQDlgSimpleFilter_shift::CQDlgSimpleFilter_shift(QWidget *parent) :
	CQDlgSimpleFilter(parent),
	ui(new Ui::CQDlgSimpleFilter_shift)
{
    ui->setupUi(this);
}

CQDlgSimpleFilter_shift::~CQDlgSimpleFilter_shift()
{
    delete ui;
}

void CQDlgSimpleFilter_shift::refresh()
{
	ui->qqWrap->setChecked((_byteParameters[0]&1)==0);
	ui->qqX->setText(tt::FNb(0,_floatParameters[0],3,true).c_str());
	ui->qqY->setText(tt::FNb(0,_floatParameters[1],3,true).c_str());
}

void CQDlgSimpleFilter_shift::on_qqOkCancel_accepted()
{
	defaultModalDialogEndRoutine(true);
}

void CQDlgSimpleFilter_shift::on_qqOkCancel_rejected()
{
	defaultModalDialogEndRoutine(false);
}

void CQDlgSimpleFilter_shift::on_qqX_editingFinished()
{
	bool ok;
	float newVal=ui->qqX->text().toFloat(&ok);
	if (ok)
	{
		tt::limitValue(-1.0f,1.0f,newVal);
		_floatParameters[0]=newVal;
	}
	refresh();
}

void CQDlgSimpleFilter_shift::on_qqY_editingFinished()
{
	bool ok;
	float newVal=ui->qqY->text().toFloat(&ok);
	if (ok)
	{
		tt::limitValue(-1.0f,1.0f,newVal);
		_floatParameters[1]=newVal;
	}
	refresh();
}

void CQDlgSimpleFilter_shift::on_qqWrap_clicked()
{
	_byteParameters[0]^=1;
	refresh();
}
