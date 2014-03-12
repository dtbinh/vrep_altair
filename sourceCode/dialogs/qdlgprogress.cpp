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
#include "qdlgprogress.h"
#include "ui_qdlgprogress.h"
#include "App.h"

CQDlgProgress::CQDlgProgress(QWidget *parent) :
	QDialog(parent,Qt::SplashScreen|Qt::WindowStaysOnTopHint),
    ui(new Ui::CQDlgProgress)
{
    ui->setupUi(this);
}

CQDlgProgress::~CQDlgProgress()
{
    delete ui;
}

void CQDlgProgress::refresh()
{
	setWindowTitle(title.c_str());
	ui->qqLine1->setText(lines[0].c_str());
	ui->qqLine2->setText(lines[1].c_str());
	ui->qqLine3->setText(lines[2].c_str());
}
