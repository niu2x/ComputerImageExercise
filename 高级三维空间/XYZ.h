// XYZ.h: interface for the XYZ class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XYZ_H__2F8038A3_8560_4241_9359_4D3D03D4D0BE__INCLUDED_)
#define AFX_XYZ_H__2F8038A3_8560_4241_9359_4D3D03D4D0BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"
#include "Line.h"
class XYZ : public Shape  
{
	Line x,y,z;
public:
	XYZ();
	virtual ~XYZ();
	virtual void Draw(CDC *,Camera*, unsigned int);

};

#endif // !defined(AFX_XYZ_H__2F8038A3_8560_4241_9359_4D3D03D4D0BE__INCLUDED_)
