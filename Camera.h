#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <GLFW\glfw3.h>
#include <SOIL.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
class Camera
{
protected:
	friend class Renderer;

	glm::vec3 target_, position_, up_;//wektory patrzenia kamery
	

	const GLfloat DELTA = 0.05f, ANGLE_DELTA = 0.3f;


public:
	const float FLOOR_Y_POS = -5.4, MAX_Y_POS = 190;
	Camera();
	
	Camera(glm::vec3 target);
	Camera(const Camera &other);
	Camera& operator=(const Camera &other);

	void setTarget(const glm::vec3 &target);
	glm::vec3 getTarget()const;

	void setPosition(const glm::vec3 &pos);
	glm::vec3 getPosition()const;

	void setUp(const glm::vec3 &up);
	glm::vec3 getUp()const;

	void setDefaultPosition();

	glm::mat4 getViewMatrix()const;

	void moveForward();
	void moveBackward();
	void roundRight();
	void roundLeft();

	void moveDown();
	void moveUp();

	virtual ~Camera();
};

