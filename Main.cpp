
#include "Shader.h"
#include "OpenGlWindow.h"
#include "Rectangle.h"
#include <iostream>
int main()
{
	try
	{
		OpenGlWindow window;
		window.createWindow();
		window.setUpOpenGl();
		Shader flat_shader("C:\\Users\\Erukolindo\\Documents\\Visual Studio 2015\\Projects\\Animacja_lokomotywy\\Animacja_lokomotywy\\shaders_code\\gl_03.vert", "C:\\Users\\Erukolindo\\Documents\\Visual Studio 2015\\Projects\\Animacja_lokomotywy\\Animacja_lokomotywy\\shaders_code\\gl_03.frag");
		std::cout << "Kompilacja sie powiodla\n";
		glm::vec3 pos({ 0.5, 0.5, 0.5 }), color({ 0.7, 0.6, 0 });
		glm::vec2 tex({ 0, 0 });
		Vertex v;
		v.color_ = color;
		v.position_ = pos;
		v.normal_ = pos;
		v.textCoord_ = tex;
		std::vector<Vertex> vert;
		vert.push_back(v);

		v.position_ = { -0.5, 0.5, 0.5 };
		vert.push_back(v);
		
		v.position_ = { -0.5, -0.5, 0.5 };
		vert.push_back(v);

		v.position_ = { 0.5, -0.5, 0.5 };
		vert.push_back(v);

		Rectangle rect(vert);
		while (!window.shouldClose())
		{
			window.pollEvents();
			flat_shader.Use();
			rect.draw();
			window.swapBuffers();
		}
	
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}