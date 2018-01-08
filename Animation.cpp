#include "Animation.h"



void Animation::setDefaultScene()
{
	scene_ = Scene::getDefaultScene();
}

Animation::Animation():OpenGlWindow(), renderer_(*this, Camera() ), scene_()
{}

void Animation::render()
{
	renderer_.render(scene_);
}




Animation::~Animation()
{}
