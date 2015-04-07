// InnerRound.cpp: implementation of the InnerRound class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "多边形变形.h"
#include "InnerRound.h"
#include <math.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

InnerRound::InnerRound()
{

}

InnerRound::~InnerRound()
{

}

void InnerRound::Init ()
{
	isDone = false;

}

bool InnerRound::IsDone()
{
	return isDone;
}

void InnerRound::LButtonDown(CPoint p)
{
	points.push_back(p);
	flags.push_back(1);
}

void InnerRound::LButtonDoubleDown(CPoint p)
{
//	points.push_back(p);
	isDone = true;
}

void InnerRound::Draw(CDC* pDC)
{
	if(isDone)
	{
		drawPolygonFrame(pDC);

		drawInnerRound(pDC);
	}
	else
	{
		for(int i = 0; i < (int)points.size() - 1; i ++)
		{
			pDC -> MoveTo(points[i]);
			pDC -> LineTo(points[i + 1]);
		}
		if(points.size() > 0)
		{
			pDC -> MoveTo(points[points.size() - 1]);
			pDC -> LineTo(mousePos);
		}
	}
}

void InnerRound::MouseMove (CPoint p)
{
	mousePos = p;
}

void InnerRound::drawPolygonFrame(CDC* pDC)
{
	for(int i = 0; i < (int)points.size() ; i ++)
	{
		pDC -> MoveTo(points[i]);
		pDC -> LineTo(points[(i + 1)%points.size()]);
	}
}

void InnerRound::drawInnerRound (CDC *pDC)
{
	if(points.size() >= 3)
	{	
		HPEN pen = CreatePen(2, 2, 0xff);
		HPEN old = (HPEN)SelectObject (pDC->m_hDC ,pen);

		for(int i = 0; i < (int)points.size() ; i ++)
		{
			CPoint a = points[i];
			CPoint b = points[(i+1)%points.size()];
			CPoint c = points[(i+2)%points.size()];

			a = CPoint((a.x+b.x)/2, (a.y+b.y)/2);
			c = CPoint((c.x+b.x)/2, (c.y+b.y)/2);

			draw2Bezier(pDC, a, b, c);
		}

		SelectObject (pDC->m_hDC ,old);
		DeleteObject(pen);
	}
}

bool enoughNear(CPoint a, CPoint b, CPoint d)
{

	float A = a.y - d.y;
	float B = d.x - a.x;
	float C = a.y*(a.x-d.x)-a.x*(a.y-d.y);

	float l1 = fabs(A*b.x + B*b.y + C)/sqrt(A*A+B*B);

	return l1 < 1;
}

void InnerRound::draw2Bezier(CDC *pDC, CPoint a, CPoint b, CPoint c)
{
	if(enoughNear(a,b,c))
	{
		pDC -> MoveTo(a);
		pDC -> LineTo(c);
	}
	else
	{
		CPoint ab = CPoint((a.x + b.x)/2, (a.y + b.y)/2);
		CPoint bc = CPoint((c.x + b.x)/2, (c.y + b.y)/2);
		CPoint abbc = CPoint((bc.x + ab.x)/2, (bc.y + ab.y)/2);


		draw2Bezier(pDC, a, ab, abbc);
		draw2Bezier(pDC, abbc, bc, c);
	}
}

void InnerRound::Move(CRect rect)
{
		for(int i = 0; i < (int)points.size() ; i ++)
		{
			if(points[i].x < 0 || points[i].y < 0 || points[i].x >= rect.right || points[i].y >= rect.bottom)
			{
				flags[i] = -flags[i];
			}
			if(points[i].x < 0)
			{
				points[i].x = 0;
			}
			if(points[i].y < 0)
			{
				points[i].y = 0;
			}
			if(points[i].x >= rect.right)
			{
				points[i].x = rect.right - 1;
			}
			if(points[i].y >= rect.bottom)
			{
				points[i].y = rect.bottom - 1;
			}

			if((i+1) % 2)
			{
				points[i].x += (1+i) * 3 * flags[i];
			}
			else
			{
				points[i].y += (1+i) * 3 * flags[i];
			}
		}
}