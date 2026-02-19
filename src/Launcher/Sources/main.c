#include <Core/Core.h>
#include <PlugNPlay/PlugNPlay.h>

#include <math.h>

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

	Model* model = LoadModel("cube", "obj");

	Camera camera = CreateCamera(Vector3(0, 0, -2), Vector3(0, 0, 0), 90.0f);

	for(;;)
	{
		UpdateWindow(window);

		if (!IsWindowOpen(window)) break;
		ResizeScreen(GetWindowSize(window));

		// FreeCam
		// Rotation
		camera.rotation.y += GetMouseMotion(window).x * 0.005;
		camera.rotation.x += GetMouseMotion(window).y * 0.005;

		camera.rotation.x = ClampFloat(camera.rotation.x, DegToRad(-89.9), DegToRad(89.9));


		// Position
		camera.position.x += 0.1333 * (IsKeyPressed(window, KEY_D)		- IsKeyPressed(window, KEY_A)) * -cos((camera.rotation.y));
		camera.position.z += 0.1333 * (IsKeyPressed(window, KEY_D)		- IsKeyPressed(window, KEY_A)) * sin((camera.rotation.y));

		camera.position.y += 0.1333 * (IsKeyPressed(window, KEY_SPACE)	- IsKeyPressed(window, KEY_LEFT_SHIFT));

		camera.position.x += 0.1333 * (IsKeyPressed(window, KEY_W)		- IsKeyPressed(window, KEY_S)) * sin((camera.rotation.y));
		camera.position.z += 0.1333 * (IsKeyPressed(window, KEY_W)		- IsKeyPressed(window, KEY_S)) * cos((camera.rotation.y));

		
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