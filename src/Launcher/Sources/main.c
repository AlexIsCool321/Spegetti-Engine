#include <Core/Core.h>
#include <PlugNPlay/PlugNPlay.h>

int main(int argc, char** argv)
{
	LoadPlugIn("plugins", "GLFW_Window");

	InitSystem();

	

	IWindow* window = CreateWindow(800, 600, "Window");
	CreateWindowContex(window);

	for(;;)
	{
		if (!IsWindowOpen(window)) break;
		
		UpdateWindow(window);
	}

	DestroyWindow(window);

	TerminateSystem();

	UnloadAllPlugIns();

	return 0;
}