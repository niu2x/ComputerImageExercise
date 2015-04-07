// Shape.cpp: implementation of the Shape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Cube.h"
#include "Shape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Shape::Shape()
{

}

Shape::~Shape()
{

}

void Line(CDC *pDC, float x1, float y1, float x2, float y2)
{
	pDC ->MoveTo (CPoint(x1, y1));
	pDC->LineTo (CPoint(x2, y2));
}

extern float ty_to_client_scale = 1300;
CPoint TYToClient(const Matrix &point)
{
	CPoint ret;
	ret.x = -point(1,1)/point(1,4)*ty_to_client_scale + 500;
	ret.y = -point(1,2)/point(1,4)*ty_to_client_scale + 400;
	return ret;
}
