// Vector3D.h: interface for the Vector3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR3D_H__6B9F5B9D_893D_4308_8227_2366DD474B12__INCLUDED_)
#define AFX_VECTOR3D_H__6B9F5B9D_893D_4308_8227_2366DD474B12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <math.h>
class Vector3D  
{
public:
	float i;
	float j;
	float k;
	Vector3D(float = 0, float = 0, float = 0);
	virtual ~Vector3D();
	
	Vector3D operator+ (const Vector3D & it) const
	{
		return Vector3D(i+it.i, j+it.j, k+it.k);
	}
	Vector3D operator- (const Vector3D & it) const
	{
		return Vector3D(i-it.i, j-it.j, k-it.k);
	}
	Vector3D operator/ (float s) const
	{
		return Vector3D(i/s, j/s, k/s);
	}

	Vector3D Normalize() const
	{
		if(i == 0 && j == 0 && k == 0) return Vector3D(0, 0, 0);
		float len = sqrt(i*i + j*j + k*k);
		return Vector3D(i / len, j / len, k / len);
	}

	float Length()const
	{
		return sqrt(i*i + j*j + k*k);
	}
};

#endif // !defined(AFX_VECTOR3D_H__6B9F5B9D_893D_4308_8227_2366DD474B12__INCLUDED_)
