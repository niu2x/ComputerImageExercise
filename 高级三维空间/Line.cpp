// Line.cpp: implementation of the Line class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "高级三维空间.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

static float depth[2000][2000];
void BeginScene()
{
	for(int i = 0; i < 2000; i ++)
	{
		for(int j = 0; j < 2000; j ++)
		{
			depth[i][j] = 1000000.0f;
		}
	}
}
void EndScene()
{
}

Line::Line()
{
	flag = false;
}

Line::~Line()
{

}

void DrawLine (CDC *pDC, const Point3D &a, const Point3D &b, unsigned int, bool);

void Line::Draw (CDC *pDC, Camera *camera, unsigned int color)
{
	Matrix a = Matrix::HomogeneousCoordinate3D (A.x, A.y, A.z) * transform;
	Matrix b = Matrix::HomogeneousCoordinate3D (B.x, B.y, B.z) * transform;

	if(camera->CullLine (&a, &b))
	{
		Matrix mat = camera->Get ();

		Matrix aa = a * mat;
		Matrix bb = b * mat;

		Point3D aaa = camera->World2Screen (aa);
		Point3D bbb = camera->World2Screen (bb);

		Matrix __a = a*camera->Get2();
		Matrix __b = b*camera->Get2();

		aaa.z = __a(1,3)/__a(1,4);
		bbb.z = __b(1,3)/__b(1,4);

		DrawLine(pDC, aaa, bbb, color, flag);
	}
}

void DrawLine (CDC *pDC, const Point3D &a, const Point3D &b, unsigned int color, bool flag)
{
	int x1 = a.x;
	int y1 = a.y;

	int x2 = b.x;
	int y2 = b.y;

	int FlipY = 0;
	int Flip45 = 0;

	if(x1 > x2)
	{
		int temp = x1;
		x1 = x2;
		x2 = temp;

		temp = y2;
		y2 = y1;
		y1 = temp;
	}

	int dx = x2 - x1;
	int dy = y2 - y1;

	if(dy < 0)
	{
		FlipY = 1;
		dy = -dy;
		y1 = -y1;
		y2 = -y2;
	}

	if(dy > dx)
	{
		int temp = dx;
		dx = dy;
		dy = temp;
		temp = x1;
		x1 = y1;
		y1 = temp;
		temp = y2;
		y2 = x2;
		x2 = temp;	
		Flip45 = 1;
	}

	int x = x1;
	int y = y1;

	int d = dy + dy - dx;

	int deltaPostive = d - dx;
	int delteNegative = dy + dy; 

	CPoint point;

	
	int flag_value = 0;
	if(flag)
	{
		x+=4;
		flag_value = 4;
	}
	while(x <= x2 - flag_value)
	{
		point.x = x;
		point.y = y;
		if(Flip45)
		{
			int temp = point.x;
			point.x = point.y;
			point.y = temp;
		}
		if(FlipY)
		{
			point.y = -point.y;
		}

		float z;
		if(fabs(b.x - a.x )>=1.f)
		{
			z = (point.x - a.x)*(b.z - a.z)/(b.x - a.x) + a.z;
		}
		else if(fabs(b.y - a.y )>=1.f)
		{
			z = (point.y - a.y)*(b.z - a.z)/(b.y - a.y) + a.z;
		}
		else
		{
			z = (a.z > b.z)?b.z:a.z;
		}

		if(point.y >=0 && point.y < 2000 && point.x >=0 && point.x < 2000)
		{
			if(z < depth[point.y][point.x])
			{
				depth[point.y][point.x] = z;
				pDC->SetPixel(point, color);
			}
		}

		if(d >= 0)
		{
			d += deltaPostive;
			++ x;
			++ y;
		}
		else
		{
			d += delteNegative;
			++ x;
		}
	}
}