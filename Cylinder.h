#pragma once
#include "Actor.h"
class Cylinder :
	public Actor
{


public:
	static const GLuint CIRCLE_VERTS_COUNT = 20;
	Cylinder();
	Cylinder(const Cylinder &other);
	Cylinder(const GLfloat r, const GLfloat h, const std::string texture_path, const GLuint verts_count = CIRCLE_VERTS_COUNT);

	virtual std::unique_ptr<Actor> clone()const;
	virtual ~Cylinder();
protected:

	virtual void countAndSetVertsAndIndices(const GLfloat r, const GLfloat h, GLuint sides);

	
};

