// BezierPlaneShape.h: interface for the BezierPlaneShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BEZIERPLANESHAPE_H__97D67B31_2233_4589_91F5_29943E4342F7__INCLUDED_)
#define AFX_BEZIERPLANESHAPE_H__97D67B31_2233_4589_91F5_29943E4342F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"
#include "Point3D.h"
#include "Camera.h"

class BezierPlaneShape : public Shape  
{
	Camera camera;
	Point3D points[4][4];
	Point3D calc(float u, float v);
	CPoint  To2D(Point3D);
public:
	BezierPlaneShape();
	virtual ~BezierPlaneShape();
	virtual void Init();
	virtual void LButtonDown(CPoint);
	virtual bool IsDone();
	virtual void Draw(CDC *);
};

#endif // !defined(AFX_BEZIERPLANESHAPE_H__97D67B31_2233_4589_91F5_29943E4342F7__INCLUDED_)
