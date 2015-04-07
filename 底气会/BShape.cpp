// BShape.cpp: implementation of the BShape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "µ×Æø»á.h"
#include "BShape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BShape::BShape()
{
	camera.SetPos(Point3D(1500, 1500, 0));
	camera.SetFront(Vector3D(-1, -1, 0));
	camera.SetLight(Vector3D(-1,-1,0));
	camera.SetType(Camera::T_PINGXING);
}

BShape::~BShape()
{

}

void BShape::Init ()
{
	points.clear();
	done = false;
	mode = 0;
}

bool BShape::IsDone()
{
	return done;
}

void BShape::LButtonDown (CPoint p)
{
	points.push_back(p);
}

void BShape::LButtonDoubleDown (CPoint p)
{
	if(points.size() >= 2)
	{
		//CPoint first(2*points[0].x - points[1].x, 2*points[0].y - points[1].y);
		//points.insert(points.begin(), first);
		
		//CPoint last(2*points[points.size() - 1].x - points[points.size() - 2].x, 2*points[points.size() - 1].y - points[points.size() - 2].y);
		//points.insert(points.end(), last);

		points.insert(points.begin(), points[0]);
		points.insert(points.begin(), points[0]);

		points.insert(points.end(), points[points.size() - 1]);
		points.insert(points.end(), points[points.size() - 1]);
	}
	done = true;
}

void BShape::SetMode (int m)
{
	mode = m;
}

void BShape::MouseMove (CPoint p)
{
	mousePos = p;
}

void BShape::Draw(CDC *pDC)
{
	if(IsDone())
	{
		switch(mode)
		{
		case 0:
			drawMode0(pDC);
			break;
		case 1:
			drawMode1(pDC);
			break;
		case 2:
			drawMode2(pDC);
			break;
		}
	}
	else
	{
		drawUT(pDC);
	}
}

void BShape::drawB3Shape(CPoint a, CPoint b , CPoint c, CPoint d, CDC *pDC, unsigned int color)
{
	HPEN pen = CreatePen(2, 3, color);
	HPEN old = (HPEN)SelectObject (pDC->m_hDC ,pen);

	pDC -> MoveTo(B3(a,b,c,d,0));
	for(float t = 0; t <= 1; t += 0.02f)
	{
		pDC -> LineTo(B3(a,b,c,d,t));
	}

	SelectObject(pDC->m_hDC, old);
	DeleteObject(pen);
}

CPoint BShape::B3(CPoint a, CPoint b, CPoint c, CPoint d, float t)
{
	CPoint m(a.x*(1-t)/3.0f+b.x*(t+2)/3.0f, a.y*(1-t)/3.0f+b.y*(t+2)/3.0f);
	CPoint n(b.x*(2-t)/3.0f+c.x*(t+1)/3.0f, b.y*(2-t)/3.0f+c.y*(t+1)/3.0f);
	CPoint p(c.x*(3-t)/3.0f+d.x*(t)/3.0f, c.y*(3-t)/3.0f+d.y*(t)/3.0f);
	return B2(m,n,p,t);
}
CPoint BShape::B2(CPoint a, CPoint b, CPoint c, float t)
{
	CPoint m(a.x*(1-t)/2.0f+b.x*(t+1)/2.0f, a.y*(1-t)/2.0f+b.y*(t+1)/2.0f);
	CPoint n(b.x*(2-t)/2.0f+c.x*(t)/2.0f, b.y*(2-t)/2.0f+c.y*(t)/2.0f);
	return B1(m,n,t);
}
CPoint BShape::B1(CPoint a, CPoint b, float t)
{
	return CPoint((1-t)*a.x + t*b.x, (1-t)*a.y + t*b.y);
}

