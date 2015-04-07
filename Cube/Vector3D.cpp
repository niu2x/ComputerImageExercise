// Vector3D.cpp: implementation of the Vector3D class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Cube.h"
#include "Vector3D.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Vector3D::Vector3D(float i, float j, float k):i(i), j(j), k(k)
{

}

Vector3D::~Vector3D()
{

}
