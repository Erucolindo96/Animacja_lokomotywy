#pragma once
#include <memory>
#include <list>
#include "Actor.h"
#include "Camera.h"
#include "Box.h"
#include "Rectangle.h"
class Scene
{
protected:
	friend class Renderer;


	std::vector < std::unique_ptr<Actor> > actors;
	GLuint shader_id_;
	void setShaderIdToActors();

public:
	Scene();
	Scene(const Scene &other);
	Scene& operator=(const Scene& other);

	void setActor(const Actor &act);
	std::unique_ptr<Actor>& getActorReference(int number);
	void setShaderId(GLuint id);
	static Scene getDefaultScene();

	void renderActors();

	
	/*
	void setWidth(GLfloat width);
	GLfloat getWidth()const;
	void setHeight(GLfloat height);
	GLfloat getHeight()const;

	void setViewAngle(GLfloat v_angle);
	GLfloat getViewAngle()const;
*/



	virtual ~Scene();
};

