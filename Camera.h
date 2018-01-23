#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <GLFW\glfw3.h>
#include <SOIL.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Camera
{
protected:
	friend class Renderer;
	//glm::mat4 view_;
	glm::vec3 target_, position_, up_;//wektory patrzenia kamery
	
	//GLfloat hAngle_;//k¹ty patrzenia kamery (k¹ty wektora target) 
	//GLfloat vAngle_;// j.w.
	//GLfloat distance_;//odleglosc od celu
	//const GLfloat MIN_DIS = 0.1, MAX_DIS = 100, MIN_VERTICAL, MAX_VERTICAL;
	const GLfloat DELTA = 0.05f;
	const static int i;

	//const GLfloat NEAR = 0.1, FAR = 100;

public:
	Camera();
	Camera(glm::vec3 target);
	Camera(const Camera &other);
	Camera& operator=(const Camera &other);

//	void setVerticalAngle(GLfloat angle);
	//GLfloat getVerticalAngle()const;

	//void setHorizontalAngle(GLfloat angle);
	//GLfloat getHorizontalAngle()const;

	//void setDistance(GLfloat dis);
	//GLfloat getDistance()const;
	
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
	void moveRight();
	void moveLeft();


//	void incrementHorizontalAngle();
	//void incrementVerticalAngle();

	//void decrementHorizontalAngle();
	//void decrementVerticalAngle();

	//void incrementDistance();
//	void decrementDistance();





	virtual ~Camera();
};

