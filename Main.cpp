
#include "Shader.h"
#include "OpenGlWindow.h"
#include "Rectangle.h"
#include <iostream>
#include "Box.h"
int main()
{
	try
	{
		OpenGlWindow window;
		window.createWindow();
		window.setUpOpenGl();
		Shader flat_shader("C:\\Users\\Erukolindo\\Documents\\Visual Studio 2015\\Projects\\Animacja_lokomotywy\\Animacja_lokomotywy\\shaders_code\\gl_03.vert", "C:\\Users\\Erukolindo\\Documents\\Visual Studio 2015\\Projects\\Animacja_lokomotywy\\Animacja_lokomotywy\\shaders_code\\gl_03.frag");
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
		Box b(vert, 2);
		while (!window.shouldClose())
		{
			window.pollEvents();
			flat_shader.Use();
			b.draw();
			window.swapBuffers();
		}
	
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}