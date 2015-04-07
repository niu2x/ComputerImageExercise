// BShape.cpp: implementation of the BShape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "曲线和曲面的大杂烩.h"
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

}

BShape::~BShape()
{

}

void BShape::Init()
{
	pointDrawedNumber = 0;
}
void BShape::LButtonDown(CPoint p)
{
	if(!IsDone())
	{
		points[pointDrawedNumber ++] = p; 
	}
}
bool BShape::IsDone()
{
	return pointDrawedNumber >= 4;
}
void BShape::Draw(CDC *pDC)
{
	if(IsDone())
	{
	/*	int i = 0;
		int j = 1;

		i = 0;
		j = 1;
		if(points[2].y < points[i].y && points[2].y < points[j].y)
		{
			if(points[i].y < points[j].y)
			{
				j = 2;
			}
			else
			{
				i = 2;
			}
		}
		else if(points[2].y < points[j].y)
		{
			j = 2;
		}
		else if(points[2].y < points[i].y)
		{
			i = 2;
		}
		if(points[3].y < points[i].y && points[3].y < points[j].y)
		{
			if(points[i].y < points[j].y)
			{
				j = 3;
			}
			else
			{
				i = 3;
			}
		}
		else if(points[3].y < points[j].y)
		{
			j = 3;
		}
		else if(points[3].y < points[i].y)
		{
			i = 3;
		}
		pDC -> MoveTo(points[i]);
		pDC -> LineTo(points[j]);

		i = 0;
		j = 1;
		if(points[2].y > points[i].y && points[2].y > points[j].y)
		{
			if(points[i].y > points[j].y)
			{
				j = 2;
			}
			else
			{
				i = 2;
			}
		}
		else if(points[2].y > points[j].y)
		{
			j = 2;
		}
		else if(points[2].y > points[i].y)
		{
			i = 2;
		}
		if(points[3].y > points[i].y && points[3].y > points[j].y)
		{
			if(points[i].y > points[j].y)
			{
				j = 3;
			}
			else
			{
				i = 3;
			}
		}
		else if(points[3].y > points[j].y)
		{
			j = 3;
		}
		else if(points[3].y > points[i].y)
		{
			i = 3;
		}
		pDC -> MoveTo(points[i]);
		pDC -> LineTo(points[j]);

		i = 0;
		j = 1;
		if(points[2].x < points[i].x && points[2].x < points[j].x)
		{
			if(points[i].x < points[j].x)
			{
				j = 2;
			}
			else
			{
				i = 2;
			}
		}
		else if(points[2].x < points[j].x)
		{
			j = 2;
		}
		else if(points[2].x < points[i].x)
		{
			i = 2;
		}
		if(points[3].x < points[i].x && points[3].x < points[j].x)
		{
			if(points[i].x < points[j].x)
			{
				j = 3;
			}
			else
			{
				i = 3;
			}
		}
		else if(points[3].x < points[j].x)
		{
			j = 3;
		}
		else if(points[3].x < points[i].x)
		{
			i = 3;
		}
		pDC -> MoveTo(points[i]);
		pDC -> LineTo(points[j]);

		i = 0;
		j = 1;
		if(points[2].x > points[i].x && points[2].x > points[j].x)
		{
			if(points[i].x > points[j].x)
			{
				j = 2;
			}
			else
			{
				i = 2;
			}
		}
		else if(points[2].x > points[j].x)
		{
			j = 2;
		}
		else if(points[2].x > points[i].x)
		{
			i = 2;
		}
		if(points[3].x > points[i].x && points[3].x > points[j].x)
		{
			if(points[i].x > points[j].x)
			{
				j = 3;
			}
			else
			{
				i = 3;
			}
		}
		else if(points[3].x > points[j].x)
		{
			j = 3;
		}
		else if(points[3].x > points[i].x)
		{
			i = 3;
		}
		pDC -> MoveTo(points[i]);
		pDC -> LineTo(points[j]);*/

		pDC -> MoveTo(points[0]);
		pDC -> LineTo(points[1]);
		pDC -> LineTo(points[2]);
		pDC -> LineTo(points[3]);

		HPEN pen = CreatePen(2, 2, 0xff0000);
		HPEN old = (HPEN)SelectObject (pDC->m_hDC ,pen);

		pDC -> MoveTo(B3(points[0], points[1], points[2], points[3], 0));
		for(float t = 0; t <= 1.0f; t += 0.001f)
		{
			pDC -> LineTo(B3(points[0], points[1], points[2], points[3], t));
		}
		SelectObject (pDC->m_hDC ,old);
		DeleteObject(pen);
	}
	else
	{
		for(int i = 0; i < pointDrawedNumber; i ++)
		{
			pDC -> Ellipse(points[i].x - 5, points[i].y - 5, points[i].x + 5, points[i].y + 5); 
		}
	}
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
