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
#include "qdlgjoints.h"
#include "ui_qdlgjoints.h"
#include "Tt.h"
#include "GV.h"
#include "qdlgmaterial.h"
#include "App.h"
#include "qdlgdependencyequation.h"
#include "qdlgmotionmodeparameters.h"
#include "qdlgjointdyn.h"
#include "v_repStrings.h"

bool CQDlgJoints::showDynamicWindow=false;

CQDlgJoints::CQDlgJoints(QWidget *parent) :
	CDlgEx(parent),
    ui(new Ui::CQDlgJoints)
{
    ui->setupUi(this);
	inMainRefreshRoutine=false;
}

CQDlgJoints::~CQDlgJoints()
{
    delete ui;
}

void CQDlgJoints::cancelEvent()
{
	// we override this cancel event. The container window should close, not this one!!
	App::mainWindow->dlgCont->close(OBJECT_DLG);
}

void CQDlgJoints::refresh()
{
	inMainRefreshRoutine=true;

	bool sel=App::ct->objCont->isLastSelectionAJoint();
	bool bigSel=(App::ct->objCont->isLastSelectionAJoint()&&(App::ct->objCont->getJointNumberInSelection()>1));
	bool simStopped=App::ct->simulation->isSimulationStopped();
	bool revolute=false;
	bool prismatic=false;
	bool spherical=false;
	bool dynamic=false;
	CJoint* it=NULL;
	if (sel)
	{
		it=(CJoint*)App::ct->objCont->getLastSelection();
		revolute=(it->getJointType()==sim_joint_revolute_subtype);
		prismatic=(it->getJointType()==sim_joint_prismatic_subtype);
		spherical=(it->getJointType()==sim_joint_spherical_subtype);
		dynamic=((it->getJointMode()==sim_jointmode_force)||it->getHybridFunctionality() );
	}

	ui->qqMotionHandlingEnabled->setChecked(App::ct->mainSettings->jointMotionHandlingEnabled);

	ui->qqCyclic->setEnabled(sel&&revolute&&simStopped);
	ui->qqPitch->setEnabled(sel&&revolute&&simStopped&&(!dynamic)&&(!it->getPositionIsCyclic()));
	ui->qqMinimum->setEnabled(sel&&(!spherical)&&(!it->getPositionIsCyclic())&&simStopped);
	if (spherical)
		ui->qqRange->setEnabled(sel&&(!dynamic)&&simStopped);
	else
		ui->qqRange->setEnabled(sel&&(!it->getPositionIsCyclic())&&simStopped);
	ui->qqPosition->setEnabled(sel&&(!spherical));
	ui->qqAlpha->setEnabled(sel&&spherical&&(!dynamic)&&simStopped);
	ui->qqBeta->setEnabled(sel&&spherical&&(!dynamic)&&simStopped);
	ui->qqGamma->setEnabled(sel&&spherical&&(!dynamic)&&simStopped);
	ui->qqIkWeight->setEnabled(sel);
	ui->qqMaxStepSize->setEnabled(sel&&simStopped);
	ui->qqApplyConfig->setEnabled(sel&&bigSel&&simStopped);

	ui->qqJointModeCombo->setEnabled(sel&&simStopped);
	ui->qqJointModeCombo->clear();
	ui->qqHybrid->setEnabled(sel&&simStopped&&(it->getJointMode()!=sim_jointmode_force)&&(!spherical));
	ui->qqApplyMode->setEnabled(sel&&bigSel&&simStopped);

	ui->qqAdjustDependency->setEnabled(sel&&simStopped&&((it->getJointMode()==sim_jointmode_dependent)||(it->getJointMode()==sim_jointmode_ikdependent)));
	ui->qqAdjustMotion->setEnabled(sel&&simStopped&&(it->getJointMode()==sim_jointmode_motion));
	ui->qqAdjustDynamicParameters->setEnabled(true); 
	ui->qqAdjustDynamicParameters->setChecked(showDynamicWindow);

	ui->qqLength->setEnabled(sel&&(!spherical)&&simStopped);
	ui->qqDiameter->setEnabled(sel&&simStopped);
	ui->qqAdjustColorA->setEnabled(sel&&simStopped);
	ui->qqAdjustColorB->setEnabled(sel&&simStopped);
	ui->qqApplyAppearance->setEnabled(sel&&bigSel&&simStopped);

	ui->qqCyclic->setChecked(sel&&revolute&&it->getPositionIsCyclic());
	ui->qqHybrid->setChecked(sel&&it->getHybridFunctionality());

	if (sel)
	{
		if (revolute)
		{
			ui->qqPitch->setText(gv::getPitchStr(true,it->getScrewPitch()).c_str());
			if (it->getPositionIsCyclic())
			{
				ui->qqMinimum->setText("");
				ui->qqRange->setText("");
			}
			else
			{
				ui->qqMinimum->setText(gv::getAngleStr(true,it->getPositionIntervalMin()).c_str());
				ui->qqRange->setText(gv::getAngleStr(false,it->getPositionIntervalRange()).c_str());
			}
			ui->qqPosition->setText(gv::getAngleStr(true,it->getPosition()).c_str());
		}
		else
			ui->qqPitch->setText("");

		if (prismatic)
		{
			ui->qqMinimum->setText(gv::getSizeStr(true,it->getPositionIntervalMin()).c_str());
			ui->qqRange->setText(gv::getSizeStr(false,it->getPositionIntervalRange()).c_str());
			ui->qqPosition->setText(gv::getSizeStr(true,it->getPosition()).c_str());
			ui->qqMaxStepSize->setText(gv::getSizeStr(false,it->getMaxStepSize()).c_str());
		}
		else
			ui->qqMaxStepSize->setText(gv::getAngleStr(false,it->getMaxStepSize()).c_str());


		if (spherical)
		{
			ui->qqMinimum->setText("");
			if (dynamic)
				ui->qqRange->setText("");
			else
				ui->qqRange->setText(gv::getAngleStr(false,it->getPositionIntervalRange()).c_str());
			ui->qqPosition->setText("");
			C3Vector euler(it->getSphericalTransformation().getEulerAngles());
			ui->qqAlpha->setText(gv::getAngleStr(true,euler(0)).c_str());
			ui->qqBeta->setText(gv::getAngleStr(true,euler(1)).c_str());
			ui->qqGamma->setText(gv::getAngleStr(true,euler(2)).c_str());
			ui->qqLength->setText("");
		}
		else
		{
			ui->qqAlpha->setText("");
			ui->qqBeta->setText("");
			ui->qqGamma->setText("");
			ui->qqLength->setText(gv::getSizeStr(false,it->getLength()).c_str());
		}

		ui->qqIkWeight->setText(tt::FNb(0,it->getIKWeight(),4).c_str());
		ui->qqDiameter->setText(gv::getSizeStr(false,it->getDiameter()).c_str());


		ui->qqJointModeCombo->addItem(strTranslate(IDSN_JOINT_IS_IN_PASSIVE_MODE),QVariant(sim_jointmode_passive));
		ui->qqJointModeCombo->addItem(strTranslate(IDSN_JOINT_IS_IN_IK_MODE),QVariant(sim_jointmode_ik));
		if (!spherical)
		{
			ui->qqJointModeCombo->addItem(strTranslate(IDSN_JOINT_IS_IN_DEPENDENT_IK_MODE),QVariant(sim_jointmode_ikdependent));
			ui->qqJointModeCombo->addItem(strTranslate(IDSN_JOINT_IS_IN_DEPENDENT_MODE),QVariant(sim_jointmode_dependent));
			ui->qqJointModeCombo->addItem(strTranslate(IDSN_JOINT_IS_IN_MOTION_MODE),QVariant(sim_jointmode_motion));
		}
		ui->qqJointModeCombo->addItem(strTranslate(IDSN_JOINT_IS_IN_TORQUE_FORCE_MODE),QVariant(sim_jointmode_force));
		for (int i=0;i<ui->qqJointModeCombo->count();i++)
		{
			if (ui->qqJointModeCombo->itemData(i).toInt()==it->getJointMode())
			{
				ui->qqJointModeCombo->setCurrentIndex(i);
				break;
			}
		}

	}
	else
	{
		ui->qqPitch->setText("");
		ui->qqMinimum->setText("");
		ui->qqRange->setText("");
		ui->qqPosition->setText("");
		ui->qqAlpha->setText("");
		ui->qqBeta->setText("");
		ui->qqGamma->setText("");
		ui->qqIkWeight->setText("");
		ui->qqMaxStepSize->setText("");
		ui->qqLength->setText("");
		ui->qqDiameter->setText("");
	}

	VDialog* dlg=App::mainWindow->dlgCont->getDialog(JOINT_DYN_DLG);
	if (dlg!=NULL)
		((CQDlgJointDyn*)dlg)->refresh();

	inMainRefreshRoutine=false;
}

