// amera.h: interface for the Camera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AMERA_H__25F2A99B_F662_431F_840A_79C281DB2D4A__INCLUDED_)
#define AFX_AMERA_H__25F2A99B_F662_431F_840A_79C281DB2D4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Matrix.h"
#include "Point3D.h"
#include "Vector3D.h"
class Camera  
{
	Point3D pos;
	Vector3D front;
	Vector3D up;
	Vector3D side;
	Vector3D light; //only useful in T_PINGXING
	int type;
	void calcUpAndSide();
public:
	enum {T_PINGXING = 0, T_POINT};
	Camera();
	virtual ~Camera();
	Matrix Get();
	void SetPos(const Point3D &);
	void SetFront(const Vector3D &);
	void SetLight(const Vector3D &);

	Point3D GetPos()const{return pos;}
	Vector3D GetFront()const{return front;}
	Vector3D GetUp()const{return up;}
	Vector3D GetLight()const{return light;}
	Vector3D GetSide()const{return side;}
	void SetType(int newType){type = newType;}
	int GetType()const{return type;}
};

#endif // !defined(AFX_AMERA_H__25F2A99B_F662_431F_840A_79C281DB2D4A__INCLUDED_)
