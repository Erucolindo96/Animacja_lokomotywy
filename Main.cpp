
#include "Shader.h"
#include "Animation.h"
#include "Rectangle.h"
#include <iostream>
#include "Box.h"
#include "Scene.h"
#include "Renderer.h"
#include "Camera.h"
int main()
{
	try
	{
		Animation *kolejka = new Animation();
		kolejka->setDefaultScene();
		
		while (!kolejka->shouldClose())
		{
			kolejka->clearBuffers();
			kolejka->pollEvents();
			kolejka->render();
			kolejka->swapBuffers();
		}
		delete kolejka;
		/*
		OpenGlWindow window;
		//window.createWindow();
		//window.setUpOpenGl();
		Shader flat_shader("C:\\Users\\Erukolindo\\Documents\\Visual Studio 2015\\Projects\\Animacja_lokomotywy\\Animacja_lokomotywy\\shaders_code\\main.vert", "C:\\Users\\Erukolindo\\Documents\\Visual Studio 2015\\Projects\\Animacja_lokomotywy\\Animacja_lokomotywy\\shaders_code\\main.frag");
				std::cout << "Kompilacja sie powiodla\n";
				glm::vec3 pos({ 0, 0, 0 }), color({ 0.7, 0.6, 0 });
				glm::vec2 tex({ 0, 0 });
				Vertex v;
				v.color_ = color;
				v.position_ = pos;
				v.normal_ = pos;
				v.textCoord_ = tex;
				std::vector<Vertex> vert;
				vert.push_back(v);

				v.position_ = { 0.1, 0, 0.5 };
				v.color_ = { 1, 1, 0.5 };;
				vert.push_back(v);

				v.position_ = { 0.6, 0, 0.5 };
				v.color_= { 0.7, 0.6, 0 };
				vert.push_back(v);

				v.position_ = { 0.5, 0, 0};
				v.color_ = { 1, 1, 0.5 };
				vert.push_back(v);

				//Rectangle rect(vert);
				//std::unique_ptr<Actor> box(new Box(vert, 2));
				Box b(vert, 2);
				Scene scene;
				scene.setActor(b);
				//Camera cam(glm::vec3(1, 0, 0));
				Renderer rend(window, Camera());
				while (!window.shouldClose())
				{
					window.pollEvents();
					//flat_shader.Use();
					//b.draw();
					rend.render(scene);
					window.swapBuffers();
				}

*/	
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}