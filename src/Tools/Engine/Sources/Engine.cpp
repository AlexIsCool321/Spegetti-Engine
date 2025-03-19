#include <Engine.h>

int main()
{
	Init_Spegetti_Renderer();


	Window window = Window("Game", 1200, 800);

	
	Texture albedo1 = Texture("engine/textures/cube/albedo.png", Repeat, Closest);
	Material material1 = Material("engine/materials/default.mat");

	Model mesh1 = Model("engine/models/cube.obj");
	mesh1.Set_Material(material1);
	
	material1.Set_Texture("albedo", &albedo1);


	Camera camera = Camera(&window);
	camera.Change_Draw_Mode(Normal);

	camera.Add_Model_To_Draw_Stack(&mesh1);
	

	while (!window.Should_Close())
	{
		// Update Window / Screen
		window.Update();
		window.Push_Context();


		// Logic
		if (glfwGetKey(window.Get_Window(), GLFW_KEY_TAB) == GLFW_PRESS)
		{
			while (glfwGetKey(window.Get_Window(), GLFW_KEY_TAB) == GLFW_PRESS) 
			{
				window.Update();
				FreeCam(&camera, &window);

				camera.Draw();
			}

			if (camera.Mode == Normal)
			{
				camera.Change_Draw_Mode(Wireframe);
			}
			else
			{
				camera.Change_Draw_Mode(Normal);
			}
		}

		FreeCam(&camera, &window);


		// Render
		camera.Draw();
	}

	Quit_Spegetti_Renderer();

	return 0;
}