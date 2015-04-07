// Line.h: interface for the Line class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__FC4BA1D2_18C9_455D_8539_A3B6BF5920D9__INCLUDED_)
#define AFX_LINE_H__FC4BA1D2_18C9_455D_8539_A3B6BF5920D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"
#include "Point3D.h"
#include "Camera.h"

class Line : public Shape  
{
public:
	Point3D A;
	Point3D B;

	bool flag; //Ìø¹ý¶Ëµã
public:
	Line();
	Line(const Point3D &a, const Point3D &b):A(a), B(b){}
	virtual ~Line();
	virtual void Draw(CDC*, Camera*, unsigned int);
};

#endif // !defined(AFX_LINE_H__FC4BA1D2_18C9_455D_8539_A3B6BF5920D9__INCLUDED_)
