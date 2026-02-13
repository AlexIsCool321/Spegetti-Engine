#include <Core/Core.h>
#include <PlugNPlay/PlugNPlay.h>

int main(int argc, char** argv)
{
	LoadPlugIn("plugins", "SDL_Window");
	LoadPlugIn("plugins", "SDL_GL_Renderer");

	InitSystem();

	IWindow* window = CreateWindow(800, 600, "Window");
	CreateContex(window);

	//InitRenderer();
	
	while(IsWindowOpen(window))
	{
		UpdateWindow(window);

		SwapWindowBuffers(window);
	}

	DestroyWindow(window);
	DestroyContex(window);

	TerminateSystem();
	TerminateRenderer();

	UnloadAllPlugIns();

	return 0;
}