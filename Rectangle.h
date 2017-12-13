#pragma once
#include "Actor.h"
class Rectangle :
	public Actor
{
public:

	Rectangle(std::vector<Vertex> verts);
	virtual ~Rectangle();
protected:
	Rectangle();


};

