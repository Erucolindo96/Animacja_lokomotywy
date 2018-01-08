#pragma once

#define GLEW_STATIC
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <GLFW\glfw3.h>
#include <SOIL.h>
#include "GlInitializationFail.h"
#include <iostream>


class OpenGlWindow
{

public:
	OpenGlWindow();
	
	void swapBuffers();
	void clearBuffers();
	void pollEvents()const;
	bool shouldClose()const;
	GLint getHeigth()const;
	GLint getWidth()const;




	virtual ~OpenGlWindow();

protected:
	void createWindow();
	void setUpOpenGl();
	void destroyWindow();
	void destroyOpenGl();
	static void setKeyCallback(GLFWwindow* window_to_handle, void (*callback) (GLFWwindow* window, int key, int scancode, int action, int mode));
	GLFWwindow* window_;
	const int WIDTH = 800;
	const int HEIGHT = 600;
	const char* WINDOW_NAME = "Animacja lokomotywy";
	
};


void defaultKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);



