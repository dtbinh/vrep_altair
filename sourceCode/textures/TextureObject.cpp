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
#include "v_rep_internal.h"
#include "TextureObject.h"
#include "IloIlo.h"
#include "App.h"
#include <boost/format.hpp>

CTextureObject::CTextureObject()
{ // for serialization
	_objectID=SIM_IDSTART_TEXTURE;
	_objectName="Texture";
	_textureSize[0]=16;
	_textureSize[1]=16;
	_oglTextureName=(unsigned int)-1;
	_textureBuffer.resize(4*_textureSize[0]*_textureSize[1],0);
	_providedImageWasRGBA=false;
	_changedFlag=true;
}

CTextureObject::CTextureObject(int sizeX,int sizeY)
{
	_objectID=SIM_IDSTART_TEXTURE;
	_objectName="Texture";
	_textureSize[0]=sizeX;
	_textureSize[1]=sizeY;
	_oglTextureName=(unsigned int)-1;
	_textureBuffer.resize(4*_textureSize[0]*_textureSize[1],0);
	_providedImageWasRGBA=false;
	_changedFlag=true;
}

CTextureObject::~CTextureObject()
{
	_deleteGlTexture();
}

void CTextureObject::setObjectID(int newID)
{
	_objectID=newID;
}

int CTextureObject::getObjectID()
{
	return(_objectID);
}

void CTextureObject::setObjectName(const char* newName)
{
	_objectName=newName;
}

std::string CTextureObject::getObjectName()
{
	return(_objectName);
}

void CTextureObject::getTextureSize(int& sizeX,int& sizeY)
{
	sizeX=_textureSize[0];
	sizeY=_textureSize[1];
}

void CTextureObject::setImage(bool rgba,bool horizFlip,bool vertFlip,unsigned char* data)
{
	int dirX=1;
	int dirY=1;
	int stX=0;
	int stY=0;
	if (horizFlip)
	{
		dirX=-1;
		stX=_textureSize[0]-1;
	}
	if (!vertFlip)
	{
		dirY=-1;
		stY=_textureSize[1]-1;
	}
	if (rgba)
	{
		for (int i=0;i<_textureSize[1];i++)
		{
			int p=i*_textureSize[0];
			int w=(stY+dirY*i)*_textureSize[0];
			for (int j=0;j<_textureSize[0];j++)
			{
				int q=4*(p+j);
				int v=4*(w+stX+dirX*j);
				_textureBuffer[q+0]=data[v+0];
				_textureBuffer[q+1]=data[v+1];
				_textureBuffer[q+2]=data[v+2];
				_textureBuffer[q+3]=data[v+3];
			}
		}
	}
	else
	{
		for (int i=0;i<_textureSize[1];i++)
		{
			int p=i*_textureSize[0];
			int w=(stY+dirY*i)*_textureSize[0];
			for (int j=0;j<_textureSize[0];j++)
			{
				int q=4*(p+j);
				int v=3*(w+stX+dirX*j);
				_textureBuffer[q+0]=data[v+0];
				_textureBuffer[q+1]=data[v+1];
				_textureBuffer[q+2]=data[v+2];
				_textureBuffer[q+3]=255;
			}
		}
	}
	_providedImageWasRGBA=rgba;
	_changedFlag=true;
}

void CTextureObject::startTextureDisplay(bool interpolateColor,bool decal,bool repeatX,bool repeatY)
{
	_generateTextureName();
	glBindTexture(GL_TEXTURE_2D,_oglTextureName);
	if (_changedFlag)
	{
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,_textureSize[0],_textureSize[1],0,GL_RGBA,GL_UNSIGNED_BYTE,&_textureBuffer[0]);
		_changedFlag=false;
	}

	GLint colInt=GL_NEAREST;
	if (interpolateColor)
		colInt=GL_LINEAR;
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // keep to GL_LINEAR here!!
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,colInt);
	GLint repS=GL_CLAMP;
	if (repeatX)
		repS=GL_REPEAT;
	glTexParameteri (GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,repS);
	GLint repT=GL_CLAMP;
	if (repeatY)
		repT=GL_REPEAT;
	glTexParameteri (GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,repT);
	GLint dec=GL_MODULATE;
	if (decal)
		dec=GL_DECAL;
	glTexEnvi (GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,dec);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,_oglTextureName);
	glColor3f(1.0f,1.0f,1.0f);
}

void CTextureObject::endTextureDisplay()
{
	glDisable(GL_TEXTURE_2D);
}

