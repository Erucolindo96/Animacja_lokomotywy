#pragma once
#include "Actor.h"
class Rectangle :
	public Actor
{
public:

	Rectangle(const GLfloat x_length, const GLfloat z_length, const GLfloat height, const std::string & texture_path);
	Rectangle(const Rectangle &other);
	virtual ~Rectangle();
	virtual std::unique_ptr<Actor> clone()const;

protected:
	Rectangle();


};

