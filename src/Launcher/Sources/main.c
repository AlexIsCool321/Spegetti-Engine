#include <Core/Core.h>
#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>

int main(int argc, char** argv)
{
	LoadPlugIn("plugins", "GLFW_Window");
	LoadPlugIn("plugins", "MGL_Renderer");

	InitSystem();

	AddSearchPath("engine");

	Surface* surface = CreateSurface();
	Instance* instance = CreateInstance();

	IWindow* window = CreateWindow(800, 600, "Window");
	AttachSurfaceAndInstanceToWindow(window, surface, instance);

	void* address = GetWindowProcedureAddress(window);
	InitRenderer(address);

	Model* model = LoadModel("cube", "glb");

	Camera camera = CreateCamera(Vector3(0, 0, -2), Vector3(0, 0, 0), 90.0f);

	for(;;)
	{
		UpdateWindow(window);

		if (!IsWindowOpen(window)) break;
		ResizeScreen(GetWindowSize(window));

		camera.position.x += 0.1333 * (IsKeyPressed(window, KEY_A)		- IsKeyPressed(window, KEY_D));
		camera.position.y += 0.1333 * (IsKeyPressed(window, KEY_SPACE)	- IsKeyPressed(window, KEY_LEFT_SHIFT));
		camera.position.z += 0.1333 * (IsKeyPressed(window, KEY_W)		- IsKeyPressed(window, KEY_S));

		// Renderering
		ClearScreen(Vector3(0, 1, 1));

		DrawModel(model, &camera);
		
		SwapWindowBuffers(window);
	}

	DestroyWindow(window);

	DestroyModel(model);

	TerminateSystem();
	TerminateRenderer();

	UnloadAllPlugIns();

	return 0;
}