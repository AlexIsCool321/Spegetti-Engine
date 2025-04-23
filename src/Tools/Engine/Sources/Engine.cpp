#include <Engine.h>

/*
// Remove Console
#ifdef _WIN32
#include <Windows.h>

int main();

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return main();
}

#endif // _WIN32
*/

int main()
{
	Init_Spegetti_Renderer();

	Window window = Window("Spegetti Engine", 800, 600);

	Camera camera = Camera(Camera::Perspective, 90.0f, &window, 0.005f, 500.0f);

	Material material = Material();

	Texture Albedo = Texture("engine/textures/Crowbar/albedo.png", Texture::Repeat, Texture::Linear);
	Texture Normal = Texture("engine/textures/Crowbar/normal.png", Texture::Repeat, Texture::Linear);
	Texture Roughness = Texture("engine/textures/Crowbar/roughness.png", Texture::Repeat, Texture::Linear);

	Model mesh = Model("engine/models/cube.obj");
	mesh.Set_Material(material);


	camera.Add_Model_To_Draw_Stack(&mesh);


	while (!window.Should_Close())
	{
		window.Update();

		FreeCam(&camera, &window);

		material.Set_Texture("albedo", &Albedo);
		material.Set_Texture("normal", &Normal);
		material.Set_Texture("roughness", &Roughness);

		camera.Draw(&window);
	}

	return 0;
}