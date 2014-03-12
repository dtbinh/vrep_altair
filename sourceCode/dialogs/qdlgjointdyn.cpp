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
#include "qdlgjointdyn.h"
#include "ui_qdlgjointdyn.h"
#include "Tt.h"
#include "GV.h"
#include "IloIlo.h"
#include "propBrowser_engineProp_joint.h"
#include "qdlgjoints.h"
#include "ScintillaModalDlg.h"
#include "App.h"
#include "v_repStringTable.h"

CQDlgJointDyn::CQDlgJointDyn(QWidget *parent) :
	CDlgEx(parent),
    ui(new Ui::CQDlgJointDyn)
{
    ui->setupUi(this);
}

CQDlgJointDyn::~CQDlgJointDyn()
{
    delete ui;
}

void CQDlgJointDyn::cancelEvent()
{ // no cancel event allowed
	CQDlgJoints::showDynamicWindow=false;
	CDlgEx::cancelEvent();
	App::ct->objCont->setFullDialogRefreshFlag();
}

void CQDlgJointDyn::refresh()
{
	bool sel=App::ct->objCont->isLastSelectionAJoint();
	bool bigSel=(App::ct->objCont->isLastSelectionAJoint()&&(App::ct->objCont->getJointNumberInSelection()>1));
	bool simStopped=App::ct->simulation->isSimulationStopped();
	bool revolute=false;
	bool prismatic=false;
	bool spherical=false;
	bool dynamic=false;
	bool dynamicMotControl=false;
	bool motorEnabled=false;
	bool ctrlEnabled=false;
	bool defaultCtrlEnabled=true;
	CJoint* it=NULL;
	if (sel)
	{
		it=(CJoint*)App::ct->objCont->getLastSelection();
		revolute=(it->getJointType()==sim_joint_revolute_subtype);
		prismatic=(it->getJointType()==sim_joint_prismatic_subtype);
		spherical=(it->getJointType()==sim_joint_spherical_subtype);
		dynamic=((it->getJointMode()==sim_jointmode_force)||it->getHybridFunctionality() );
		dynamicMotControl=(dynamic&&(!spherical));
		motorEnabled=dynamic&&it->getEnableDynamicMotor();
		ctrlEnabled=motorEnabled&&it->getEnableDynamicMotorPositionControl();
		defaultCtrlEnabled=!it->getEnableDynamicMotorCustomControl();
	}

	ui->qqMotorEnabled->setEnabled(dynamicMotControl&&(!it->getHybridFunctionality()));
	ui->qqTargetVelocity->setEnabled(dynamicMotControl&&motorEnabled&&((!ctrlEnabled)||it->getEnableTorqueModulation()));
	ui->qqMaxForce->setEnabled(dynamicMotControl&&motorEnabled);
	ui->qqAdjustEngineProperties->setEnabled(dynamic&&simStopped);
	ui->qqApplyDynamicProperties->setEnabled(dynamic&&bigSel&&simStopped);

	ui->qqControlEnabled->setEnabled(dynamicMotControl&&motorEnabled&&(!it->getHybridFunctionality()));
	ui->qqPositionControl->setEnabled(dynamicMotControl&&ctrlEnabled&&simStopped);
	ui->qqCustomControl->setEnabled(dynamicMotControl&&ctrlEnabled&&simStopped);
	ui->qqEditCustomControl->setEnabled(dynamicMotControl&&ctrlEnabled&&simStopped&&(!defaultCtrlEnabled));

	ui->qqRegulateVelocity->setEnabled(dynamicMotControl&&ctrlEnabled&&simStopped&&defaultCtrlEnabled);
	ui->qqRegulateForce->setEnabled(dynamicMotControl&&ctrlEnabled&&simStopped&&defaultCtrlEnabled);
	ui->qqVelocityUpperLimit->setEnabled(dynamicMotControl&&ctrlEnabled&&simStopped&&(!it->getEnableTorqueModulation())&&defaultCtrlEnabled);
	ui->qqTargetPosition->setEnabled(dynamicMotControl&&ctrlEnabled&&(!it->getHybridFunctionality())&&defaultCtrlEnabled);
	ui->qqP->setEnabled(dynamicMotControl&&ctrlEnabled&&defaultCtrlEnabled);
	ui->qqI->setEnabled(dynamicMotControl&&ctrlEnabled&&defaultCtrlEnabled);
	ui->qqD->setEnabled(dynamicMotControl&&ctrlEnabled&&defaultCtrlEnabled);

	ui->qqApplyControlParameters->setEnabled(dynamicMotControl&&bigSel&&simStopped);

	ui->qqMotorEnabled->setChecked(dynamic&&it->getEnableDynamicMotor());
	ui->qqControlEnabled->setChecked(dynamic&&it->getEnableDynamicMotorPositionControl());
	ui->qqRegulateVelocity->setChecked(dynamic&&(!it->getEnableTorqueModulation()));
	ui->qqRegulateForce->setChecked(dynamic&&it->getEnableTorqueModulation());

	if (dynamicMotControl)
	{
		if (it->getEnableDynamicMotorPositionControl())
		{
			if (it->getEnableTorqueModulation())
			{
				if (it->getJointType()==sim_joint_revolute_subtype)
					ui->qqTargetVelocity->setText(gv::getAngularVelocityStr(true,it->getDynamicMotorTargetVelocity()).c_str());
				else
					ui->qqTargetVelocity->setText(gv::getLinearVelocityStr(true,it->getDynamicMotorTargetVelocity()).c_str());
			}
			else
				ui->qqTargetVelocity->setText("");
		}
		else
		{
			if (it->getJointType()==sim_joint_revolute_subtype)
				ui->qqTargetVelocity->setText(gv::getAngularVelocityStr(true,it->getDynamicMotorTargetVelocity()).c_str());
			else
				ui->qqTargetVelocity->setText(gv::getLinearVelocityStr(true,it->getDynamicMotorTargetVelocity()).c_str());
		}

		if (it->getJointType()==sim_joint_revolute_subtype)
		{
			ui->qqMaxForce->setText(tt::FNb(1,it->getDynamicMotorMaximumForce()*gv::kilogramsToUser*gv::meterToUser*gv::meterToUser/(gv::secondsToUser*gv::secondsToUser),3,false).c_str());
			ui->qqVelocityUpperLimit->setText(gv::getAngularVelocityStr(false,it->getDynamicMotorUpperLimitVelocity()).c_str());
			if (it->getHybridFunctionality())
				ui->qqTargetPosition->setText("");
			else
				ui->qqTargetPosition->setText(gv::getAngleStr(true,it->getDynamicMotorPositionControlTargetPosition(),3).c_str());
		}
		else
		{
			ui->qqMaxForce->setText(tt::FNb(1,it->getDynamicMotorMaximumForce()*gv::kilogramsToUser*gv::meterToUser/(gv::secondsToUser*gv::secondsToUser),3,false).c_str());
			ui->qqVelocityUpperLimit->setText(gv::getLinearVelocityStr(false,it->getDynamicMotorUpperLimitVelocity()).c_str());
			if (it->getHybridFunctionality())
				ui->qqTargetPosition->setText("");
			else
				ui->qqTargetPosition->setText(gv::getSizeStr(true,it->getDynamicMotorPositionControlTargetPosition(),3).c_str());
		}

		float pp,ip,dp;
		it->getDynamicMotorPositionControlParameters(pp,ip,dp);
		ui->qqP->setText(tt::FNb(1,pp,3,false).c_str());
		ui->qqI->setText(tt::FNb(1,ip,3,false).c_str());
		ui->qqD->setText(tt::FNb(1,dp,3,false).c_str());

		ui->qqPositionControl->setChecked(defaultCtrlEnabled);
		ui->qqCustomControl->setChecked(!defaultCtrlEnabled);
	}
	else
	{
		ui->qqTargetVelocity->setText("");
		ui->qqMaxForce->setText("");
		ui->qqVelocityUpperLimit->setText("");
		ui->qqTargetPosition->setText("");
		ui->qqP->setText("");
		ui->qqI->setText("");
		ui->qqD->setText("");
	}
}

