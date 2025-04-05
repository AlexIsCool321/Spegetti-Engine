#include <Engine.h>

// Remove Console
#ifdef _WIN32
#include <Windows.h>

int main();

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return main();
}

#endif // _WIN32

int main()
{
	Init_Spegetti_Renderer();

	Window window = Window("Engine", 800, 600);
	window.Set_Icon("bin/UV_Viewer.png");

	Model model = Model("engine/models/crowbar.obj");

	Camera camera = Camera(Camera::Perspective, 90.0f, &window, 0.005f, 500);

	camera.Add_Model_To_Draw_Stack(&model);

	while (!window.Should_Close())
	{
		window.Push_Context();
		window.Update();
		
		FreeCam(&camera, &window);

		camera.Draw();
	}

	Quit_Spegetti_Renderer();

	return 0;
}