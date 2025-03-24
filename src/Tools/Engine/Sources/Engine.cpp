#include <UV_Viewer.h>

// Remove Console
#ifdef _WIN32
#include <Windows.h>

int main();

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return main();
}

#endif // _WIN32

glm::vec3 Light_Position;

int main()
{
	Init_Spegetti_Renderer();

	Window window = Window("Engine", 800, 600);
	window.Set_Icon("bin/UV_Viewer.png");

	Camera camera = Camera(Perspective, 90.0f, &window, 0.01f, 500.0f);
	
	Material material = Material();
	
	Texture albedo		= Texture("engine/textures/crowbar/albedo.png",		Repeat, Linear);
	Texture normal		= Texture("engine/textures/crowbar/normal.png",		Repeat, Linear);
	Texture roughness	= Texture("engine/textures/crowbar/roughness.png",	Repeat, Linear);
	
	Model model = Model("engine/models/crowbar.obj");

	model.Set_Material(material);
	
	camera.Add_Model_To_Draw_Stack(&model);
	
	camera.Reload_Models(&window);
	

	//Shader shader = Shader("engine/shaders/light.vs", "engine/shaders/light.fs");
	//Material material = Material(&shader);
	//Post_Process_Effect effect = Post_Process_Effect(&material);

	while (!window.Should_Close())
	{
		Update_Delta();

		window.Push_Context();
		window.Update();
		
		//effect.Draw();

		
		FreeCam(&camera, &window);

		material.Set_Texture("material.albedo", &albedo);
		material.Set_Texture("material.normal", &normal);
		material.Set_Texture("material.roughness", &roughness);

		camera.Draw();
		
	}

	Quit_Spegetti_Renderer();

	return 0;
}