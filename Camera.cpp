#include "Camera.h"



Camera::Camera():position_(0.0, 0.0, 0.0), target_(1.0, 0.0, 0.0), up_(0.0, 1.0, 0.0)
{

}

Camera::Camera(glm::vec3 target): Camera()
{
	setDefaultPosition();
	target_ = target;
}
Camera::Camera(const Camera & other):position_(other.position_), target_(other.target_), up_(other.up_)
{}
Camera & Camera::operator=(const Camera & other)
{
	if (&other == this)
		return *this;
	position_ = other.position_;
	target_ = other.target_;
	up_ = other.up_;
	return *this;

	// TODO: insert return statement here
}
/*
void Camera::setVerticalAngle(GLfloat angle)
{
	vAngle_ = angle;
}

GLfloat Camera::getVerticalAngle() const
{
	return vAngle_;
}

void Camera::setHorizontalAngle(GLfloat angle)
{
	hAngle_ = angle;
}

GLfloat Camera::getHorizontalAngle() const
{
	return hAngle_;
}

void Camera::setDistance(GLfloat dis)
{
	distance_ = dis;
}

GLfloat Camera::getDistance() const
{
	return distance_;
}
*/
void Camera::setTarget(const glm::vec3 &target)
{
	target_ = target;
}

glm::vec3 Camera::getTarget() const
{
	return target_;
}

void Camera::setPosition(const glm::vec3 &pos)
{
	position_ = pos;
	
}

glm::vec3 Camera::getPosition() const
{
	return position_;
}

void Camera::setUp(const glm::vec3 &up)
{
	up_ = up;
}

glm::vec3 Camera::getUp() const
{
	return glm::vec3(up_);
}

void Camera::setDefaultPosition()
{
	position_ = { -1.0, 0.0, 0.0 };
	target_ = { 1.0, 0.0, 0.0 };
	up_ = { 0.0, 1.0, 0.0 };

}
glm::mat4 Camera::getViewMatrix() const
{
	//return glm::mat4(1.0);
	//TODO
	return glm::lookAt(position_, target_, up_); 
}
void Camera::moveForward()
{
	position_ += DELTA * glm::normalize(target_);
}
void Camera::moveBackward()
{
	position_ -= DELTA* glm::normalize(target_);
}
void Camera::moveRight()
{
	position_ += DELTA * glm::normalize(glm::cross(target_, up_));
}
void Camera::moveLeft()
{
	position_ -= DELTA * glm::normalize(glm::cross(target_, up_));
}
/*
void Camera::incrementHorizontalAngle()
{
	hAngle_ += DELTA;
}

void Camera::incrementVerticalAngle()
{
	if (vAngle_ < MAX_VERTICAL)
		vAngle_ += DELTA;
}

void Camera::decrementHorizontalAngle()
{
	hAngle_ -= DELTA;
}

void Camera::decrementVerticalAngle()
{
	if (vAngle_ > MIN_VERTICAL)
		vAngle_ -= DELTA;
}

void Camera::incrementDistance()
{
	if (distance_ < MAX_DIS)
		distance_ += DELTA;
}

void Camera::decrementDistance()
{
	if (distance_ > MIN_DIS)
		distance_ -= DELTA;
}
*/

Camera::~Camera()
{
}
