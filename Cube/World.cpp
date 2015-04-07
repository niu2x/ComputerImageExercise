// World.cpp: implementation of the World class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Cube.h"
#include "World.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define safe_delete(p) if(p) delete p; p = 0;
#include "myCube.h"

World::World()
{
	camera = new Camera();
	camera->SetPos (Point3D(1000, 1000, 1000));
	camera->SetFront (Vector3D(-1, -1, -1));

	AddShape(new Cube());

}	

World::~World()
{
	safe_delete(camera);
	for(std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it ++)
	{
		safe_delete(*it);
	}
}

void World::AddShape (Shape *shape)
{
	shapes.push_back(shape);
}

void World::Draw (CDC *pDC)
{
	drawXYZ(pDC);
	for(std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it ++)
	{
		(*it)->Draw(pDC, camera);
	}
}

void World::drawXYZ (CDC *pDC)
{
	Matrix TouYing = camera->Get ();

	Matrix AA = Matrix::HomogeneousCoordinate3D (0,		0,		0);
	Matrix BB = Matrix::HomogeneousCoordinate3D (500,	0,		0);
	Matrix CC = Matrix::HomogeneousCoordinate3D (0,		500,	0);
	Matrix DD = Matrix::HomogeneousCoordinate3D (0,		0,		500);
	

	Matrix A_TouYing = AA * TouYing;
	Matrix B_TouYing = BB * TouYing;
	Matrix C_TouYing = CC * TouYing;
	Matrix D_TouYing = DD * TouYing;


	Line(pDC, TYToClient(A_TouYing).x, TYToClient(A_TouYing).y, TYToClient(B_TouYing).x, TYToClient(B_TouYing).y);
	Line(pDC, TYToClient(A_TouYing).x, TYToClient(A_TouYing).y, TYToClient(C_TouYing).x, TYToClient(C_TouYing).y);
	Line(pDC, TYToClient(A_TouYing).x, TYToClient(A_TouYing).y, TYToClient(D_TouYing).x, TYToClient(D_TouYing).y);

	pDC->TextOut (TYToClient(B_TouYing).x, TYToClient(B_TouYing).y, "X");
	pDC->TextOut (TYToClient(C_TouYing).x, TYToClient(C_TouYing).y, "Y");
	pDC->TextOut (TYToClient(D_TouYing).x, TYToClient(D_TouYing).y, "Z");

	Point3D pos = camera->GetPos();
	char sz[256];
	if(camera->GetType() == Camera::T_PINGXING)
	{
		sprintf(sz,"投影面经过点:(%.2f, %.2f, %.2f)", pos.x, pos.y, pos.z);
	}
	else if(camera->GetType() == Camera::T_POINT)
	{
		sprintf(sz,"投影点位置:(%.2f, %.2f, %.2f)", pos.x, pos.y, pos.z);
	}
	pDC->TextOut (0,0,sz);

	Vector3D front = camera->GetFront ();
	sprintf(sz,"投影面法线方向:(%.2f, %.2f, %.2f)", front.i, front.j, front.k);
	pDC->TextOut (0,20,sz);

	if(camera->GetType() == Camera::T_PINGXING)
	{
		Vector3D light = camera->GetLight ();
		sprintf(sz,"光的方向:(%.2f, %.2f, %.2f)", light.i, light.j, light.k);
		pDC->TextOut (0,40,sz);
	}
}

Shape *World::GetShape (int n)
{
	return shapes[n];
}