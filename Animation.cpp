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

	if (isKeyPressed(GLFW_KEY_UP))
		moveUp();
	if (isKeyPressed(GLFW_KEY_DOWN))
		moveDown();
	
	if (isKeyPressed(GLFW_KEY_Q))
		incrementVelocity();
	if (isKeyPressed(GLFW_KEY_R))
		decrementVelocity();
}

void Animation::render()
{
	incrementRotationOfTrainWeels();
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

void Animation::moveUp()
{
	renderer_.moveCameraUp();
}

void Animation::moveDown()
{
	renderer_.moveCameraDown();
}

void Animation::incrementRotationOfTrainWeels()
{
	scene_.incrementRotationOfActor(TRAIN_ID);
}

void Animation::decrementRotationOfTrainWeels()
{
	scene_.decrementRotationOfActor(TRAIN_ID);
}

void Animation::incrementVelocity()
{
	auto &train = scene_.getActorReference(TRAIN_ID);
	train->incrementRotationIncrementVelocity();
}

void Animation::decrementVelocity()
{
	auto &train = scene_.getActorReference(TRAIN_ID);
	train->decrementRotationIncrementVelocity();
}




Animation::~Animation()
{}
