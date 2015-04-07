// HermiteShape1.cpp: implementation of the HermiteShape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "曲线和曲面的大杂烩.h"
#include "HermiteShape1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HermiteShape::HermiteShape()
{

}

HermiteShape::~HermiteShape()
{

}

void HermiteShape::Init()
{
	counter = 0;
}
void HermiteShape::LButtonDown(CPoint p)
{
	switch(counter)
	{
	case 0:
		p0 = p;
		counter ++;
		break;
	case 1:
		p00 = p;
		counter ++;
		break;
	case 2:
		p1 = p;
		counter ++;
		break;
	case 3:
		p11 = p;
		counter ++;
		break;
	}
}
bool HermiteShape::IsDone()
{
	return counter >= 4;
}

void HermiteShape::drawHelper(CDC *pDC, int n)
{
		switch(n)
		{
		case 1:
			pDC -> Ellipse(p0.x - 5, p0.y - 5, p0.x + 5, p0.y + 5);
			break;
		case 2:
			pDC -> Ellipse(p0.x - 5, p0.y - 5, p0.x + 5, p0.y + 5);
			pDC -> Ellipse(p00.x - 5, p00.y - 5, p00.x + 5, p00.y + 5);
			pDC -> MoveTo(p0);
			pDC -> LineTo(p00);
			break;
		case 3:
			pDC -> Ellipse(p0.x - 5, p0.y - 5, p0.x + 5, p0.y + 5);
			pDC -> Ellipse(p00.x - 5, p00.y - 5, p00.x + 5, p00.y + 5);
			pDC -> Ellipse(p1.x - 5, p1.y - 5, p1.x + 5, p1.y + 5);
			pDC -> MoveTo(p0);
			pDC -> LineTo(p00);
	
			break;
		case 4:
			pDC -> Ellipse(p0.x - 5, p0.y - 5, p0.x + 5, p0.y + 5);
			pDC -> Ellipse(p00.x - 5, p00.y - 5, p00.x + 5, p00.y + 5);
			pDC -> Ellipse(p1.x - 5, p1.y - 5, p1.x + 5, p1.y + 5);
			pDC -> Ellipse(p11.x - 5, p11.y - 5, p11.x + 5, p11.y + 5);
			pDC -> MoveTo(p0);
			pDC -> LineTo(p00);
			pDC -> MoveTo(p1);
			pDC -> LineTo(p11);
			break;
		}
}
void HermiteShape::Draw(CDC *pDC)
{
	if(IsDone())
	{
		drawHelper(pDC, counter);
		
		HPEN pen = CreatePen(2, 2, 0xff0000);
		HPEN old = (HPEN)SelectObject (pDC->m_hDC ,pen);

		pDC -> MoveTo(Hermit(0));
		for(float t = 0; t <= 1; t += 0.001f)
		{
			pDC -> LineTo(Hermit(t));
		}
		SelectObject (pDC->m_hDC ,old);
		DeleteObject(pen);
	}
	else
	{
		drawHelper(pDC, counter);
	}
}

CPoint HermiteShape::Hermit (float t)
{
	CPoint p0__ = CPoint(p00.x - p0.x, p00.y - p0.y);
	CPoint p1__ = CPoint(p11.x - p1.x, p11.y - p1.y);
	CPoint ret;
	ret.x = p0.x*(2*t*t*t - 3*t*t + 1) + p1.x*(-2*t*t*t + 3*t*t) + p0__.x*(t*t*t - 2*t*t + t) +p1__.x*(t*t*t - t*t);
	ret.y = p0.y*(2*t*t*t - 3*t*t + 1) + p1.y*(-2*t*t*t + 3*t*t) + p0__.y*(t*t*t - 2*t*t + t) +p1__.y*(t*t*t - t*t);
	return ret;
}
