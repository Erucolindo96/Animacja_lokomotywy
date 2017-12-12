#include "OpenGlWindow.h"



OpenGlWindow::OpenGlWindow()
{
}

void OpenGlWindow::createWindow()
{
	if (glfwInit() != GL_TRUE)
	{
		throw GlInitializationFail("GLFW init: Cannot init\n");
	}
	//needGLFWdestroy = true;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	window_ = glfwCreateWindow(WIDTH, HEIGHT, WINDOW_NAME , nullptr, nullptr);
	if (window_ == nullptr)
	{
		throw GlInitializationFail("GLFW: Cannot create a window\n");
	}
	glfwMakeContextCurrent(window_);
	OpenGlWindow::setKeyCallback(this->window_, defaultKeyCallback);

}

void OpenGlWindow::setUpOpenGl()
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		throw GlInitializationFail("GLEW: GLEW Initialization failed\n");

	glViewport(0, 0, WIDTH, HEIGHT);
}




OpenGlWindow::~OpenGlWindow()
{
	destroyWindow();
	destroyOpenGl();
}
/*
void OpenGlWindow::setKeyCallback(void callbackFuncName(GLFWwindow* window, int key, int scancode, int action, int mode))
{
	glfwSetKeyCallback(window_, callbackFuncName);
}

void OpenGlWindow::keyCallbackDefault(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
*/
void OpenGlWindow::destroyWindow()
{
	glfwTerminate();
	//needGLFWdestroy = false;
	//ciekawe czy nie trzeba jeszcze zniszczyc window_
}

void OpenGlWindow::destroyOpenGl()
{
	//chyba nie trzeba tego wolac
}

void OpenGlWindow::setKeyCallback(GLFWwindow * window_to_handle, void(*callback)(GLFWwindow * window, int key, int scancode, int action, int mode))
{
	glfwSetKeyCallback(window_to_handle, callback);
}
/*
void OpenGlWindow::setKeyCallback(void(OpenGlWindow::*)(GLFWwindow * window, int key, int scancode, int action, int mode))
{
	glfwSetKeyCallback(window_, func);
}
*/


void defaultKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}