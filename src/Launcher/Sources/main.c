#include <Core/Core.h>
#include <PlugNPlay/PlugNPlay.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	LoadPlugIn("plugins", "SDL_Window");

	Init_System();

	IWindow* window = CreateWindow(800, 600, "Window");

	while(IsWindowOpen(window))
	{
		UpdateWindow(window);
	}

	DestroyWindow(window);

	Terminate_System();

	return 0;
}