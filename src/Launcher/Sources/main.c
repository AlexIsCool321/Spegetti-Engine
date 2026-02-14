#include <Core/Core.h>
#include <PlugNPlay/PlugNPlay.h>

int main(int argc, char** argv)
{
	LoadPlugIn("plugins", "GLFW_Window");
	LoadPlugIn("plugins", "GL_Renderer");

	InitSystem();

	Surface* surface = CreateSurface();
	Instance* instance = CreateInstance();

	IWindow* window = CreateWindow(800, 600, "Window");
	AttachSurfaceAndInstanceToWindow(window, surface, instance);

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