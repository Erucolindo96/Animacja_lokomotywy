#pragma once
#include "Actor.h"


class Box :
	public Actor
{
public:
	Box();
	Box(const Box &other);
	Box& operator=(const Box &other);
	Box(const GLfloat x_length, const GLfloat y_length, const GLfloat z_length, const std::string &texture_path);
	
	virtual std::unique_ptr<Actor> clone()const;
	virtual ~Box();
protected:

	virtual void setTextureCoordinate();
	virtual void countAndSetVertsAndIndices(const GLfloat x_length, const GLfloat y_length, const GLfloat z_length);


	


};

