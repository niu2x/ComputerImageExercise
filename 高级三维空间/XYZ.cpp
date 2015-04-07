// XYZ.cpp: implementation of the XYZ class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "高级三维空间.h"
#include "XYZ.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XYZ::XYZ():x(Point3D(0, 0, 0),Point3D(500, 0, 0)),y(Point3D(0, 0, 0),Point3D(0, 500, 0)),z(Point3D(0, 0, 0), Point3D(0, 0, 500))
{
}

XYZ::~XYZ()
{

}
void XYZ::Draw(CDC *pDC,Camera *camera, unsigned int color)
{
	x.Draw(pDC, camera, color);
	y.Draw(pDC, camera, color);
	z.Draw(pDC, camera, color);

	Point3D xx = x.B;
	Point3D yy = y.B;
	Point3D zz = z.B;

	Point3D xxx = camera->World2Screen (Matrix::HomogeneousCoordinate3D (xx.x, xx.y, xx.z) * camera->Get ());
	Point3D yyy = camera->World2Screen (Matrix::HomogeneousCoordinate3D (yy.x, yy.y, yy.z) * camera->Get ());
	Point3D zzz = camera->World2Screen (Matrix::HomogeneousCoordinate3D (zz.x, zz.y, zz.z) * camera->Get ());

	pDC->TextOut (xxx.x, xxx.y, "X");
	pDC->TextOut (yyy.x, yyy.y, "Y");
	pDC->TextOut (zzz.x, zzz.y, "Z");
}
