#pragma once
#include "Actor.h"


class Box :
	public Actor
{
public:
	Box();
	Box(const Box &other);
	Box(const std::vector<Vertex> &base, GLfloat height);
	
	virtual std::unique_ptr<Actor> clone()const;
	virtual ~Box();
protected:
	virtual void countAndSetVertsAndIndices(const std::vector<Vertex> &base, const GLfloat height);

};

