// amera.cpp: implementation of the Camera class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Cube.h"
#include "Camera.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Camera::Camera()
{
	type = T_POINT;
	pos = Point3D(1000, 0, 0);
	front = Vector3D(1, 0, 0);
	calcUpAndSide();
}

Camera::~Camera()
{

}

void Camera::SetPos (const Point3D &new_pos)
{
	pos = new_pos;
	light = front;
}

void Camera::SetFront (const Vector3D &new_front)
{
	front = new_front.Normalize ();
	calcUpAndSide();
	light = front;
}

void Camera::SetLight (const Vector3D &new_light)
{
	light = new_light.Normalize ();
}

Matrix Camera::Get ()
{
	if(type == T_POINT)
	{
		Matrix mat = Matrix::Unit (4);
		mat = mat * Matrix::Transform3D (-pos.x, -pos.y, -pos.z);
		mat = mat * Matrix::Vector2Z (front.i, front.j, front.k);         
		Point3D pPoint(up.i + pos.x, up.j + pos.y, up.k + pos.z);

		Matrix newUpH = Matrix::HomogeneousCoordinate3D (pPoint.x, pPoint.y, pPoint.z) * mat;
		Point3D newUp(newUpH(1,1)/newUpH(1,4), newUpH(1,2)/newUpH(1,4), 0);
		Vector3D upVector = Vector3D(newUp.x, newUp.y, 0);
		mat = mat * Matrix::Vector2Y (upVector.i, upVector.j, upVector.k);
	
		mat = mat * Matrix::ProjectionPointZ (1);

		return mat;
	}
	if(type == T_PINGXING)
	{
		Matrix mat = Matrix::Unit (4);
		mat = mat * Matrix::Transform3D (-pos.x, -pos.y, -pos.z);
		mat = mat * Matrix::Vector2Z (front.i, front.j, front.k);

		Point3D pPoint(up.i + pos.x, up.j + pos.y, up.k + pos.z);
		Matrix newUpH = Matrix::HomogeneousCoordinate3D (pPoint.x, pPoint.y, pPoint.z) * mat;
		Point3D newUp(newUpH(1,1)/newUpH(1,4), newUpH(1,2)/newUpH(1,4), 0);
		Vector3D upVector = Vector3D(newUp.x, newUp.y, 0);
		mat = mat * Matrix::Vector2Y (upVector.i, upVector.j, upVector.k);

		Matrix now_light_m = Matrix::HomogeneousCoordinate3D (light.i + pos.x, light.j + pos.y, light.k + pos.z) * mat;
		Vector3D now_light = Vector3D(now_light_m(1,1)/now_light_m(1,4), now_light_m(1,2)/now_light_m(1,4), now_light_m(1,3)/now_light_m(1,4));
	
		mat = mat * Matrix::ProjectionPingXingZ (now_light.i, now_light.j, now_light.k);

		//
		Matrix now_up_m = Matrix::HomogeneousCoordinate3D (up.i + pos.x, light.j + pos.y, up.k + pos.z) * mat;
		Vector3D now_up = Vector3D(now_up_m(1,1)/now_up_m(1,4), now_up_m(1,2)/now_up_m(1,4), now_up_m(1,3)/now_up_m(1,4));
		//
		return mat;
	}
}

void Camera::calcUpAndSide ()
{
	if(front.k < 0)
	{
		up.i = front.i;
		up.j = front.j;
		up.k = (- front.i*up.i - front.j*up.j)/front.k;
		up=up.Normalize ();
	}
	else if(front.k > 0)
	{
		up.i = -front.i;
		up.j = -front.j;
		up.k = (- front.i*up.i - front.j*up.j)/front.k;
		up=up.Normalize ();
	}
	else
	{
		up = Vector3D(0, 0, 1);
	}

	side.i = front.j * up.k - front.k * up.j;
	side.j = front.k * up.i - front.i * up.k;
	side.k = front.i * up.j - front.j * up.i;
}