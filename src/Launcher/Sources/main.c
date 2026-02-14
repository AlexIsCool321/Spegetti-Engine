#include <Core/Core.h>
#include <PlugNPlay/PlugNPlay.h>

int main(int argc, char** argv)
{
	LoadPlugIn("plugins", "GLFW_Window");

	Init_System();

	IWindow* window = CreateWindow(800, 600, "Window");

	for(;;)
	{
		if (!IsWindowOpen(window)) break;
		
		UpdateWindow(window);
	}

	DestroyWindow(window);

	Terminate_System();

	UnloadAllPlugIns();

	return 0;
}