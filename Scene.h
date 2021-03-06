#pragma once
#include <memory>
#include <list>
#include "Actor.h"
#include "Camera.h"
#include "Box.h"
#include "Rectangle.h"
#include "Cylinder.h"
#include "Train.h"
#include "Skybox.h"
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

	void incrementRotationOfActor(int actor_nr);
	void decrementRotationOfActor(int actor_nr);

	void renderActors();

	virtual ~Scene();
};

