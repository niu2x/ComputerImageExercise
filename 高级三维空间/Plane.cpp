// Plane.cpp: implementation of the Plane class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "高级三维空间.h"
#include "Plane.h"
#include "Vector3D.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Plane::Plane()
{

}

Plane::~Plane()
{

}

Plane::Plane(const Point3D &a, const Point3D &b, const Point3D &c):A(a), B(b), C(c)
{
}

void Plane::Draw (CDC *pDC, Camera *camera, unsigned int color)
{
	Matrix aa = Matrix::HomogeneousCoordinate3D (A.x, A.y, A.z) * transform;
	Matrix bb = Matrix::HomogeneousCoordinate3D (B.x, B.y, B.z) * transform;
	Matrix cc = Matrix::HomogeneousCoordinate3D (C.x, C.y, C.z) * transform;

	Point3D aaa(aa(1,1)/aa(1,4), aa(1,2)/aa(1,4), aa(1,3)/aa(1,4));
	Point3D bbb(bb(1,1)/bb(1,4), bb(1,2)/bb(1,4), bb(1,3)/bb(1,4));
	Point3D ccc(cc(1,1)/cc(1,4), cc(1,2)/cc(1,4), cc(1,3)/cc(1,4));
	Line m(aaa,bbb);
	Line n(bbb,ccc);
	Line p(aaa,ccc);

	m.Draw(pDC, camera, color);
	n.Draw(pDC, camera, color);
	p.Draw(pDC, camera, color);


	Vector3D v1(bbb.x-aaa.x, bbb.y-aaa.y, bbb.z-aaa.z);
	Vector3D v2(ccc.x-aaa.x, ccc.y-aaa.y, ccc.z-aaa.z);
	
	if(v1.Length () > v2.Length ())
	{
		v1 = v1 / v2.Length();
		v2 = v2.Normalize();
	}
	else
	{
		v2 = v2 / v1.Length();
		v1 = v1.Normalize();
	}

	Point3D bbbb(aaa);
	Point3D cccc(aaa);
	while(true)
	{
		if(fabs(bbbb.x-bbb.x)<4.f && fabs(bbbb.y-bbb.y)<4.f && fabs(bbbb.z-bbb.z)<4.f)
		{
			if(fabs(cccc.x-ccc.x)<4.f && fabs(cccc.y-ccc.y)<4.f && fabs(cccc.z-ccc.z)<4.f)
			{
				break;
			}
		}

		bbbb.MoveBy (v1.i, v1.j, v1.k);
		cccc.MoveBy (v2.i, v2.j, v2.k);

		Line scan_line(bbbb, cccc);
		scan_line.flag = true;
		scan_line.Draw(pDC, camera, 0xffffff);
	}
}