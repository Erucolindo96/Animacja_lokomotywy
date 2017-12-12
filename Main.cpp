
#include "Shader.h"
#include "OpenGlWindow.h"
#include <iostream>
int main()
{
	try
	{
		OpenGlWindow window;
		window.createWindow();
		window.setUpOpenGl();
		Shader shady_lady("C:\\Users\\Erukolindo\\Documents\\Visual Studio 2015\\Projects\\Animacja_lokomotywy\\Animacja_lokomotywy\\shaders_code\\gl_03.vert", "C:\\Users\\Erukolindo\\Documents\\Visual Studio 2015\\Projects\\Animacja_lokomotywy\\Animacja_lokomotywy\\shaders_code\\gl_03.frag");
		std::cout << "Kompilacja sie powiodla\n";
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}