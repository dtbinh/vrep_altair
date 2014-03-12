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

#include "GraphData.h"

class CGraphDataComb  
{
public:

	CGraphDataComb();
	virtual ~CGraphDataComb();

	// Various
	void setVisible(bool v);
	bool getVisible();
	void setVisibleOnTopOfEverything(bool v);
	bool getVisibleOnTopOfEverything();
	void set3DCurveWidth(float width);
	float get3DCurveWidth();
	void setLinkPoints(bool l);
	bool getLinkPoints();
	void setIdentifier(int newIdentifier);
	int getIdentifier();
	std::string getName();
	void setName(std::string theName);
	void setLabel(bool l);
	bool getLabel();
	void serialize(CSer& ar);
	CGraphDataComb* copyYourself();

	void setCurveRelativeToWorld(bool relToWorld);
	bool getCurveRelativeToWorld();

	int getLifeID();

	// Variables which need to be serialized & copied 
	int data[3];
	float ambientColor[3];
	float emissiveColor[3];

protected:
	// Variables which need to be serialized & copied 
	std::string name;
	int identifier;
	bool visible;
	bool visibleOnTopOfEverything; // only for 3D curves!
	float threeDCurveWidth; // only for 3D curves!
	bool linkPoints;
	bool label;
	bool _curveRelativeToWorld; // only for 3D curves!

private:
	int _lifeID;
};
