// Point3D.h: interface for the Point3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINT3D_H__08E47F9B_F26C_4E96_8895_31BB9E924E04__INCLUDED_)
#define AFX_POINT3D_H__08E47F9B_F26C_4E96_8895_31BB9E924E04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Point3D  
{
public:
	float x;
	float y;
	float z;
	Point3D(float x = 0, float y = 0, float z = 0);
	virtual ~Point3D();

	void MoveBy(float dx, float dy, float dz);
	void MoveTo(float x, float y, float z);
};

#endif // !defined(AFX_POINT3D_H__08E47F9B_F26C_4E96_8895_31BB9E924E04__INCLUDED_)
