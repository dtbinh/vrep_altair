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

#ifndef QVREP_OPENGLWIDGET_H
#define QVREP_OPENGLWIDGET_H

class COpenglWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit COpenglWidget(QWidget *parent = 0);
    ~COpenglWidget();

	void setOpenGlDisplayEnabled(bool e);
	bool getOpenGlDisplayEnabled();

protected:
	bool _openGlDisplayEnabled;

	void mouseMoveEvent(QMouseEvent* mEvent);
	void mousePressEvent(QMouseEvent* mEvent);
	void mouseReleaseEvent(QMouseEvent* mEvent);
	void mouseDoubleClickEvent(QMouseEvent* mEvent);
	void wheelEvent(QWheelEvent* wEvent);

	void keyPressEvent(QKeyEvent* kEvent);
	void keyReleaseEvent(QKeyEvent* kEvent);

    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

	void paintEvent(QPaintEvent* event);
	void resizeEvent(QResizeEvent* event);

signals:

public slots:
};
#endif // QVREP_OPENGLWIDGET_H
