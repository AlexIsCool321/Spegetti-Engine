#include <Core/Core.h>
#include <PlugNPlay/PlugNPlay.h>

int main(int argc, char** argv)
{
	LoadPlugIn("plugins", "GLFW_Window");
	LoadPlugIn("plugins", "MGL_Renderer");

	InitSystem();

	Surface* surface = CreateSurface();
	Instance* instance = CreateInstance();

	IWindow* window = CreateWindow(800, 600, "Window");
	AttachSurfaceAndInstanceToWindow(window, surface, instance);

	void* address = GetWindowProcedureAddress(window);
	InitRenderer(address);

	for(;;)
	{
		UpdateWindow(window);

		if (!IsWindowOpen(window)) break;

		SwapWindowBuffers(window);
	}

	DestroyWindow(window);

	TerminateSystem();
	TerminateRenderer();

	UnloadAllPlugIns();

	return 0;
}