#pragma once
#include "Scene.h"
#include "OpenGlWindow.h"
#include "Camera.h"
#include "Shader.h"
class Renderer
{
protected:
	//Scene scene_to_render;
	OpenGlWindow &window_;
	Shader shader_;
public:
	Renderer()=delete;
	Renderer(OpenGlWindow &window);
	void render(const Scene &scene, const Camera &camera);
	~Renderer();
};

