// BezierPlaneShape.cpp: implementation of the BezierPlaneShape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "曲线和曲面的大杂烩.h"
#include "BezierPlaneShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include <math.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BezierPlaneShape::BezierPlaneShape()
{

}

BezierPlaneShape::~BezierPlaneShape()
{

}

void BezierPlaneShape::Init()
{
	points[0][0] = Point3D(0, 0, 0);
	points[0][1] = Point3D(2, 0, 3);
	points[0][2] = Point3D(4, 0, 0);
	points[0][3] = Point3D(6, 0, 3);

	points[1][0] = Point3D(0, 2, 0);
	points[1][1] = Point3D(2, 2, 3);
	points[1][2] = Point3D(4, 2, 0);
	points[1][3] = Point3D(6, 2, 3);

	points[2][0] = Point3D(0, 4, 0);
	points[2][1] = Point3D(2, 4, 3);
	points[2][2] = Point3D(4, 4, 0);
	points[2][3] = Point3D(6, 4, 3);

	points[3][0] = Point3D(0, 6, 0);
	points[3][1] = Point3D(2, 6, 3);
	points[3][2] = Point3D(4, 6, 0);
	points[3][3] = Point3D(6, 6, 3);

/*	points[0][0] = Point3D(0, 0, 0);
	points[0][1] = Point3D(1, 0, 0);
	points[0][2] = Point3D(2, 0, 0);
	points[0][3] = Point3D(3, 0, 0);

	points[1][0] = Point3D(0, 1, 0);
	points[1][1] = Point3D(1, 1, 0);
	points[1][2] = Point3D(2, 1, 0);
	points[1][3] = Point3D(3, 1, 0);

	points[2][0] = Point3D(0, 2, 0);
	points[2][1] = Point3D(1, 2, 0);
	points[2][2] = Point3D(2, 2, 0);
	points[2][3] = Point3D(3, 2, 0);

	points[3][0] = Point3D(0, 3, 0);
	points[3][1] = Point3D(1, 3, 0);
	points[3][2] = Point3D(2, 3, 0);
	points[3][3] = Point3D(3, 3, 0);*/

	/*points[0][0] = Point3D(-18, -18, 0);
	points[0][1] = Point3D(-18, -6, 2);
	points[0][2] = Point3D(-18, 6, 2);
	points[0][3] = Point3D(-18, 18, 0);

	points[1][0] = Point3D(-6, -18, 4);
	points[1][1] = Point3D(-6, -6, 6);
	points[1][2] = Point3D(-6, 6, 6);
	points[1][3] = Point3D(-6, 18, 4);

	points[2][0] = Point3D(6, -18, 4);
	points[2][1] = Point3D(6, -6, 6);
	points[2][2] = Point3D(6, 6, 6);
	points[2][3] = Point3D(6, 18, 4);

	points[3][0] = Point3D(18, -18, 0);
	points[3][1] = Point3D(18, -6, 2);
	points[3][2] = Point3D(18, 6, 2);
	points[3][3] = Point3D(18, 18, 0);*/

	camera.SetType(Camera::T_POINT);
	camera.SetPos(Point3D(20,20,20));
	camera.SetFront(Vector3D(-1,-1,-1));
}
void BezierPlaneShape::LButtonDown(CPoint)
{}
bool BezierPlaneShape::IsDone()
{
	return true;
}
void BezierPlaneShape::Draw(CDC *pDC)
{
	if(IsDone())
	{
		HPEN pen = CreatePen(2, 2, 0xff0000);
		HPEN old = (HPEN)SelectObject (pDC->m_hDC ,pen);
		float delta = 0.05f;
		for(float u = 0; u <= 1; u += delta)
		{
			for(float v = 0; v <= 1; v += delta)
			{
				Point3D ret = calc(u, v);

				if(u > 0)
				{
					Point3D other = calc(u - delta, v);
					pDC -> MoveTo(To2D(ret));
					pDC -> LineTo(To2D(other));
				}
				if(v > 0)
				{
					Point3D other = calc(u, v - delta);
					pDC -> MoveTo(To2D(ret));
					pDC -> LineTo(To2D(other));
				}
				if(u < 1)
				{
					Point3D other = calc(u + delta, v);
					pDC -> MoveTo(To2D(ret));
					pDC -> LineTo(To2D(other));
				}
				if(v < 1)
				{
					Point3D other = calc(u , v + delta);
					pDC -> MoveTo(To2D(ret));
					pDC -> LineTo(To2D(other));
				}
			}
		}
		SelectObject(pDC->m_hDC ,old);
		DeleteObject(pen);

		for(int i = 0; i < 4; i ++)
		{
			for(int j = 0; j < 4; j ++)
			{
				pDC -> MoveTo(To2D(points[i][j]));
				if(i>0) pDC -> LineTo(To2D(points[i-1][j]));
				pDC -> MoveTo(To2D(points[i][j]));
				if(j>0) pDC -> LineTo(To2D(points[i][j-1]));
				pDC -> MoveTo(To2D(points[i][j]));
				if(i<3) pDC -> LineTo(To2D(points[i+1][j]));
				pDC -> MoveTo(To2D(points[i][j]));
				if(j<3) pDC -> LineTo(To2D(points[i][j+1]));
			}
		}
	}
}

int jieCheng(int n)
{
	if(n <= 1)
	{
		return 1;
	}
	else
	{
		return n*jieCheng(n-1);
	}
}
int C(int n, int i)
{
	return jieCheng(n)/jieCheng(i)/jieCheng(n-i);	
}
Point3D BezierPlaneShape::calc (float u, float v)
{
	Point3D ret(0, 0, 0);
	for(int i = 0; i < 4; i ++)
	{
		for(int j = 0; j < 4; j ++)
		{
			ret.x += points[i][j].x * pow(u, i) * pow(1-u, 3-i) * C(3, i) * pow(v, j) * pow(1-v, 3-j) * C(3, j);
			ret.y += points[i][j].y * pow(u, i) * pow(1-u, 3-i) * C(3, i) * pow(v, j) * pow(1-v, 3-j) * C(3, j);
			ret.z += points[i][j].z * pow(u, i) * pow(1-u, 3-i) * C(3, i) * pow(v, j) * pow(1-v, 3-j) * C(3, j);
		}
	}
	return ret;
}

CPoint BezierPlaneShape::To2D (Point3D point)
{
	Matrix mat = Matrix::HomogeneousCoordinate3D (point.x, point.y, point.z) * camera.Get ();
	float x = mat(1,1)/mat(1,4);
	float y = mat(1,2)/mat(1,4);

	return CPoint(-x*1000 + 500, -y*1000 + 300);
}