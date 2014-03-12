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
#include "IKGraphNode.h"

CIKGraphNode::CIKGraphNode()
{
	elementID=-1;
	explorationID=-1;
	userData0=-1;
	userData1=-1;
}

CIKGraphNode::~CIKGraphNode()
{
}

CIKGraphNode* CIKGraphNode::getUnexplored(int pos)
{
	return(NULL);
}

CIKGraphNode* CIKGraphNode::getNeighbour(int pos,bool noLinkNeighbour)
{
	return(NULL);
}

int CIKGraphNode::getNumberOfUnexplored()
{	
	return(0);
}

CIKGraphNode* CIKGraphNode::getNeighbourWithExplorationID(int theID)
{
	return(NULL);
}


CIKGraphNode* CIKGraphNode::getExploredWithSmallestExplorationID()
{
	return(NULL);
}

int CIKGraphNode::getConnectionNumber()
{
	return(0);
}
