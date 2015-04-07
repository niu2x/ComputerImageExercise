// Shape.h: interface for the Shape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHAPE_H__EE25702C_3166_4394_B834_ED39386AB7FE__INCLUDED_)
#define AFX_SHAPE_H__EE25702C_3166_4394_B834_ED39386AB7FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Shape  
{
public:
	Shape();
	virtual ~Shape();

	virtual void Init() = 0;
	virtual void LButtonDown(CPoint) = 0;
	virtual void LButtonDoubleDown(CPoint) = 0;
	virtual void MouseMove(CPoint) = 0;
	virtual bool IsDone() = 0;
	virtual void Draw(CDC*) = 0;
};

#endif // !defined(AFX_SHAPE_H__EE25702C_3166_4394_B834_ED39386AB7FE__INCLUDED_)
