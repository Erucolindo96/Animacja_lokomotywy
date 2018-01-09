#pragma once
#include "Actor.h"
class Cylinder :
	public Actor
{


public:
	Cylinder();
	Cylinder(const Cylinder &other);
	Cylinder(const std::vector<Vertex> &sign_square_verts, const GLfloat height);

	virtual std::unique_ptr<Actor> clone()const;
	virtual ~Cylinder();
protected:
	virtual void countAndSetVertsAndIndices(std::vector<Vertex> &&base, const GLfloat height);
	std::vector<Vertex> countCylinderBase(const std::vector<Vertex> &sign_square_verts, const Vertex center_vertex);
};

