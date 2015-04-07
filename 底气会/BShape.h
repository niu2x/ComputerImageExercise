// BShape.h: interface for the BShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BSHAPE_H__FF524443_6B9B_43BD_98BF_852F01C4395B__INCLUDED_)
#define AFX_BSHAPE_H__FF524443_6B9B_43BD_98BF_852F01C4395B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "shape.h"
#include <vector>
#include "camera.h"

class BShape:public Shape  
{
	typedef std::vector<CPoint> PointGrp;
	PointGrp points;
	bool done;
	int mode;
	Camera camera;
	CPoint mousePos;
	void drawUT(CDC*);
	void drawMode0(CDC*);
	void drawMode1(CDC*);
	void drawMode2(CDC*);

	CPoint B3(CPoint, CPoint, CPoint, CPoint, float);
	CPoint B2(CPoint, CPoint, CPoint, float);
	CPoint B1(CPoint, CPoint, float);
	void drawB3Shape(CPoint, CPoint, CPoint, CPoint, CDC*, unsigned int color);
	void drawB3Shape3D(CPoint, CPoint, CPoint, CPoint, CDC*, unsigned int color);
public:
	BShape();
	virtual ~BShape();
	virtual void Init();
	virtual void LButtonDown(CPoint);
	virtual void LButtonDoubleDown(CPoint);
	virtual void MouseMove(CPoint);
	virtual bool IsDone();
	virtual void Draw(CDC*);
	virtual void SetMode(int);
};

#endif // !defined(AFX_BSHAPE_H__FF524443_6B9B_43BD_98BF_852F01C4395B__INCLUDED_)
