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

#define bricks 1

#include <stb_image/stb_image.h>

int main()
{
	Init_Spegetti_Renderer();

	Window window = Window("Spegetti Engine", 800, 600);

	

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window.Get_Window(), true);

	ImGui_ImplOpenGL3_Init("#version 130");

	io.IniFilename = NULL;


	Camera camera = Camera(Camera::Perspective, 90.0f, &window, 0.005f, 1000.0f);

	
	Material material = Material();
	
#if bricks
	Texture albedo		= Texture("demo/textures/block wall/albedo.jpg", Texture::Repeat, Texture::Linear);
	Texture normal		= Texture("demo/textures/block wall/normal.png", Texture::Repeat, Texture::Linear);
	
	Texture ao	= Texture("demo/textures/block wall/ao.jpg", Texture::Repeat, Texture::Linear);
	Texture metallic	= Texture("demo/textures/block wall/height.png", Texture::Repeat, Texture::Linear);
	Texture roughness	= Texture("demo/textures/block wall/roughness.png", Texture::Repeat, Texture::Linear);
#else

	Texture albedo = Texture("demo/textures/crowbar/albedo.png", Texture::Repeat, Texture::Linear);
	Texture normal = Texture("demo/textures/crowbar/normal.png", Texture::Repeat, Texture::Linear);

	Texture ao = Texture("demo/textures/crowbar/roughness.png", Texture::Repeat, Texture::Linear);
	Texture metallic = Texture("demo/textures/crowbar/roughness.png", Texture::Repeat, Texture::Linear);
	Texture roughness = Texture("demo/textures/crowbar/roughness.png", Texture::Repeat, Texture::Linear);
#endif

	Material light_mat = Material();
	light_mat.Set_Float("emmision", 1.0f);

	Model light = Model("demo/models/cube.obj");
	light.Set_Material(&light_mat);

	Model crowbar = Model("demo/models/map.obj");
	crowbar.Set_Material(&material);

	crowbar.Transform = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -10.0f));
	crowbar.Update_Transform();

	camera.Add_To_Draw_Stack(&crowbar);
	camera.Add_To_Draw_Stack(&light);
	
	

	while (!window.Should_Close())
	{
		window.Update();
		float fps = Get_FPS();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::DragFloat("FPS", &fps, 0.1f, 0.0f, 100.0f);
		
		FreeCam(&camera, &window);

		light.Transform = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, sin(glfwGetTime()) * 20.0f));
		light.Update_Transform();

		material.Set_Texture("albedo", &albedo);
		material.Set_Texture("normal", &normal);
		
		material.Set_Texture("ao", &ao);
		material.Set_Texture("metallic", &metallic);
		material.Set_Texture("roughness", &roughness);
		
		material.Set_Texture("height", &metallic);

		camera.Draw(&window);

		//ImGui::End();
		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	return 0;
}