// Point3D.cpp: implementation of the Point3D class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Point3D.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Point3D::Point3D(float x, float y, float z):x(x), y(y), z(z)
{

}

Point3D::~Point3D()
{

}

void Point3D::MoveBy (float dx, float dy, float dz)
{
	x += dx;
	y += dy;
	z += dz;
}