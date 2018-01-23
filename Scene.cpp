#include "Scene.h"



Scene::Scene()
{
}

Scene::Scene(const Scene & other)
{
	for (auto &var : other.actors)
	{
		actors.push_back(var->clone());
	}
}

Scene & Scene::operator=(const Scene & other)
{
	if (&other == this)
		return *this;
	for (auto &my_act : actors)
	{
		my_act = nullptr;
	}
	for (auto &actor : other.actors)
	{
		actors.push_back(actor->clone());
	}
	setShaderId(other.shader_id_);
	return *this;
}

void Scene::setActor(const Actor & act)
{

	actors.push_back(act.clone());
	actors.back()->setShaderId(shader_id_);
//	(actors[actors.size - 1])->setShaderId(shader_id_);
}

std::unique_ptr<Actor>& Scene::getActorReference(int number)
{
	if (number < 0 || number >= actors.size())
		throw std::out_of_range("Scene::getActorReference - nie ma aktora o takim numerze");
	return actors.at(number);

}

void Scene::setShaderId(GLuint id)
{
	shader_id_ = id;
	setShaderIdToActors();
}

Scene Scene::getDefaultScene()
{
	const std::string TEX_PATH = "..\\Animacja_lokomotywy\\textures\\metal.jpg";
	Scene ret_scene;
	Train tr;
	Box szyna_lewa(1, 1, 1000, TEX_PATH), szyna_prawa(1, 1, 100, TEX_PATH);
	szyna_lewa.setDefaultTranslation({ 3, -5, 0 });
	szyna_prawa.setDefaultTranslation({ -3, -5, 0 });
	
	ret_scene.setActor(tr);
	ret_scene.setActor(szyna_lewa);
	ret_scene.setActor(szyna_prawa);
	return ret_scene;
	
}

void Scene::incrementRotationOfActor(int actor_nr)
{
	actors[actor_nr]->incrementRotationAngle();
}

void Scene::decrementRotationOfActor(int actor_nr)
{
	actors[actor_nr]->decrementRotationAngle();
}

void Scene::setShaderIdToActors()
{
	for (auto &act : actors)
	{
		act->setShaderId(shader_id_);
	}
}

void Scene::renderActors()
{
	for (auto &&act : actors)
	{
		act->draw();
	}
}


Scene::~Scene()
{
}
