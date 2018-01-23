
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
			kolejka->reactOnEvents();
			kolejka->render();
			kolejka->swapBuffers();
		}
		delete kolejka;

	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}