#include "Scene.h"



Scene::Scene()
{
}

Scene::Scene(const Scene & other)
{
	for each (auto &var in other.actors)
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
	//teraz defaultowa scena skladac sie bedzie z prostopadlosciany w srodku ekranu
	Scene ret_scene;
	Vertex v1(glm::vec3({0.25, 0, 0.25 }), glm::vec3({0.3,0.2,0.1}), glm::vec3({0,0,0}), glm::vec2({0,0})), v2(v1), v3(v1), v4(v1);
	v2.position_ = {0.25, 0 , -0.25 };
	v3.position_ = {-0.25, 0 , -0.25 };
	v3.color_ = { 0.7, 0.8, 0.9 };
	v4.position_ = { -0.25,  0, 0.25 };
	std::vector<Vertex> verts;
	verts.push_back(v1);
	verts.push_back(v2);
	verts.push_back(v3);
	verts.push_back(v4); 
	//Rectangle r(verts);
	Box b(verts, 0.25);
	b.setTranslation({ -0.25, 0.2, -0.25 } );
	//b.setRotation({0.0, 1.0, 0.0}, glm::radians(45.0));
	Cylinder c(verts, 0.2);
	c.setTranslation({ -0.3, -0.2, 0.0 });
	ret_scene.setActor(b);
	ret_scene.setActor(c);
	return ret_scene;
	
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
