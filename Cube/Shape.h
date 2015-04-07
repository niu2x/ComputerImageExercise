// Shape.h: interface for the Shape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHAPE_H__F179DE99_8361_43F7_99BE_DD7AD9A08D2A__INCLUDED_)
#define AFX_SHAPE_H__F179DE99_8361_43F7_99BE_DD7AD9A08D2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Camera.h"
#include "Matrix.h"
#include "Vector3D.h"
class Shape  
{
public:
	Shape();
	virtual ~Shape();
	virtual void Draw(CDC*, Camera*)=0;

	virtual void MoveBy(const Vector3D &) = 0;
	virtual void RotationX(float)=0;
	virtual void RotationY(float)=0;
	virtual void RotationZ(float)=0;
	virtual void Zoom(float)=0;

};

void Line(CDC *pDC, float x1, float y1, float x2, float y2);
CPoint TYToClient(const Matrix &point);

#endif // !defined(AFX_SHAPE_H__F179DE99_8361_43F7_99BE_DD7AD9A08D2A__INCLUDED_)
