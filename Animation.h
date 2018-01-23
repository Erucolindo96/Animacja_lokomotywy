#pragma once
#include "OpenGlWindow.h"
#include "Renderer.h"
class Animation :
	public OpenGlWindow
{

protected:
	Renderer renderer_;
	Scene scene_;
	const unsigned int TRAIN_ID=0;

	void incrementRotationOfTrainWeels();
	void decrementRotationOfTrainWeels();

	void incrementVelocity();
	void decrementVelocity();

public:
	Animation();
	void reactOnEvents();
	void render();
	void moveForward();
	void moveBackward();
	void moveRight();
	void moveLeft();


	void setDefaultScene();

	virtual ~Animation();
};

