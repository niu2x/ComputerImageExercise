// InnerRound.h: interface for the InnerRound class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INNERROUND_H__82CEFC60_7BB3_42B8_B948_037A1E657984__INCLUDED_)
#define AFX_INNERROUND_H__82CEFC60_7BB3_42B8_B948_037A1E657984__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"
#include <vector>
class InnerRound : public Shape  
{
	typedef std::vector<CPoint> PointGrp;
	PointGrp points;
	bool isDone;
	CPoint mousePos;

	void drawPolygonFrame(CDC *);
	void drawInnerRound(CDC *);
	void draw2Bezier(CDC *, CPoint a, CPoint b, CPoint c);

	std::vector<int> flags;
public:
	InnerRound();
	virtual ~InnerRound();
	virtual void Init();
	virtual void LButtonDown(CPoint);
	virtual void LButtonDoubleDown(CPoint);
	virtual void MouseMove(CPoint);
	virtual bool IsDone();
	virtual void Draw(CDC*);

	void Move(CRect);
};

#endif // !defined(AFX_INNERROUND_H__82CEFC60_7BB3_42B8_B948_037A1E657984__INCLUDED_)
