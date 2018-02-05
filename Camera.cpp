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
}

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
	return glm::lookAt(position_, position_ + target_, up_); 
}
void Camera::moveForward()
{
	position_ += DELTA * glm::normalize(target_);
}
void Camera::moveBackward()
{
	position_ -= DELTA* glm::normalize(target_);
}
void Camera::roundRight()
{
	target_ = glm::rotateY(target_, -glm::radians(ANGLE_DELTA));

}
void Camera::roundLeft()
{
	target_ = glm::rotateY(target_, glm::radians(ANGLE_DELTA));

}

void Camera::moveDown()
{
	if(position_.y >= FLOOR_Y_POS)
		position_ -= DELTA* glm::normalize(up_);
}

void Camera::moveUp()
{
	if(position_.y <= MAX_Y_POS)
		position_ += DELTA* glm::normalize(up_);
}

Camera::~Camera()
{
}
