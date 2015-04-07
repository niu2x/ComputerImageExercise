// ube.h: interface for the Cube class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UBE_H__54744189_649B_473B_8C69_26268C5B7AE3__INCLUDED_)
#define AFX_UBE_H__54744189_649B_473B_8C69_26268C5B7AE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Shape.h"
#include "Point3D.h"
#include "Matrix.h"
class Cube  :public Shape
{
	Point3D A;
	Point3D B;
	Point3D C;
	Point3D D;
	Point3D E;
	Point3D F;
	Point3D G;
	Point3D H;
	Matrix transform;
public:
	Cube();
	virtual ~Cube();
	virtual void Draw(CDC*, Camera *);
	virtual void MoveBy(const Vector3D &);
	virtual void RotationX(float);
	virtual void RotationY(float);
	virtual void RotationZ(float);
	virtual void Zoom(float);

};

#endif // !defined(AFX_UBE_H__54744189_649B_473B_8C69_26268C5B7AE3__INCLUDED_)
