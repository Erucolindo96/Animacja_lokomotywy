#pragma once
#include <memory>
#include <list>
#include "Actor.h"

class Scene
{
protected:
	friend class Renderer;

	std::list < std::unique_ptr<Actor> > actors;
public:
	Scene();
	void setActor(const Actor &act);

	virtual ~Scene();
};

