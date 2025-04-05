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

	Texture Albedo = Texture("engine/textures/cube/albedo.png", Texture::Repeat, Texture::Linear);

	Material material = Material();
	material.Set_Texture("material.albedo", &Albedo);

	Model model = Model("engine/models/cube.obj");

	Camera camera = Camera(Camera::Perspective, 90.0f, &window, 0.005f, 500);

	camera.Add_Model_To_Draw_Stack(&model);

	bool Has_Released = false;
	bool Can_Press = true;

	while (!window.Should_Close())
	{
		window.Push_Context();
		window.Update();
		
		if (glfwGetKey(window.Get_Window(), GLFW_KEY_TAB) == GLFW_PRESS)
		{
			if (Has_Released == true)
			{
				if (camera.Mode == Camera::Normal)
				{
					camera.Change_Draw_Mode(Camera::Frag_Position);
				}
				else
				{
					camera.Change_Draw_Mode(Camera::Normal);
				}

				Has_Released = false;
				Can_Press = false;
			}
			else
			{
				if (Can_Press == true)
				{
					Has_Released = true;
				}
			}
		}
		else
		{
			Has_Released = false;
			Can_Press = true;
		}

		FreeCam(&camera, &window);

		camera.Draw(&window);
	}

	Quit_Spegetti_Renderer();

	return 0;
}