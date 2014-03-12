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
#include "qdlginsertscript.h"
#include "ui_qdlginsertscript.h"
#include "v_rep_internal.h"
#include "v_repStrings.h"
#include "App.h"

CQDlgInsertScript::CQDlgInsertScript(QWidget *parent) :
	VDialog(parent,QT_MODAL_DLG_STYLE),
    ui(new Ui::CQDlgInsertScript)
{
    ui->setupUi(this);
}

CQDlgInsertScript::~CQDlgInsertScript()
{
    delete ui;
}

void CQDlgInsertScript::cancelEvent()
{
	defaultModalDialogEndRoutine(false);
}

void CQDlgInsertScript::okEvent()
{
	scriptType=ui->qqCombo->itemData(ui->qqCombo->currentIndex()).toInt();
	defaultModalDialogEndRoutine(true);
}

void CQDlgInsertScript::initialize()
{
	ui->qqCombo->clear();
	ui->qqCombo->addItem(strTranslate(IDS_MAIN_SCRIPT),QVariant(sim_scripttype_mainscript));
	ui->qqCombo->addItem(strTranslate(IDS_CHILD_SCRIPT_UNTHREADED),QVariant(sim_scripttype_childscript));
	ui->qqCombo->addItem(strTranslate(IDS_CHILD_SCRIPT_THREADED),QVariant(sim_scripttype_childscript|sim_scripttype_threaded));
}

void CQDlgInsertScript::on_qqOkCancel_accepted()
{
	scriptType=ui->qqCombo->itemData(ui->qqCombo->currentIndex()).toInt();
	defaultModalDialogEndRoutine(true);
}

void CQDlgInsertScript::on_qqOkCancel_rejected()
{
	defaultModalDialogEndRoutine(false);
}
