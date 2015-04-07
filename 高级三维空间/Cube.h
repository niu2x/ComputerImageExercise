// Cube.h: interface for the Cube class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CUBE_H__E016A354_6D76_48A0_954D_3D4287B952E8__INCLUDED_)
#define AFX_CUBE_H__E016A354_6D76_48A0_954D_3D4287B952E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"
#include "Plane.h"

class Cube : public Shape  
{
	Plane planes[12];
public:
	Cube();
	virtual ~Cube();
	virtual void Draw(CDC*, Camera *, unsigned int);

};

#endif // !defined(AFX_CUBE_H__E016A354_6D76_48A0_954D_3D4287B952E8__INCLUDED_)
