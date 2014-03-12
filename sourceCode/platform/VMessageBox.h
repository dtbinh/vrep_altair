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

#pragma once
#include <string>

// FULLY STATIC CLASS
class VMessageBox  
{
public:
	// Do not directly call these! Call instead App::uiThread->messageBox_information...
	static WORD information_(QWidget* parent,const std::string& title,const std::string& message,WORD flags);
	static WORD question_(QWidget* parent,const std::string& title,const std::string& message,WORD flags);
	static WORD warning_(QWidget* parent,const std::string& title,const std::string& message,WORD flags);
	static WORD critical_(QWidget* parent,const std::string& title,const std::string& message,WORD flags);

	static WORD informationSystemModal_(QWidget* parent,const std::string& title,const std::string& message,WORD flags);
private:
	static WORD _displayBox(QWidget* parent,const std::string& title,const std::string& message,WORD flags);

public:
	static WORD OKELI;
	static WORD YES_NO;
	static WORD YES_NO_CANCEL;
	static WORD OK_CANCEL;

	static WORD REPLY_CANCEL;
	static WORD REPLY_NO;
	static WORD REPLY_YES;
	static WORD REPLY_OK;
	static WORD REPLY_ERROR;

private:
	static WORD APP_MODAL;
	static WORD INFO_TYPE;
	static WORD QUESTION_TYPE;
	static WORD WARNING_TYPE;
	static WORD CRITICAL_TYPE;
};
