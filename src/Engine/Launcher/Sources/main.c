#include <Core/Core.h>
#include <PlugNPlay/PlugNPlay.h>

#include <math.h>

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
	AttachSurfaceAndInstanceToWindow(window, surface, instance);

	void* address = GetWindowProcedureAddress(window);
	InitRenderer(address);

	Model* model = LoadModel("cube", "obj");

	Camera camera = CreateCamera(Vector3(0, 0, -2), Vector3(0, 0, 0), 90.0f);
	SetCurrentCamera(&camera);

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
		Vec3 InputDirection = Vector3
		(
			IsKeyPressed(window, KEY_D)		- IsKeyPressed(window, KEY_A),
			IsKeyPressed(window, KEY_SPACE)	- IsKeyPressed(window, KEY_LEFT_SHIFT),
			IsKeyPressed(window, KEY_W)		- IsKeyPressed(window, KEY_S)
		);

		Vec3 Forward = Vector3
		(
			InputDirection.z * sin(camera.rotation.y),
			0,
			InputDirection.z * cos(camera.rotation.y)
		);
		Forward = ScaleVector3(Forward, 0.1333);

		Vec3 Right = Vector3
		(
			InputDirection.x * -cos(camera.rotation.y),
			0,
			InputDirection.x * sin(camera.rotation.y)
		);
		Right = ScaleVector3(Right, 0.1333);

		
		camera.position = AddVector3(camera.position, Forward);
		camera.position = AddVector3(camera.position, Right);

		camera.position.y += 0.1333 * InputDirection.y;
		
		// Renderering
		ClearScreen(Vector3(0, 1, 1));

		DrawModel(model);
		
		SwapWindowBuffers(window);
	}

	DestroyWindow(window);

	DestroyModel(model);

	TerminateSystem();
	TerminateRenderer();

	UnloadAllPlugIns();

	return 0;
}