void CQDlgJoints::on_qqMotionHandlingEnabled_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		App::ct->mainSettings->jointMotionHandlingEnabled=!App::ct->mainSettings->jointMotionHandlingEnabled;
		App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		refresh();
	}
}

void CQDlgJoints::on_qqCyclic_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		C3DObject* it=App::ct->objCont->getLastSelection();
		((CJoint*)it)->setPositionIsCyclic(!((CJoint*)it)->getPositionIsCyclic());
		App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		refresh();
	}
}

void CQDlgJoints::on_qqPitch_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		bool ok;
		float newVal=ui->qqPitch->text().toFloat(&ok);
		if (ok)
		{
			it->setScrewPitch(newVal*gv::userToMeter/gv::userToRad);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJoints::on_qqMinimum_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		bool ok;
		float newVal=ui->qqMinimum->text().toFloat(&ok);
		if (ok)
		{
			if (it->getJointType()==sim_joint_prismatic_subtype)
				it->setPositionIntervalMin(newVal*gv::userToMeter);
			else
				it->setPositionIntervalMin(newVal*gv::userToRad);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJoints::on_qqRange_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		bool ok;
		float newVal=ui->qqRange->text().toFloat(&ok);
		if (ok)
		{
			CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
			if (it->getJointType()==sim_joint_prismatic_subtype)
				it->setPositionIntervalRange(newVal*gv::userToMeter);
			else
				it->setPositionIntervalRange(newVal*gv::userToRad);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJoints::on_qqPosition_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		bool ok;
		float newVal=ui->qqPosition->text().toFloat(&ok);
		if (ok)
		{
			CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
			if (it->getJointType()==sim_joint_prismatic_subtype)
				it->setPosition(newVal*gv::userToMeter);
			else
				it->setPosition(newVal*gv::userToRad);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJoints::on_qqAlpha_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		if (((CJoint*)App::ct->objCont->getLastSelection())->getJointType()!=sim_joint_spherical_subtype)
			return;
		bool ok;
		float newVal=ui->qqAlpha->text().toFloat(&ok);
		if (ok)
		{
			CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
			C4Vector tr(it->getSphericalTransformation());
			C3Vector euler(tr.getEulerAngles());
			euler(0)=newVal*gv::userToRad;
			tr.setEulerAngles(euler);
			it->setSphericalTransformation(tr);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJoints::on_qqBeta_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		if (((CJoint*)App::ct->objCont->getLastSelection())->getJointType()!=sim_joint_spherical_subtype)
			return;
		bool ok;
		float newVal=ui->qqBeta->text().toFloat(&ok);
		if (ok)
		{
			CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
			C4Vector tr(it->getSphericalTransformation());
			C3Vector euler(tr.getEulerAngles());
			euler(1)=newVal*gv::userToRad;
			tr.setEulerAngles(euler);
			it->setSphericalTransformation(tr);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJoints::on_qqGamma_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		if (((CJoint*)App::ct->objCont->getLastSelection())->getJointType()!=sim_joint_spherical_subtype)
			return;
		bool ok;
		float newVal=ui->qqGamma->text().toFloat(&ok);
		if (ok)
		{
			CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
			C4Vector tr(it->getSphericalTransformation());
			C3Vector euler(tr.getEulerAngles());
			euler(2)=newVal*gv::userToRad;
			tr.setEulerAngles(euler);
			it->setSphericalTransformation(tr);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJoints::on_qqIkWeight_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		bool ok;
		float newVal=ui->qqIkWeight->text().toFloat(&ok);
		if (ok)
		{
			CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
			it->setIKWeight(newVal);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJoints::on_qqMaxStepSize_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		bool ok;
		float newVal=ui->qqMaxStepSize->text().toFloat(&ok);
		if (ok)
		{
			CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
			if (it->getJointType()==sim_joint_prismatic_subtype)
				it->setMaxStepSize(newVal*gv::userToMeter);
			else
				it->setMaxStepSize(newVal*gv::userToRad);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJoints::on_qqApplyConfig_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		if (App::ct->objCont->getJointNumberInSelection()<2)
			return;
		CJoint* last=(CJoint*)App::ct->objCont->getLastSelection();
		for (int i=0;i<App::ct->objCont->getSelSize()-1;i++)
		{
			CJoint* it=App::ct->objCont->getJoint(App::ct->objCont->getSelID(i));
			if ((it!=NULL)&&(last->getJointType()==it->getJointType()) )
			{
				it->setPositionIsCyclic(last->getPositionIsCyclic());
				it->setPositionIntervalRange(last->getPositionIntervalRange());
				it->setPositionIntervalMin(last->getPositionIntervalMin());
				it->setPosition(last->getPosition());
				it->setSphericalTransformation(last->getSphericalTransformation());
				it->setScrewPitch(last->getScrewPitch());
				it->setIKWeight(last->getIKWeight());
				it->setMaxStepSize(last->getMaxStepSize());
				App::ct->undoBufferContainer->announceChangeStart(); // **************** UNDO THINGY ****************
			}
		}
		App::ct->undoBufferContainer->announceChangeEnd(); // **************** UNDO THINGY ****************
		refresh();
	}
}

void CQDlgJoints::on_qqJointModeCombo_currentIndexChanged(int index)
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		if (!inMainRefreshRoutine)
		{
			int objID=ui->qqJointModeCombo->itemData(ui->qqJointModeCombo->currentIndex()).toInt();
			CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
			it->setJointMode(objID);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
			refresh();
		}
	}
}

void CQDlgJoints::on_qqHybrid_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		C3DObject* it=App::ct->objCont->getLastSelection();
		((CJoint*)it)->setHybridFunctionality(!((CJoint*)it)->getHybridFunctionality());
		App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		refresh();
	}
}

void CQDlgJoints::on_qqApplyMode_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		if (App::ct->objCont->getJointNumberInSelection()<2)
			return;
		CJoint* last=(CJoint*)App::ct->objCont->getLastSelection();
		for (int i=0;i<App::ct->objCont->getSelSize()-1;i++)
		{
			CJoint* it=App::ct->objCont->getJoint(App::ct->objCont->getSelID(i));
			if ((it!=NULL)&&(last->getJointType()==it->getJointType()) )
			{
				it->setJointMode(last->getJointMode());
				it->setHybridFunctionality(last->getHybridFunctionality());
				App::ct->undoBufferContainer->announceChangeStart(); // **************** UNDO THINGY ****************
			}
		}
		App::ct->undoBufferContainer->announceChangeEnd(); // **************** UNDO THINGY ****************
		refresh();
	}
}

void CQDlgJoints::on_qqAdjustDependency_clicked()
{
	IF_UI_EVENT_PAUSE_SIM_THREAD_FOR_MODAL_DLG
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CQDlgDependencyEquation theDialog(this);
		theDialog.refresh();
		theDialog.makeDialogModal(); // modifications made directly!
		App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		refresh();
	}
}

