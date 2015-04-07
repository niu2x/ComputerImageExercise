// MyPolygon.h: interface for the MyPolygon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYPOLYGON_H__DAB576BA_E994_4EE5_BE4D_57740F19F4B4__INCLUDED_)
#define AFX_MYPOLYGON_H__DAB576BA_E994_4EE5_BE4D_57740F19F4B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>

class MyPolygon  
{
	static bool mask[1600][1600];
	CPoint GetPoint(int i, int n);
public:
	std::vector <CPoint> points;
	MyPolygon();
	virtual ~MyPolygon();
	void AddPoint(const CPoint &point);
	void Draw(CDC*);
	void Clear();
	static void Line(CDC *pDC, const CPoint &a, const CPoint &b);
	static void Fill(CDC *, int id, int width, int height);
	static void ClearMask();
	void Mask(const CPoint &a, const CPoint &b);
};

#endif // !defined(AFX_MYPOLYGON_H__DAB576BA_E994_4EE5_BE4D_57740F19F4B4__INCLUDED_)
