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

#include <stb_image/stb_image.h>

int main()
{
	Init_Spegetti_Renderer();

	Window window = Window("Spegetti Engine", 800, 600);

	
	Camera camera = Camera(Camera::Perspective, 90.0f, &window, 0.005f, 1000.0f);

	
	Material material = Material();

	Texture albedo		= Texture("demo/textures/crowbar/albedo.png", Texture::Repeat, Texture::Linear);
	Texture normal		= Texture("demo/textures/crowbar/normal.png", Texture::Repeat, Texture::Linear);
	Texture roughness	= Texture("demo/textures/crowbar/roughness.png", Texture::Repeat, Texture::Linear);

	Material light_mat = Material();
	light_mat.Set_Float("emmision", 1.0f);

	Model light = Model("demo/models/cube.obj");
	light.Set_Material(&light_mat);

	Model crowbar = Model("demo/models/crowbar.obj");
	crowbar.Set_Material(&material);

	crowbar.Transform = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -10.0f));
	crowbar.Update_Transform();

	camera.Add_To_Draw_Stack(&crowbar);
	camera.Add_To_Draw_Stack(&light);
	 
	while (!window.Should_Close())
	{
		window.Update();
		
		
		FreeCam(&camera, &window);

		light.Transform = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, sin(glfwGetTime()) * 20.0f));
		light.Update_Transform();

		material.Set_Texture("albedo", &albedo);
		material.Set_Texture("normal", &normal);
		material.Set_Texture("roughness", &roughness);
		

		camera.Draw(&window);
	}

	return 0;
}