// BezierShape.cpp: implementation of the BezierShape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "曲线和曲面的大杂烩.h"
#include "BezierShape.h"
#include <math.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BezierShape::BezierShape()
{
	pointDrawedNumber = 0;
}

BezierShape::~BezierShape()
{

}


void BezierShape::Init()
{
	pointDrawedNumber = 0;
}
void BezierShape::LButtonDown(CPoint point)
{
	if(!IsDone())
	{
		points[pointDrawedNumber] = point;
		pointDrawedNumber ++;
	}
}
bool BezierShape::IsDone()
{
	return pointDrawedNumber >= 4;
}
void BezierShape::Draw(CDC *pDC)
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
		draw(points[0], points[1], points[2], points[3], pDC);
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

CPoint MidPoint(CPoint a, CPoint b)
{
	return CPoint((a.x + b.x)/2, (a.y + b.y)/2);
}
void BezierShape::draw(CPoint a, CPoint b, CPoint c, CPoint d, CDC *pDC)
{
	if(enoughNear(a,b,c,d))
	{
		pDC -> MoveTo(a);
		pDC -> LineTo(d);
	}
	else
	{
		CPoint p[4];
		CPoint q[4];

		CPoint a1,a2,a3;
		CPoint b1,b2;
		CPoint c1;

		a1 = MidPoint(a, b);
		a2 = MidPoint(b, c);
		a3 = MidPoint(c, d);
		b1 = MidPoint(a1, a2);
		b2 = MidPoint(a2, a3);
		c1 = MidPoint(b1, b2);
	
		p[0] = a;
		p[1] = a1;
		p[2] = b1;
		p[3] = c1;
		q[0] = c1;
		q[1] = b2;
		q[2] = a3;
		q[3] = d;

		draw(p[0], p[1], p[2], p[3], pDC);
		draw(q[0], q[1], q[2], q[3], pDC);
	}
}

bool BezierShape::enoughNear(CPoint a, CPoint b, CPoint c, CPoint d)
{

	float A = a.y - d.y;
	float B = d.x - a.x;
	float C = a.y*(a.x-d.x)-a.x*(a.y-d.y);

	float l1 = fabs(A*b.x + B*b.y + C)/sqrt(A*A+B*B);
	float l2 = fabs(A*c.x + B*c.y + C)/sqrt(A*A+B*B);


	return l1 < 1 && l2 < 1;
}
