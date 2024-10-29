#include <Headers/Spegetti_Film_Maker.h>

using namespace Spegetti;

int main()
{

	Init();
	
	OS::Window window = OS::Window(glm::vec2(640, 380), "Fork");

	while (!glfwWindowShouldClose(window.Get_Window()))
	{

		window.Update();

	}
	
	window.~Window();
	
	return 0;
}
