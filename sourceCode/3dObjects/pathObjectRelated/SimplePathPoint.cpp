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
#include "SimplePathPoint.h"
#include "IloIlo.h"
#include "Tt.h"
#include "v_rep_internal.h"

CSimplePathPoint::CSimplePathPoint()
{
	commonInit();
}

CSimplePathPoint::~CSimplePathPoint()
{
}

void CSimplePathPoint::commonInit()
{
	_transformation.setIdentity();
	_bezierFactorBefore=0.5f;
	_bezierFactorAfter=0.5f;
	_maxRelAbsVelocity=1.0f;
	_bezierPointCount=15;
	_onSpotDistance=0.0f;
}

void CSimplePathPoint::setBezierFactors(float fBefore,float fAfter)
{ // 0.99f is so that we don't have dedoubled bezier points!
	tt::limitValue(0.1f,0.99f,fBefore);
	tt::limitValue(0.1f,0.99f,fAfter);
	_bezierFactorBefore=fBefore;
	_bezierFactorAfter=fAfter;
}

void CSimplePathPoint::getBezierFactors(float& fBefore,float& fAfter)
{
	fBefore=_bezierFactorBefore;
	fAfter=_bezierFactorAfter;
}

void CSimplePathPoint::setBezierPointCount(int c)
{
	c=tt::getLimitedInt(1,100,c);
	if (c<3)
		c=1;
	_bezierPointCount=c;
}

int CSimplePathPoint::getBezierPointCount()
{
	return(_bezierPointCount);
}

void CSimplePathPoint::scaleYourself(float scalingFactor)
{
	_transformation.X=_transformation.X*scalingFactor;
}

CSimplePathPoint* CSimplePathPoint::copyYourself()
{ // Everything is copied.
	CSimplePathPoint* newPoint=new CSimplePathPoint();
	newPoint->_transformation=_transformation;
	newPoint->_bezierFactorBefore=_bezierFactorBefore;
	newPoint->_bezierFactorAfter=_bezierFactorAfter;
	newPoint->_maxRelAbsVelocity=_maxRelAbsVelocity;
	newPoint->_bezierPointCount=_bezierPointCount;
	newPoint->_onSpotDistance=_onSpotDistance;
	return(newPoint);
}

void CSimplePathPoint::serialize(CSer& ar)
{
	if (ar.isStoring())
	{		// Storing
		ar.storeDataName("At2");
		ar << _transformation(0) << _transformation(1) << _transformation(2) << _transformation(3);
		ar << _transformation(4) << _transformation(5) << _transformation(6);
		ar << _bezierFactorBefore << _bezierFactorAfter << _bezierPointCount << _maxRelAbsVelocity;
		ar.flush();

		ar.storeDataName("At3");
		ar << _onSpotDistance;
		ar.flush();

		ar.storeDataName(SER_END_OF_OBJECT);
	}
	else
	{		// Loading
		int byteQuantity;
		std::string theName="";
		while (theName.compare(SER_END_OF_OBJECT)!=0)
		{
			theName=ar.readDataName();
			if (theName.compare(SER_END_OF_OBJECT)!=0)
			{
				bool noHit=true;
				if (theName.compare("At2")==0)
				{
					noHit=false;
					ar >> byteQuantity;
					ar >> _transformation(0) >> _transformation(1) >> _transformation(2) >> _transformation(3);
					ar >> _transformation(4) >> _transformation(5) >> _transformation(6);
					ar >> _bezierFactorBefore >> _bezierFactorAfter >> _bezierPointCount >> _maxRelAbsVelocity;
				}
				if (theName.compare("At3")==0)
				{
					noHit=false;
					ar >> byteQuantity;
					ar >> _onSpotDistance;
				}
				if (noHit)
					ar.loadUnknownData();
			}
		}
	}
}
