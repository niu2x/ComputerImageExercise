// HermiteShape1.h: interface for the HermiteShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HERMITESHAPE1_H__A47A9D78_3456_407D_8FE5_DDB2DD71A6EF__INCLUDED_)
#define AFX_HERMITESHAPE1_H__A47A9D78_3456_407D_8FE5_DDB2DD71A6EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"

class HermiteShape : public Shape  
{
	CPoint p0;
	CPoint p00;
	CPoint p1;
	CPoint p11;

	int counter;

	void drawHelper(CDC *,int);

	CPoint Hermit(float);
public:
	HermiteShape();
	virtual ~HermiteShape();

	virtual void Init();
	virtual void LButtonDown(CPoint);
	virtual bool IsDone();
	virtual void Draw(CDC *);
};

#endif // !defined(AFX_HERMITESHAPE1_H__A47A9D78_3456_407D_8FE5_DDB2DD71A6EF__INCLUDED_)
