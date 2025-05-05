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
	
	Texture arm			= Texture("demo/textures/block wall/arm.jpg", Texture::Repeat, Texture::Linear);
#else

	Texture albedo = Texture("demo/textures/crowbar/albedo.png", Texture::Repeat, Texture::Linear);
	Texture normal = Texture("demo/textures/crowbar/normal.png", Texture::Repeat, Texture::Linear);

	Texture arm = Texture("demo/textures/crowbar/roughness.png", Texture::Repeat, Texture::Linear);
#endif

	Material light_mat = Material();
	light_mat.Set_Float("emmision", 1.0f);

	Model light_model = Model("demo/models/cube.obj");
	light_model.Set_Material(&light_mat);

	Model crowbar = Model("demo/models/map.obj");
	crowbar.Set_Material(&material);

	crowbar.Transform = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -10.0f));
	crowbar.Update_Transform();

	camera.Add_To_Draw_Stack(&crowbar);
	camera.Add_To_Draw_Stack(&light_model);
	
	std::vector<Light*> light_pos;

	bool Released = true;

	while (!window.Should_Close())
	{
		window.Update();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::Text("FPS : %f", (float)Get_FPS(), 0.1f, 0.0f, 100.0f);
		ImGui::Text("Camera Position : %f %f %f", camera.Position.x, camera.Position.y, camera.Position.z);

		ImGui::Separator();
		
		for (int i = 0; i < light_pos.size(); i++)
		{
			ImGui::Text("Light Position : %f %f %f", light_pos[i]->Position.x, light_pos[i]->Position.y, light_pos[i]->Position.z, 0.1f, -100.0f, 100.0f);
		}

		FreeCam(&camera, &window);

		if (glfwGetKey(window.Get_Window(), GLFW_KEY_E) == GLFW_PRESS)
		{
			if (Released == true)
			{
				Light* light = new Light(camera.Position, glm::vec3(1.0f, 1.0f, 1.0f), 1.0f, 0.09f, 0.032f);
				camera.Add_Light(light);
				light_pos.push_back(light);
				
				Released = false;
			}
		}
		else
		{
			Released = true;
		}

		if (glfwGetKey(window.Get_Window(), GLFW_KEY_Q) == GLFW_PRESS)
		{
			light_pos.clear();
		}

		light_model.Transform = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, sin(glfwGetTime()) * 20.0f));
		light_model.Update_Transform();

		material.Set_Texture("albedo", &albedo);
		material.Set_Texture("normal", &normal);
		
		material.Set_Texture("arm", &arm);

		camera.Draw(&window);

		//ImGui::End();
		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	return 0;
}