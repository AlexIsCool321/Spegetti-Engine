#include <Headers/Fork.h>

using namespace Spegetti;
using namespace Spegetti_GUI;

int main()
{

	Init();
	
	OS::Window window = OS::Window(glm::vec2(640, 380), "Fork");

	GUI gui = GUI();

	while (!glfwWindowShouldClose(window.Get_Window()))
	{

		window.Update();

	}
	
	window.~Window();
	
	return 0;
}