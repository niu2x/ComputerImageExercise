// Plane.h: interface for the Plane class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANE_H__7A963B0D_B2E3_469A_B29D_F15D49C76AF4__INCLUDED_)
#define AFX_PLANE_H__7A963B0D_B2E3_469A_B29D_F15D49C76AF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"
#include "Line.h"

class Plane : public Shape  
{
	Point3D A;
	Point3D B;
	Point3D C;
public:
	Plane();
	Plane(const Point3D &a, const Point3D &b, const Point3D &c);
	virtual void Draw(CDC *, Camera *, unsigned int);
	virtual ~Plane();

};

#endif // !defined(AFX_PLANE_H__7A963B0D_B2E3_469A_B29D_F15D49C76AF4__INCLUDED_)
