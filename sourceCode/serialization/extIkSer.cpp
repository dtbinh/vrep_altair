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
#include "extIkSer.h"

CExtIkSer::CExtIkSer()
{
	_reading=false;
}


CExtIkSer::~CExtIkSer()
{
}

void CExtIkSer::writeFloat(float a)
{
	_writeBuffer.push_back(((unsigned char*)&a)[0]);
	_writeBuffer.push_back(((unsigned char*)&a)[1]);
	_writeBuffer.push_back(((unsigned char*)&a)[2]);
	_writeBuffer.push_back(((unsigned char*)&a)[3]);
}

void CExtIkSer::writeInt(int a)
{
	_writeBuffer.push_back(((unsigned char*)&a)[0]);
	_writeBuffer.push_back(((unsigned char*)&a)[1]);
	_writeBuffer.push_back(((unsigned char*)&a)[2]);
	_writeBuffer.push_back(((unsigned char*)&a)[3]);
}

void CExtIkSer::writeUInt(unsigned int a)
{
	_writeBuffer.push_back(((unsigned char*)&a)[0]);
	_writeBuffer.push_back(((unsigned char*)&a)[1]);
	_writeBuffer.push_back(((unsigned char*)&a)[2]);
	_writeBuffer.push_back(((unsigned char*)&a)[3]);
}

void CExtIkSer::writeWord(unsigned short a)
{
	_writeBuffer.push_back(((unsigned char*)&a)[0]);
	_writeBuffer.push_back(((unsigned char*)&a)[1]);
}

void CExtIkSer::writeByte(unsigned char a)
{
	_writeBuffer.push_back(a);
}

void CExtIkSer::writeChar(char a)
{
	_writeBuffer.push_back((unsigned char)a);
}

void CExtIkSer::writeString(const char* string)
{
	for (int i=0;i<int(strlen(string));i++)
		_writeBuffer.push_back((unsigned char)string[i]);
	_writeBuffer.push_back(0);
}

unsigned char* CExtIkSer::getBuffer(int& bufferLength)
{
	bufferLength=int(_writeBuffer.size());
	return(&_writeBuffer[0]);
}


