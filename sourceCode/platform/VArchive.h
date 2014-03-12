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

#include "VFile.h"
#include <string>

class VArchive  
{
public:
	VArchive(VFile* file,WORD flag);
	virtual ~VArchive();

	void writeLine(const std::string& line); // Will add char(10) and char(13)
	void writeString(const std::string& str); // Will not add char(10) or char(13)
	bool readLine(DWORD& actualPosition,std::string& line,bool keepTabs);

	inline VFile* getFile()
	{
		return(_theFile);
	}

	inline bool isStoring()
	{
		return(!_loading);
	}

	inline bool isLoading()
	{
		return(_loading);
	}

	inline void close()
	{
	}

	inline VArchive& operator<< (const int& v)
	{
		(*_theArchive) << v;
		return(*this);
	}

	inline VArchive& operator<< (const unsigned int& v)
	{
		(*_theArchive) << v;
		return(*this);
	}

	inline VArchive& operator<< (const float& v)
	{
		(*_theArchive) << v;
		return(*this);
	}

	VArchive& operator<< (const double& v)
	{
		// Very special here (because of the strange thing with _theArchive->setFloatingPointPrecision(QDataStream::SinglePrecision) )
		(*_theArchive) << ((unsigned char*)&v)[0];
		(*_theArchive) << ((unsigned char*)&v)[1];
		(*_theArchive) << ((unsigned char*)&v)[2];
		(*_theArchive) << ((unsigned char*)&v)[3];
		(*_theArchive) << ((unsigned char*)&v)[4];
		(*_theArchive) << ((unsigned char*)&v)[5];
		(*_theArchive) << ((unsigned char*)&v)[6];
		(*_theArchive) << ((unsigned char*)&v)[7];
		return(*this);
	}

	inline VArchive& operator<< (const WORD& v)
	{
		(*_theArchive) << v;
		return(*this);
	}

	inline VArchive& operator<< (const unsigned char& v)
	{
		(*_theArchive) << quint8(v);
		return(*this);
	}

	inline VArchive& operator<< (const char& v)
	{
		(*_theArchive) << qint8(v);
		return(*this);
	}

	inline VArchive& operator<< (const signed char& v)
	{
		(*_theArchive) << qint8(v);
		return(*this);
	}

	inline VArchive& operator>> (int& v)
	{
		(*_theArchive) >> v;
		return(*this);
	}

	inline VArchive& operator>> (unsigned int& v)
	{
		(*_theArchive) >> v;
		return(*this);
	}

	inline VArchive& operator>> (float& v)
	{
		(*_theArchive) >> v;
		return(*this);
	}

	VArchive& operator>> (double& v)
	{
		// Very special here (because of the strange thing with _theArchive->setFloatingPointPrecision(QDataStream::SinglePrecision) )
		(*_theArchive) >> ((unsigned char*)&v)[0];
		(*_theArchive) >> ((unsigned char*)&v)[1];
		(*_theArchive) >> ((unsigned char*)&v)[2];
		(*_theArchive) >> ((unsigned char*)&v)[3];
		(*_theArchive) >> ((unsigned char*)&v)[4];
		(*_theArchive) >> ((unsigned char*)&v)[5];
		(*_theArchive) >> ((unsigned char*)&v)[6];
		(*_theArchive) >> ((unsigned char*)&v)[7];
		return(*this);
	}

	inline VArchive& operator>> (WORD& v)
	{
		(*_theArchive) >> v;
		return(*this);
	}

	inline VArchive& operator>> (unsigned char& v)
	{
		(*_theArchive) >> v;
		return(*this);
	}

	inline VArchive& operator>> (signed char& v)
	{
		(*_theArchive) >> v;
		return(*this);
	}

	inline VArchive& operator>> (char& v)
	{
		(*_theArchive) >> ((qint8*)(&v))[0];
		return(*this);
	}

private:
	QDataStream* _theArchive;
	VFile* _theFile;
	bool _loading;

public:
	static WORD LOAD;
	static WORD STORE;
};