void CTextureObject::_generateTextureName()
{
	if (_oglTextureName==(unsigned int)-1)
	{
		glGenTextures(1,&_oglTextureName);
		glBindTexture(GL_TEXTURE_2D,_oglTextureName);
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,_textureSize[0],_textureSize[1],0,GL_RGBA,GL_UNSIGNED_BYTE,&_textureBuffer[0]);
	}
}

void CTextureObject::_deleteGlTexture()
{
	if (_oglTextureName!=(unsigned int)-1)
		glDeleteTextures(1,&_oglTextureName);
	_oglTextureName=(unsigned int)-1;
	/*
	if (_oglTextureName!=(unsigned int)-1)
	{
		if (VThread::isCurrentThreadTheUiThread())
		{
			// Here we should also check if _oglTextureNameFromGuiThread is true, but since by default we handle
			// everything in the GUI thread, it is ok. For now.
			glDeleteTextures(1,&_oglTextureName);
		}
		else
		{
			if (_oglTextureNameFromGuiThread)
			{ // we do a deferred destruction:
				App::uiThread->destroyGlTexture
			}
			else
			{ // this should not happen if we use default settings (everything handled in the GUI thread)
				glDeleteTextures(1,&_oglTextureName);
			}
		}
	}
	_oglTextureName=(unsigned int)-1;
	*/
}

bool CTextureObject::announceGeneralObjectWillBeErased(int objectID,int subObjectID)
{ // return value true means this object needs destruction!
	for (int i=0;i<int(_dependentObjects.size());i++)
	{
		if (_dependentObjects[i]==objectID)
		{
			if (subObjectID==-1)
			{
				_dependentObjects.erase(_dependentObjects.begin()+i);
				_dependentSubObjects.erase(_dependentSubObjects.begin()+i);
				i--; // we have to reprocess this position!
			}
			else
			{
				if (subObjectID==_dependentSubObjects[i])
				{
					_dependentObjects.erase(_dependentObjects.begin()+i);
					_dependentSubObjects.erase(_dependentSubObjects.begin()+i);
					i--; // we have to reprocess this position!
				}
			}
		}
	}
	return(_dependentObjects.size()==0);
}

void CTextureObject::transferDependenciesToThere(CTextureObject* receivingObject)
{
	for (int i=0;i<int(_dependentObjects.size());i++)
		receivingObject->_dependentObjects.push_back(_dependentObjects[i]);
	for (int i=0;i<int(_dependentSubObjects.size());i++)
		receivingObject->_dependentSubObjects.push_back(_dependentSubObjects[i]);
	clearAllDependencies();
}


void CTextureObject::addDependentObject(int objectID,int subObjectID)
{
	_dependentObjects.push_back(objectID);
	_dependentSubObjects.push_back(subObjectID);
}

void CTextureObject::clearAllDependencies()
{
	_dependentObjects.clear();
	_dependentSubObjects.clear();
}

bool CTextureObject::isSame(CTextureObject* obj)
{
	if ( (obj->_textureSize[0]==_textureSize[0])&&(obj->_textureSize[1]==_textureSize[1]) )
	{
		if (obj->_providedImageWasRGBA!=_providedImageWasRGBA)
			return(false);
		for (int i=0;i<4*_textureSize[0]*_textureSize[1];i++)
		{
			if (obj->_textureBuffer[i]!=_textureBuffer[i])
				return(false);
		}
		return(true);
	}
	return(false);
}

void CTextureObject::setTextureBuffer(const std::vector<unsigned char>& tb)
{
	_textureBuffer.assign(tb.begin(),tb.end());
	_changedFlag=true;
}

void CTextureObject::getTextureBuffer(std::vector<unsigned char>& tb)
{
	tb.assign(_textureBuffer.begin(),_textureBuffer.end());
}

void CTextureObject::lightenUp()
{
	for (int i=0;i<int(_textureBuffer.size())/4;i++)
	{
		int avg=_textureBuffer[4*i+0];
		avg+=_textureBuffer[4*i+1];
		avg+=_textureBuffer[4*i+2];
		avg/=3;
		avg=128+avg/2;
		_textureBuffer[4*i+0]=avg;
		_textureBuffer[4*i+1]=avg;
		_textureBuffer[4*i+2]=avg;
	}
	/*
	// do some sort of contrast filter and shift all values upwards:
	std::vector<unsigned char> tmp(int(_textureBuffer.size())/4);
	for (int i=0;i<int(_textureBuffer.size())/4;i++)
	{
		int avg=_textureBuffer[4*i+0];
		avg+=_textureBuffer[4*i+1];
		avg+=_textureBuffer[4*i+2];
		avg/=3;
		tmp[i]=avg;
		_textureBuffer[4*i+0]=avg;
	}
	std::sort(tmp.begin(),tmp.end());
	unsigned char l0=tmp[tmp.size()/4];
	unsigned char l2=tmp[tmp.size()/2];
	unsigned char l3=tmp[3*tmp.size()/4];
	for (int i=0;i<int(_textureBuffer.size())/4;i++)
	{
		int v=_textureBuffer[4*i+0];
		if (v<=l0)
			v=160;
		else
		{
			if (v<=l2)
				v=192;
			else
			{
				if (v<=l3)
					v=224;
				else
					v=255;
			}
		}
		_textureBuffer[4*i+0]=v;
		_textureBuffer[4*i+1]=v;
		_textureBuffer[4*i+2]=v;
		_textureBuffer[4*i+3]=255;
	}
*/
	_changedFlag=true;
}

