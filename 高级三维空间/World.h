// World.h: interface for the World class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORLD_H__09B98AED_1485_4FA2_8DF4_17AB80D2FF84__INCLUDED_)
#define AFX_WORLD_H__09B98AED_1485_4FA2_8DF4_17AB80D2FF84__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Camera.h"
#include <vector>
#include "Shape.h"
class World  
{
	Camera *camera;
	std::vector<Shape*> shapes;
public:
	World();
	virtual ~World();
	void Draw(CDC*);
	void AddShape(Shape*);
	Camera *GetCamera(){return camera;}
	Shape* GetShape(int);
};

#endif // !defined(AFX_WORLD_H__09B98AED_1485_4FA2_8DF4_17AB80D2FF84__INCLUDED_)