void CQDlgJointDyn::on_qqMotorEnabled_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		C3DObject* it=App::ct->objCont->getLastSelection();
		((CJoint*)it)->setEnableDynamicMotor(!((CJoint*)it)->getEnableDynamicMotor());
		App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		refresh();
	}
}

void CQDlgJointDyn::on_qqTargetVelocity_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		bool ok;
		float newVal=ui->qqTargetVelocity->text().toFloat(&ok);
		if (ok)
		{
			if (it->getJointType()==sim_joint_prismatic_subtype)
				it->setDynamicMotorTargetVelocity(newVal*gv::userToLinearVel);
			if (it->getJointType()==sim_joint_revolute_subtype)
				it->setDynamicMotorTargetVelocity(newVal*gv::userToAngularVel);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJointDyn::on_qqAdjustEngineProperties_clicked()
{
	IF_UI_EVENT_PAUSE_SIM_THREAD_FOR_MODAL_DLG
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CPropBrowserEngineJoint dlg(App::mainWindow);
		dlg.setModal(true);
		dlg.exec();
		App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		refresh();
	}
}

void CQDlgJointDyn::on_qqMaxForce_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		bool ok;
		float newVal=ui->qqMaxForce->text().toFloat(&ok);
		if (ok)
		{
			if (it->getJointType()==sim_joint_prismatic_subtype)
				it->setDynamicMotorMaximumForce(newVal*gv::userToKilograms*gv::userToMeter/(gv::userToSeconds*gv::userToSeconds));
			if (it->getJointType()==sim_joint_revolute_subtype)
				it->setDynamicMotorMaximumForce(newVal*gv::userToKilograms*gv::userToMeter*gv::userToMeter/(gv::userToSeconds*gv::userToSeconds));
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJointDyn::on_qqApplyDynamicProperties_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		if (App::ct->objCont->getJointNumberInSelection()<2)
			return;
		CJoint* last=(CJoint*)App::ct->objCont->getLastSelection();
		if ( (last->getJointMode()==sim_jointmode_force)||last->getHybridFunctionality() )
		{ // only when the last sel is a joint in force/torque mode, or when it is in hybrid operation
			for (int i=0;i<App::ct->objCont->getSelSize()-1;i++)
			{
				CJoint* it=App::ct->objCont->getJoint(App::ct->objCont->getSelID(i));
				if ( (it!=NULL)&&((it->getJointMode()==last->getJointMode())||(last->getHybridFunctionality()&&it->getHybridFunctionality())) )
				{
					it->setEnableDynamicMotor(last->getEnableDynamicMotor());
					it->setDynamicMotorTargetVelocity(last->getDynamicMotorTargetVelocity());
					it->setDynamicMotorMaximumForce(last->getDynamicMotorMaximumForce());
					float stopERP,stopCFM,bounce,fudge,normalCFM;
					last->getOdeParameters(stopERP,stopCFM,bounce,fudge,normalCFM);
					it->setOdeParameters(stopERP,stopCFM,bounce,fudge,normalCFM);
					last->getBulletParameters(stopERP,stopCFM,normalCFM);
					it->setBulletParameters(stopERP,stopCFM,normalCFM);
					App::ct->undoBufferContainer->announceChangeStart(); // **************** UNDO THINGY ****************
				}
			}
		}
		App::ct->undoBufferContainer->announceChangeEnd(); // **************** UNDO THINGY ****************
		refresh();
	}
}

