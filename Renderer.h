#pragma once
#include "Scene.h"
#include "OpenGlWindow.h"
#include "Camera.h"
#include "Shader.h"
#include "Camera.h"
#include <string>

class Renderer
{
protected:
	//Scene scene_to_render;
	const char* DEFAULT_VERT_SHADER = "..\\Animacja_lokomotywy\\shaders_code\\main.vert";
	const char* DEFAULT_FRAG_SHADER = "..\\Animacja_lokomotywy\\shaders_code\\main.frag";
	OpenGlWindow &window_;
	Camera camera_;
	
	Shader shader_;
	const GLfloat FAR = 100 , NEAR = 0.1;
	GLfloat fov_;
	

public:
	Renderer()=delete;
	Renderer(OpenGlWindow &window, const Camera &cam);
	
	void setCamera(const Camera &other);
	Camera getCamera()const;


	void render(Scene &scene)const;
	glm::mat4x4 getProjectionMatrix()const;
	~Renderer();
};