CTextureObject* CTextureObject::copyYourself()
{
	CTextureObject* newObj=new CTextureObject();
	newObj->_objectID=_objectID;
	newObj->_objectName=_objectName;

	newObj->_textureSize[0]=_textureSize[0];
	newObj->_textureSize[1]=_textureSize[1];

	newObj->_textureBuffer.assign(_textureBuffer.begin(),_textureBuffer.end());
	newObj->_providedImageWasRGBA=_providedImageWasRGBA;
	newObj->_changedFlag=true;

	newObj->_dependentObjects.assign(_dependentObjects.begin(),_dependentObjects.end());
	newObj->_dependentSubObjects.assign(_dependentSubObjects.begin(),_dependentSubObjects.end());

	return(newObj);
}

void CTextureObject::serialize(CSer& ar)
{
	if (ar.isStoring())
	{		// Storing
		ar.storeDataName("Ipa");
		ar << _objectID << _textureSize[0] << _textureSize[1];
		ar.flush();

		ar.storeDataName("Gon");
		ar << _objectName;
		ar.flush();

		ar.storeDataName("Bst");
		BYTE nothing=0;
		SIM_SET_CLEAR_BIT(nothing,0,_providedImageWasRGBA);
		ar << nothing;
		ar.flush();

		if (App::ct->undoBufferContainer->isUndoSavingOrRestoringUnderWay())
		{ // undo/redo serialization:
			ar.storeDataName("Img");
			ar << App::ct->undoBufferContainer->undoBufferArrays.addTextureBuffer(_textureBuffer,App::ct->undoBufferContainer->getNextBufferId());
			ar.flush();
		}
		else
		{ // normal serialization
			ar.storeDataName("Img");
			for (int i=0;i<_textureSize[0]*_textureSize[1];i++)
			{
				ar << _textureBuffer[4*i+0];
				ar << _textureBuffer[4*i+1];
				ar << _textureBuffer[4*i+2];
				if (_providedImageWasRGBA)
					ar << _textureBuffer[4*i+3];
			}
			ar.flush();
		}

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
				if (theName.compare("Ipa")==0)
				{
					noHit=false;
					ar >> byteQuantity;
					ar >> _objectID >> _textureSize[0] >> _textureSize[1];
				}
				if (theName.compare("Gon")==0)
				{
					noHit=false;
					ar >> byteQuantity;
					ar >> _objectName;
				}
				if (theName=="Bst")
				{
					noHit=false;
					ar >> byteQuantity;
					BYTE nothing;
					ar >> nothing;
					_providedImageWasRGBA=SIM_IS_BIT_SET(nothing,0);
				}
				if (App::ct->undoBufferContainer->isUndoSavingOrRestoringUnderWay())
				{ // undo/redo serialization
					if (theName.compare("Img")==0)
					{
						noHit=false;
						ar >> byteQuantity;
						int id;
						ar >> id;
						App::ct->undoBufferContainer->undoBufferArrays.getTextureBuffer(id,_textureBuffer);
					}
				}
				else
				{ // normal serialization
					if (theName=="Img")
					{
						noHit=false;
						ar >> byteQuantity;
						_textureBuffer.resize(4*_textureSize[0]*_textureSize[1],0);
						for (int i=0;i<_textureSize[0]*_textureSize[1];i++)
						{
							ar >> _textureBuffer[4*i+0];
							ar >> _textureBuffer[4*i+1];
							ar >> _textureBuffer[4*i+2];
							if (_providedImageWasRGBA)
								ar >> _textureBuffer[4*i+3];
							else
								_textureBuffer[4*i+3]=255;
						}
						_changedFlag=true;
					}
				}
				if (noHit)
					ar.loadUnknownData();
			}
		}
	}
}
