#pragma once
#include "Actor.h"
class Rectangle :
	public Actor
{
public:

	Rectangle(std::vector<Vertex> verts);
	Rectangle(const Rectangle &other);
	virtual ~Rectangle();
	virtual std::unique_ptr<Actor> clone()const;

protected:
	Rectangle();


};