void BShape::drawMode0 (CDC *pDC)
{
	for(int i = 1; i < (int)points.size() - 2; i ++)
	{
		pDC -> MoveTo(points[i]);
		pDC -> LineTo(points[i+1]);
	}
	
	
	if(points.size() >= 4)
	{
		unsigned int color[3] = {0xff0000, 0x00ff00, 0x0000ff};
		for(int i = 0; i < points.size() - 3; i ++)
		{
			drawB3Shape(points[i], points[i+1], points[i+2], points[i+3], pDC, color[i%3]);
		}
	}
}
void BShape::drawMode1 (CDC *pDC)
{
	if(points.size() >= 4)
	{
		unsigned int color[3] = {0xff0000, 0x00ff00, 0x0000ff};
		for(int i = 0; i < points.size() - 3; i ++)
		{
			drawB3Shape(points[i], points[i+1], points[i+2], points[i+3], pDC, color[i%3]);
		}

		for(i = 0; i < points.size() - 3; i ++)
		{
			CPoint a = CPoint(2*points[1].x - points[i].x, points[i].y);
			CPoint b = CPoint(2*points[1].x - points[i+1].x, points[i+1].y);
			CPoint c = CPoint(2*points[1].x - points[i+2].x, points[i+2].y);
			CPoint d = CPoint(2*points[1].x - points[i+3].x, points[i+3].y);
			drawB3Shape(a, b, c, d, pDC, color[i%3]);
		}
	}
}
void BShape::drawMode2 (CDC *pDC)
{
	if(points.size() >= 4)
	{
		unsigned int color[3] = {0xff0000, 0x00ff00, 0x0000ff};
		for(int i = 0; i < points.size() - 3; i ++)
		{
			drawB3Shape3D(points[i], points[i+1], points[i+2], points[i+3], pDC, color[i%3]);
		}
	}
}

void BShape::drawB3Shape3D(CPoint a, CPoint b, CPoint c, CPoint d, CDC *pDC, unsigned int color)
{
	HPEN pen = CreatePen(2, 3, color);
	HPEN old = (HPEN)SelectObject (pDC->m_hDC ,pen);

	a.x -= points[1].x;
	b.x -= points[1].x;
	c.x -= points[1].x;
	d.x -= points[1].x;

	const int n = 50 + 1;
	float delta = 1.0f / (n - 1);
	CPoint keyPoints[n];
	
	int i = 0;
	for(float t = 0; t <= 1; t += delta, i ++)
	{
		keyPoints[i] = B3(a,b,c,d,t);
	}

	Point3D keyPoints3D[n];

	for(i = 0; i < n; i ++)
	{
		keyPoints3D[i].x = keyPoints[i].x;
		keyPoints3D[i].y = 0;
		keyPoints3D[i].z = keyPoints[i].y;
	}

	for(float angle = 0; angle < 360; angle += 30)
	{
		for(int i = 0; i < n; i ++)
		{
			Matrix mat = Matrix::HomogeneousCoordinate3D (keyPoints3D[i].x, keyPoints3D[i].y, keyPoints3D[i].z) * Matrix::Rotation3DZ (3.1415926*30/180.0f); 
			keyPoints3D[i].x = mat(1,1)/mat(1,4);
			keyPoints3D[i].y = mat(1,2)/mat(1,4);
			keyPoints3D[i].z = mat(1,3)/mat(1,4);
		}

		Matrix mat = camera.Get();

		for(i = 0; i < n; i ++)
		{
			Matrix ty = Matrix::HomogeneousCoordinate3D (keyPoints3D[i].x, keyPoints3D[i].y, keyPoints3D[i].z) * mat;
			Point3D p = Point3D(ty(1,1)/ty(1,4), ty(1,2)/ty(1,4), 0);
			p.x *= -1;
			p.y *= 1;

			p.x += points[1].x;
			p.y += 0;

			if(i == 0)
			{
				pDC -> MoveTo(CPoint(p.x, p.y));
			}
			else
			{
				pDC -> LineTo(CPoint(p.x, p.y));
			}
		}
	}

	SelectObject(pDC->m_hDC, old);
	DeleteObject(pen);
}

void BShape::drawUT (CDC *pDC)
{
	for(int i = 0; i < (int)points.size() - 1; i ++)
	{
		pDC -> MoveTo(points[i]);
		pDC -> LineTo(points[i+1]);
	}
	if((int)points.size() > 0)
	{
		pDC -> MoveTo(points[points.size() - 1]);
		pDC -> LineTo(mousePos);
	}
}