#include "Animation.h"



void Animation::setDefaultScene()
{
	scene_ = Scene::getDefaultScene();
}

Animation::Animation():OpenGlWindow(), renderer_(*this, Camera() ), scene_()
{}

void Animation::reactOnEvents()
{
	if (isKeyPressed(GLFW_KEY_W))
		moveForward();
	if (isKeyPressed(GLFW_KEY_A))
		moveLeft();
	if (isKeyPressed(GLFW_KEY_D))
		moveRight();
	if (isKeyPressed(GLFW_KEY_S))
		moveBackward();
}

void Animation::render()
{
	renderer_.render(scene_);
}

void Animation::moveForward()
{
	renderer_.moveCameraForward();
}

void Animation::moveBackward()
{
	renderer_.moveCameraBackward();
}

void Animation::moveRight()
{
	renderer_.moveCameraRight();
}

void Animation::moveLeft()
{
	renderer_.moveCameraLeft();
}




Animation::~Animation()
{}
