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

	Texture Albedo		= Texture("demo/textures/Crowbar/albedo.png", Texture::Repeat, Texture::Linear);
	Texture Normal		= Texture("demo/textures/Crowbar/normal.png", Texture::Repeat, Texture::Linear);
	Texture Roughness	= Texture("demo/textures/Crowbar/roughness.png", Texture::Repeat, Texture::Linear);

	Model mesh = Model("demo/models/cube.obj");


	camera.Add_Model_To_Draw_Stack(&mesh);
	mesh.Set_Material(material);

	while (!window.Should_Close())
	{
		window.Update();

		FreeCam(&camera, &window);

		material.Use();

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Albedo.Get_ID());
		material.Set_Int("albedo", 0);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, Normal.Get_ID());
		material.Set_Int("normal", 2);

		camera.Draw(&window);
	}

	return 0;
}