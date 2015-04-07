// BShape.h: interface for the BShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BSHAPE_H__9D33DBCF_4951_4D43_9D51_948309A3E069__INCLUDED_)
#define AFX_BSHAPE_H__9D33DBCF_4951_4D43_9D51_948309A3E069__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"
class BShape : public Shape  
{
	CPoint points[4];
	int pointDrawedNumber;
	CPoint B3(CPoint a, CPoint b, CPoint c, CPoint d, float t);
	CPoint B2(CPoint a, CPoint b, CPoint c, float t);
	CPoint B1(CPoint a, CPoint b, float t);
public:
	BShape();
	virtual ~BShape();

	virtual void Init();
	virtual void LButtonDown(CPoint);
	virtual bool IsDone();
	virtual void Draw(CDC *);
};

#endif // !defined(AFX_BSHAPE_H__9D33DBCF_4951_4D43_9D51_948309A3E069__INCLUDED_)
