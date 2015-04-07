// Cube.cpp: implementation of the Cube class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "高级三维空间.h"
#include "Cube.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Cube::Cube()
{
	Point3D a(0, 0, 0);
	Point3D b(100, 0, 0);
	Point3D c(100, 100, 0);
	Point3D d(0, 100, 0);
	Point3D e(0, 0, 100);
	Point3D f(100, 0, 100);
	Point3D g(100, 100, 100);
	Point3D h(0, 100, 100);

	planes[0] = Plane(a,b,c);
	planes[1] = Plane(a,d,c);

	planes[2] = Plane(a,e,f);
	planes[3] = Plane(a,b,f);

	planes[4] = Plane(d,g,c);
	planes[5] = Plane(d,g,h);

	planes[6] = Plane(f,b,g);
	planes[7] = Plane(g,b,c);

	planes[8] = Plane(a,d,e);
	planes[9] = Plane(h,d,e);

	planes[10] = Plane(f,h,e);
	planes[11] = Plane(f,h,g);

}

Cube::~Cube()
{

}

void Cube::Draw(CDC *pDC, Camera *camera, unsigned int col)
{
	for(int i = 0; i < 12; i ++)
	{
		planes[i].Draw(pDC, camera, 0xff);
	}
}