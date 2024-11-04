#include <Headers/Spegetti_Launcher.h>

using namespace Spegetti;

int main()
{

	Init();

	OS::Window window = OS::Window(glm::vec2(640, 380), "Spegetti Launcher");

	while (!glfwWindowShouldClose(window.Get_Window()))
	{

		window.Update();

	}

	window.~Window();

	return 0;
}
