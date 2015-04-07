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
protected:
	Matrix transform;
public:
	Shape();
	virtual ~Shape();
	virtual void Draw(CDC*, Camera*, unsigned int)=0;
	void MoveBy(const Vector3D &);
	void RotationX(float);
	void RotationY(float);
	void RotationZ(float);
	void Zoom(float);

};

//CPoint TYToClient(const Matrix &point);

#endif // !defined(AFX_SHAPE_H__F179DE99_8361_43F7_99BE_DD7AD9A08D2A__INCLUDED_)
