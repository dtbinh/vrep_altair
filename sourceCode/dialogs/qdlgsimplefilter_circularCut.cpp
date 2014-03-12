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
#include "qdlgsimplefilter_circularCut.h"
#include "ui_qdlgsimplefilter_circularCut.h"
#include "GV.h"
#include "Tt.h"

CQDlgSimpleFilter_circularCut::CQDlgSimpleFilter_circularCut(QWidget *parent) :
	CQDlgSimpleFilter(parent),
	ui(new Ui::CQDlgSimpleFilter_circularCut)
{
    ui->setupUi(this);
}

CQDlgSimpleFilter_circularCut::~CQDlgSimpleFilter_circularCut()
{
    delete ui;
}

void CQDlgSimpleFilter_circularCut::refresh()
{
	ui->qqRadius->setText(tt::FNb(0,_floatParameters[0],3,false).c_str());
	ui->qqInverse->setChecked((_byteParameters[0]&1)!=0);
}

void CQDlgSimpleFilter_circularCut::on_qqOkCancel_accepted()
{
	defaultModalDialogEndRoutine(true);
}

void CQDlgSimpleFilter_circularCut::on_qqOkCancel_rejected()
{
	defaultModalDialogEndRoutine(false);
}

void CQDlgSimpleFilter_circularCut::on_qqRadius_editingFinished()
{
	bool ok;
	float newVal=ui->qqRadius->text().toFloat(&ok);
	if (ok)
	{
		tt::limitValue(0.01f,100.0f,newVal);
		_floatParameters[0]=newVal;
	}
	refresh();
}

void CQDlgSimpleFilter_circularCut::on_qqInverse_clicked()
{
	_byteParameters[0]^=1;
}
