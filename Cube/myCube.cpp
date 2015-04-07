// ube.cpp: implementation of the Cube class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Cube.h"
#include "myCube.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Cube::Cube():transform(Matrix::Unit (4))
{
	A = Point3D(0,0,0);
	B = Point3D(1,0,0);
	C = Point3D(1,1,0);
	D = Point3D(0,1,0);
	E = Point3D(0,0,1);
	F = Point3D(1,0,1);
	G = Point3D(1,1,1);
	H = Point3D(0,1,1);

	transform = Matrix::Zoom3D (100, 100, 100);
}

Cube::~Cube()
{

}

void Cube::Draw (CDC *pDC, Camera *camera)
{
	Matrix TouYing = camera->Get ();
	Matrix AA = Matrix::HomogeneousCoordinate3D (A.x, A.y, A.z);
	Matrix BB = Matrix::HomogeneousCoordinate3D (B.x, B.y, B.z);
	Matrix CC = Matrix::HomogeneousCoordinate3D (C.x, C.y, C.z);
	Matrix DD = Matrix::HomogeneousCoordinate3D (D.x, D.y, D.z);
	Matrix EE = Matrix::HomogeneousCoordinate3D (E.x, E.y, E.z);
	Matrix FF = Matrix::HomogeneousCoordinate3D (F.x, F.y, F.z);
	Matrix GG = Matrix::HomogeneousCoordinate3D (G.x, G.y, G.z);
	Matrix HH = Matrix::HomogeneousCoordinate3D (H.x, H.y, H.z);

	Matrix A_TouYing = AA * transform * TouYing;
	Matrix B_TouYing = BB * transform * TouYing;
	Matrix C_TouYing = CC * transform * TouYing;
	Matrix D_TouYing = DD * transform * TouYing;
	Matrix E_TouYing = EE * transform * TouYing;
	Matrix F_TouYing = FF * transform * TouYing;
	Matrix G_TouYing = GG * transform * TouYing;
	Matrix H_TouYing = HH * transform * TouYing;

	Line(pDC, TYToClient(A_TouYing).x, TYToClient(A_TouYing).y, TYToClient(B_TouYing).x, TYToClient(B_TouYing).y);
	Line(pDC, TYToClient(C_TouYing).x, TYToClient(C_TouYing).y, TYToClient(B_TouYing).x, TYToClient(B_TouYing).y);
	Line(pDC, TYToClient(C_TouYing).x, TYToClient(C_TouYing).y, TYToClient(D_TouYing).x, TYToClient(D_TouYing).y);
	Line(pDC, TYToClient(A_TouYing).x, TYToClient(A_TouYing).y, TYToClient(D_TouYing).x, TYToClient(D_TouYing).y);

	Line(pDC, TYToClient(E_TouYing).x, TYToClient(E_TouYing).y, TYToClient(F_TouYing).x, TYToClient(F_TouYing).y);
	Line(pDC, TYToClient(G_TouYing).x, TYToClient(G_TouYing).y, TYToClient(F_TouYing).x, TYToClient(F_TouYing).y);
	Line(pDC, TYToClient(G_TouYing).x, TYToClient(G_TouYing).y, TYToClient(H_TouYing).x, TYToClient(H_TouYing).y);
	Line(pDC, TYToClient(E_TouYing).x, TYToClient(E_TouYing).y, TYToClient(H_TouYing).x, TYToClient(H_TouYing).y);

	Line(pDC, TYToClient(A_TouYing).x, TYToClient(A_TouYing).y, TYToClient(E_TouYing).x, TYToClient(E_TouYing).y);
	Line(pDC, TYToClient(B_TouYing).x, TYToClient(B_TouYing).y, TYToClient(F_TouYing).x, TYToClient(F_TouYing).y);
	Line(pDC, TYToClient(C_TouYing).x, TYToClient(C_TouYing).y, TYToClient(G_TouYing).x, TYToClient(G_TouYing).y);
	Line(pDC, TYToClient(D_TouYing).x, TYToClient(D_TouYing).y, TYToClient(H_TouYing).x, TYToClient(H_TouYing).y);
}

void Cube::MoveBy (const Vector3D &delta)
{
	transform = transform * Matrix::Transform3D (delta.i, delta.j, delta.k);
}

void Cube::RotationX (float k)
{
	transform = transform * Matrix::Rotation3DX (k*0.1f);
}
void Cube::RotationY (float k)
{
	transform = transform * Matrix::Rotation3DY (k*0.1f);
}
void Cube::RotationZ (float k)
{
	transform = transform * Matrix::Rotation3DZ (k*0.1f);
}
void Cube::Zoom (float k)
{
	transform = transform * Matrix::Zoom3D (k, k, k);
}