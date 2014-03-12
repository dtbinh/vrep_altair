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

#include <QtOpenGL>
#include "VThread.h"

class COffscreenGlContext : public QObject
{
	Q_OBJECT
public:

	COffscreenGlContext(int offscreenType,int resX,int resY,QGLWidget *otherWidgetToShareResourcesWith,int majorOpenGl,int minorOpenGl);
	virtual ~COffscreenGlContext();

	bool makeCurrent();
	bool doneCurrent();

	bool canBeDeleted();
	void moveGlContextToThread(QThread* otherThread);

	enum OFFSCREEN_TYPE
	{
		QT_OFFSCREEN_TP	= 0,
		QT_WINDOW_SHOW_TP =1,
		QT_WINDOW_HIDE_TP =2,
		NATIVE_WINDOW_SHOW_TP =3,
		NATIVE_WINDOW_HIDE_TP =4,
	};

protected:
	int _offscreenType;
	QThread* _initialThread;

	// Native window vars:
#ifdef WIN_VREP
	HWND _windowHandle;
	HDC _hdc;
	HGLRC _nativeContext;
	static std::vector<HGLRC> _allNativeContexts;
#endif

	// Qt offscreen vars:
	QOpenGLContext* _qContext;
	QOffscreenSurface* _qOffscreenSurface;

	// Qt window vars:
	QGLWidget* _hiddenWindow;

	static std::vector<QOpenGLContext*> _allQtContexts;
	static std::vector<QGLWidget*> _allQtWidgets;
};
