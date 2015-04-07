// Shape.cpp: implementation of the Shape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Shape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Shape::Shape():transform(Matrix::Unit (4))
{
	
}

Shape::~Shape()
{

}


void Shape::MoveBy(const Vector3D &d)
{
	transform = transform * Matrix::Transform3D (d.i, d.j, d.k);
}
void Shape::RotationX(float angle)
{
	transform = transform * Matrix::Rotation3DX (angle);
}
void Shape::RotationY(float angle)
{
	transform = transform * Matrix::Rotation3DY (angle);
}

void Shape::RotationZ(float angle)
{
	transform = transform * Matrix::Rotation3DZ (angle);
}
void Shape::Zoom(float k)
{
	transform = transform * Matrix::Zoom3D (k, k, k);
}

