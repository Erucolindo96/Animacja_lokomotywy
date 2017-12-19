#include "Scene.h"



Scene::Scene()
{
}

void Scene::setActor(const Actor & act)
{
	actors.push_back(act.clone());
}


Scene::~Scene()
{
}
