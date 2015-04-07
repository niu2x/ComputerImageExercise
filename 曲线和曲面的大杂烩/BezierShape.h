// BezierShape.h: interface for the BezierShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BEZIERSHAPE_H__4BE10ECB_89B2_4BE0_8D11_1793309ED4E6__INCLUDED_)
#define AFX_BEZIERSHAPE_H__4BE10ECB_89B2_4BE0_8D11_1793309ED4E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"

class BezierShape : public Shape  
{
	int pointDrawedNumber;
	CPoint points[4];

	void draw(CPoint a, CPoint b, CPoint c, CPoint d, CDC *);
	bool enoughNear(CPoint a, CPoint b, CPoint c, CPoint d);
public:
	BezierShape();
	virtual ~BezierShape();

	virtual void Init();
	virtual void LButtonDown(CPoint);
	virtual bool IsDone();
	virtual void Draw(CDC *);

};

#endif // !defined(AFX_BEZIERSHAPE_H__4BE10ECB_89B2_4BE0_8D11_1793309ED4E6__INCLUDED_)