void CQDlgJointDyn::on_qqControlEnabled_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		C3DObject* it=App::ct->objCont->getLastSelection();
		((CJoint*)it)->setEnableDynamicMotorPositionControl(!((CJoint*)it)->getEnableDynamicMotorPositionControl());
		App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		refresh();
	}
}

void CQDlgJointDyn::on_qqRegulateVelocity_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		C3DObject* it=App::ct->objCont->getLastSelection();
		((CJoint*)it)->setEnableTorqueModulation(false);
		App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		refresh();
	}
}

void CQDlgJointDyn::on_qqVelocityUpperLimit_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		bool ok;
		float newVal=ui->qqVelocityUpperLimit->text().toFloat(&ok);
		if (ok)
		{
			if (it->getJointType()==sim_joint_prismatic_subtype)
				it->setDynamicMotorUpperLimitVelocity(newVal*gv::userToMeter);
			if (it->getJointType()==sim_joint_revolute_subtype)
				it->setDynamicMotorUpperLimitVelocity(newVal*gv::userToRad);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJointDyn::on_qqRegulateForce_clicked()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		C3DObject* it=App::ct->objCont->getLastSelection();
		((CJoint*)it)->setEnableTorqueModulation(true);
		App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		refresh();
	}
}

void CQDlgJointDyn::on_qqTargetPosition_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		bool ok;
		float newVal=ui->qqTargetPosition->text().toFloat(&ok);
		if (ok)
		{
			if (it->getJointType()==sim_joint_prismatic_subtype)
				it->setDynamicMotorPositionControlTargetPosition(newVal*gv::userToMeter);
			if (it->getJointType()==sim_joint_revolute_subtype)
				it->setDynamicMotorPositionControlTargetPosition(newVal*gv::userToRad);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJointDyn::on_qqP_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		bool ok;
		float newVal=ui->qqP->text().toFloat(&ok);
		if (ok)
		{
			float pp,ip,dp;
			it->getDynamicMotorPositionControlParameters(pp,ip,dp);
			it->setDynamicMotorPositionControlParameters(newVal,ip,dp);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJointDyn::on_qqI_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		bool ok;
		float newVal=ui->qqI->text().toFloat(&ok);
		if (ok)
		{
			float pp,ip,dp;
			it->getDynamicMotorPositionControlParameters(pp,ip,dp);
			it->setDynamicMotorPositionControlParameters(pp,newVal,dp);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJointDyn::on_qqD_editingFinished()
{
	IF_UI_EVENT_CAN_READ_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		bool ok;
		float newVal=ui->qqD->text().toFloat(&ok);
		if (ok)
		{
			float pp,ip,dp;
			it->getDynamicMotorPositionControlParameters(pp,ip,dp);
			it->setDynamicMotorPositionControlParameters(pp,ip,newVal);
			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
	}
}

void CQDlgJointDyn::on_qqApplyControlParameters_clicked()
{
	IF_UI_EVENT_CAN_WRITE_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		if (App::ct->objCont->getJointNumberInSelection()<2)
			return;
		CJoint* last=(CJoint*)App::ct->objCont->getLastSelection();
		char* callbackScriptText=NULL;
		if (last->getEnableDynamicMotorCustomControl())
		{
			CLuaScriptObject* script=App::ct->luaScriptContainer->getScriptFromObjectAttachedTo_callback(last->getID());
			if (script)
				callbackScriptText=script->getScriptText();
		}

		if ( (last->getJointMode()==sim_jointmode_force)||last->getHybridFunctionality() )
		{ // only when the last sel is a joint in force/torque mode, or when it is in hybrid operation
			for (int i=0;i<App::ct->objCont->getSelSize()-1;i++)
			{
				CJoint* it=App::ct->objCont->getJoint(App::ct->objCont->getSelID(i));
				if ( (it!=NULL)&&((it->getJointMode()==last->getJointMode())||(last->getHybridFunctionality()&&it->getHybridFunctionality())) )
				{ // only when the two joints are in the same mode, or when both are in hybrid operation
					if (last->getJointType()==it->getJointType())
					{ // only when the two are the same type
						it->setEnableDynamicMotorPositionControl(last->getEnableDynamicMotorPositionControl());
						it->setDynamicMotorUpperLimitVelocity(last->getDynamicMotorUpperLimitVelocity());
						it->setEnableTorqueModulation(last->getEnableTorqueModulation());
						float pp,ip,dp;
						last->getDynamicMotorPositionControlParameters(pp,ip,dp);
						it->setDynamicMotorPositionControlParameters(pp,ip,dp);
						it->setDynamicMotorPositionControlTargetPosition(last->getDynamicMotorPositionControlTargetPosition());
						it->setEnableDynamicMotorCustomControl(false,NULL);
						if (last->getEnableDynamicMotorCustomControl())
							it->setEnableDynamicMotorCustomControl(true,callbackScriptText);
						App::ct->undoBufferContainer->announceChangeStart(); // **************** UNDO THINGY ****************
					}
				}
			}
		}
		App::ct->undoBufferContainer->announceChangeEnd(); // **************** UNDO THINGY ****************
		refresh();
		App::ct->objCont->setFullDialogRefreshFlag(); // to reflect changes in the script dlg too!
	}
}

void CQDlgJointDyn::on_qqCustomControl_clicked()
{
	IF_UI_EVENT_CAN_WRITE_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		if (!it->getEnableDynamicMotorCustomControl())
		{
			std::string filenameAndPath(App::directories->systemDirectory+VREP_SLASH);
			filenameAndPath+=DEFAULT_JOINTCALLBACKSCRIPT_NAME;
			if (VFile::doesFileExist(filenameAndPath))
			{
				try
				{
					VFile file(filenameAndPath,VFile::READ|VFile::SHARE_DENY_NONE);
					VArchive archive(&file,VArchive::LOAD);
					DWORD archiveLength=DWORD(file.getLength());
					char* defaultScript=new char[archiveLength+1];
					for (int i=0;i<int(archiveLength);i++)
						archive >> defaultScript[i];
					defaultScript[archiveLength]=0;
					it->setEnableDynamicMotorCustomControl(true,defaultScript);
					delete[] defaultScript;
					archive.close();
					file.close();
				}
				catch(VFILE_EXCEPTION_TYPE e)
				{
					VFile::reportAndHandleFileExceptionError(e);
					char defaultMessage[]="Default script file could not be found!"; // do not use comments ("--"), we want to cause an execution error!
					it->setEnableDynamicMotorCustomControl(true,defaultMessage);
				}
			}
			else
			{
				char defaultMessage[]="Default joint custom control script file could not be found!"; // do not use comments ("--"), we want to cause an execution error!
				it->setEnableDynamicMotorCustomControl(true,defaultMessage);
			}

			App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
		}
		refresh();
		App::ct->objCont->setFullDialogRefreshFlag(); // to reflect changes in the script dlg too!
	}
}

void CQDlgJointDyn::on_qqPositionControl_clicked()
{
	IF_UI_EVENT_CAN_WRITE_DATA
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		if (it->getEnableDynamicMotorCustomControl())
		{
			if (VMessageBox::REPLY_YES==App::uiThread->messageBox_warning(App::mainWindow,strTranslate("Custom control"),strTranslate(IDSN_SURE_TO_REMOVE_CUSTOM_JOINT_CTRL_WARNING),VMessageBox::YES_NO))
			{
				it->setEnableDynamicMotorCustomControl(false,NULL);
				App::ct->undoBufferContainer->announceChange(); // **************** UNDO THINGY ****************
			}
		}
		refresh();
		App::ct->objCont->setFullDialogRefreshFlag(); // to reflect changes in the script dlg too!
	}
}

void CQDlgJointDyn::on_qqEditCustomControl_clicked()
{
	IF_UI_EVENT_PAUSE_SIM_THREAD_FOR_MODAL_DLG
	{
		if (!App::ct->objCont->isLastSelectionAJoint())
			return;
		CJoint* it=(CJoint*)App::ct->objCont->getLastSelection();
		if (it->getEnableDynamicMotorCustomControl())
		{
			CLuaScriptObject* script=App::ct->luaScriptContainer->getScriptFromObjectAttachedTo_callback(it->getID());
			if (script)
			{
				CScintillaModalDlg dlg(App::mainWindow);
				std::string dlgTitle("Custom control loop for joint '");
				dlgTitle+=it->getName();
				dlgTitle+="'";
				dlg.initialize(script->getScriptID(),dlgTitle.c_str(),false);
				dlg.makeDialogModal();
			}
		}
	}
}
