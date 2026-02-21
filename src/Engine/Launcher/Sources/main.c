#include <Core/Core.h>
#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>

int main(int argc, char** argv)
{
	LoadPlugIn("GLFW_Window");
	LoadPlugIn("MGL_Renderer");

	InitSystem();

	AddSearchPath("engine");

	Surface* surface = CreateSurface();
	Instance* instance = CreateInstance();

	IWindow* window = CreateWindow(800, 600, "Window");
	SetCurrentWindow(window);
	AttachSurfaceAndInstanceToWindow(window, surface, instance);

	void* address = GetWindowProcedureAddress(window);
	InitRenderer(address);

	LoadGame("Demo");

	Entity* freecam = CreateEntity("FreeCam", "FreeCam");

	Model* model = LoadModel("cube", "obj");

	for(;;)
	{
		UpdateWindow(window);

		if (!IsWindowOpen(window)) break;
		ResizeScreen(GetWindowSize(window));

		UpdateEntity(freecam);
		
		// Renderering
		ClearScreen(Vector3(0, 1, 1));

		DrawModel(model);
		
		SwapWindowBuffers(window);
	}

	DestroyWindow(window);

	DestroyEntity(freecam);

	DestroyModel(model);

	TerminateSystem();
	TerminateRenderer();

	UnloadAllPlugIns();

	return 0;
}