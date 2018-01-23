#pragma once
#include "Scene.h"
#include "OpenGlWindow.h"
#include "Camera.h"
#include "Shader.h"
#include "Camera.h"
#include "Skybox.h"
#include <string>

class Renderer
{
protected:
	//Scene scene_to_render;
	const char* DEFAULT_VERT_SHADER = "..\\Animacja_lokomotywy\\shaders_code\\main.vert";
	const char* DEFAULT_FRAG_SHADER = "..\\Animacja_lokomotywy\\shaders_code\\main.frag";
	const char* DEFAULT_SKYBOX_TEXTURE = "..\\Animacja_lokomotywy\\textures\\wood.jpg";
/*	const std::vector<std::string> skybox_paths = {"C:\Users\Erukolindo\Documents\Visual Studio 2015\Projects\Animacja_lokomotywy\Animacja_lokomotywy\textures\ely_hills\\hills_rt.tga",
		"C:\Users\Erukolindo\Documents\Visual Studio 2015\Projects\Animacja_lokomotywy\Animacja_lokomotywy\textures\ely_hills\\hills_lf.tga" ,
		"C:\Users\Erukolindo\Documents\Visual Studio 2015\Projects\Animacja_lokomotywy\Animacja_lokomotywy\textures\ely_hills\\hills_up.tga" ,
		"C:\Users\Erukolindo\Documents\Visual Studio 2015\Projects\Animacja_lokomotywy\Animacja_lokomotywy\textures\ely_hills\\hills_dn.tga" ,
		"C:\Users\Erukolindo\Documents\Visual Studio 2015\Projects\Animacja_lokomotywy\Animacja_lokomotywy\textures\ely_hills\\hills_bk.tga" ,
		"C:\Users\Erukolindo\Documents\Visual Studio 2015\Projects\Animacja_lokomotywy\Animacja_lokomotywy\textures\ely_hills\\hills_ft.tga" };
*/
	const std::vector<std::string> skybox_paths = { "..\\Animacja_lokomotywy\\textures\\ely_hills\\kon_srokaty1.jpg",
		"..\\Animacja_lokomotywy\\textures\\ely_hills\\kon_srokaty1.jpg" ,
		"..\\Animacja_lokomotywy\\textures\\ely_hills\\kon_srokaty1.jpg" ,
		"..\\Animacja_lokomotywy\\textures\\ely_hills\\kon_srokaty1.jpg" ,
		"..\\Animacja_lokomotywy\\textures\\ely_hills\\kon_srokaty1.jpg" ,
		"..\\Animacja_lokomotywy\\textures\\ely_hills\\kon_srokaty1.jpg" };
	
	OpenGlWindow &window_;
	Camera camera_;
	//Skybox skybox_;

	Shader shader_;
	const GLfloat FAR = 100.0f , NEAR = 0.01;
	GLfloat fov_;
	

public:
	Renderer()=delete;
	Renderer(OpenGlWindow &window, const Camera &cam);
	
	void setCamera(const Camera &other);
	Camera getCamera()const;

	void moveCameraForward();
	void moveCameraBackward();
	void moveCameraRight();
	void moveCameraLeft();

	void render(Scene &scene)const;
	glm::mat4x4 getProjectionMatrix()const;
	~Renderer();
};

