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
	const std::string TEX_PATH = "..\\Animacja_lokomotywy\\textures\\wood.jpg", TEX_PATH2 = "..\\Animacja_lokomotywy\\textures\\kon_srokaty1.jpg";
	//teraz defaultowa scena skladac sie bedzie z prostopadlosciany w srodku ekranu
	Scene ret_scene;
	/*
	Vertex v1(glm::vec3({0.25, 0, 0.25 }),  glm::vec3({0,0,0}), glm::vec2({0,0})), v2(v1), v3(v1), v4(v1);
	v2.position_ = {0.25, 0, -0.25 };
	v3.position_ = {-0.25, 0, -0.25 };
	v3.color_ = { 0.7, 0.6, 0.6 };
	v4.position_ = { -0.25,  0 , 0.25 };
	std::vector<Vertex> verts;
	verts.push_back(v1);
	verts.push_back(v2);
	verts.push_back(v3);
	verts.push_back(v4); 
	*/
	Box b(2, 2, 2, TEX_PATH );
	//Box drugi(verts, 0.4);
	b.setTranslation({ 3, -2, 3 } );
	b.setRotation({1.0, 0.0, 0.0}, glm::radians(45.0));
	Cylinder c(1,1, TEX_PATH);
	c.setTranslation({ 0.3, 0.2, -0.3 });
	ret_scene.setActor(b);
	//ret_scene.setActor(drugi);
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
