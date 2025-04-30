#include <Fork.h>

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

	Window window = Window("Fork", 800, 600);
	window.Set_Icon("bin/UV_Viewer.png");

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window.Get_Window(), true);

	ImGui_ImplOpenGL3_Init("#version 130");

	io.IniFilename = NULL;

	Camera camera = Camera(Camera::Perspective, 90.0f, &window, 0.005f, 1000.0f);
	camera.Change_Draw_Mode(Camera::Unlit);

	Shader editor_shader = Shader("engine/shaders/editor.vs", "engine/shaders/editor.fs");
	Material editor = Material(&editor_shader);

	Model grid = Model("engine/models/grid.obj");
	grid.Set_Material(&editor);

	camera.Add_To_Draw_Stack(&grid);

	while (!window.Should_Close())
	{
		Update_Delta();

		FreeCam(&camera, &window);

		// Update Window
		window.Update();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		camera.Draw(&window);

		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	ImGui::End();
	Quit_Spegetti_Renderer();
	
	return 0;
}