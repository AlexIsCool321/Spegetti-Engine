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

	Texture Albedo = Texture("engine/textures/crowbar/albedo.png", Texture::Repeat, Texture::Linear);
	Texture Normal = Texture("engine/textures/crowbar/normal.png",			Texture::Repeat, Texture::Linear);
	Texture Roughness = Texture("engine/textures/crowbar/roughness.png",	Texture::Repeat, Texture::Linear);

	Material material = Material();

	Model model = Model("engine/models/crowbar.obj");

	Camera camera = Camera(Camera::Perspective, 90.0f, &window, 0.005f, 500);

	camera.Add_Model_To_Draw_Stack(&model);
	
	while (!window.Should_Close())
	{
		window.Push_Context();
		window.Update();

		material.Set_Texture("albedo",		&Albedo);

		FreeCam(&camera, &window);

		camera.Draw(&window);
	}

	Quit_Spegetti_Renderer();

	return 0;
}