void CQDlgJoints::on_qqAdjustMotion_clicked()
{
	IF_UI_EVENT_PAUSE_SIM_THREAD_FOR_MODAL_DLG
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CQDlgMotionModeParameters theDialog(this);
		theDialog.refresh();
		theDialog.makeDialogModal(); // modifications made directly!
		App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		refresh();
	}
}

void CQDlgJoints::on_qqAdjustDynamicParameters_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		showDynamicWindow=!showDynamicWindow;
		if (App::mainWindow->dlgCont->isVisible(JOINT_DYN_DLG)!=showDynamicWindow)
			App::mainWindow->dlgCont->toggle(JOINT_DYN_DLG);
	}
}

void CQDlgJoints::on_qqLength_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		bool ok;
		float newVal=ui->qqLength->text().toFloat(&ok);
		if (ok)
		{
			CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
			it->setLength(newVal*gv::userToMeter);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJoints::on_qqDiameter_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		bool ok;
		float newVal=ui->qqDiameter->text().toFloat(&ok);
		if (ok)
		{
			CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
			it->setDiameter(newVal*gv::userToMeter);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJoints::on_qqAdjustColorA_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		int identification[4]={it->getLifeID(),0,it->getID(),-1};
		CQDlgMaterial::display(identification,&it->colorPart1,App::mainWindow,true,true,true,true,true,false,true,false);
	}
}

void CQDlgJoints::on_qqAdjustColorB_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		int identification[4]={it->getLifeID(),0,it->getID(),-1};
		CQDlgMaterial::display(identification,&it->colorPart2,App::mainWindow,true,true,true,true,true,false,true,false);
	}
}

void CQDlgJoints::on_qqApplyAppearance_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		for (int i=0;i<App::ct->objCont->getSelSize()-1;i++)
		{
			CJoint* it2=App::ct->objCont->getJoint(App::ct->objCont->getSelID(i));
			if (it2!=NULL)
			{
				it->colorPart1.copyYourselfInto(&it2->colorPart1);
				it->colorPart2.copyYourselfInto(&it2->colorPart2);
				it2->setLength(it->getLength());
				it2->setDiameter(it->getDiameter());
				App::ct->undoBufferContainer->announceChangeStart(); // **************** UNDO THINGY ****************
			}
		}
		App::ct->undoBufferContainer->announceChangeEnd(); // **************** UNDO THINGY ****************
	}
}
