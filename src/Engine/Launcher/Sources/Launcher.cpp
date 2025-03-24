#include <Launcher.h>

using namespace Spegetti_Renderer;
using namespace OS;

void Open_Project(std::string path);

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
	std::vector<std::string> Projects;

	for (const auto& entry : std::filesystem::directory_iterator("bin"))
	{
		if (!entry.is_directory())
			entry.path().filename().replace_extension("");
			Projects.push_back(entry.path().filename().string());
	}

	Init_Spegetti_Renderer();
	Window window = Window("Launcher", 800, 600);
	
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window.Get_Window(), true);

	ImGui_ImplOpenGL3_Init("#version 130");

	while (!window.Should_Close())
	{
		window.Update();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::Begin("Launcher");
		ImGui::Text("Select a Project");
		ImGui::Separator();
		
		for (int i = 0; i < Projects.size(); i++)
		{
			if (ImGui::Button(Projects[i].c_str()))
			{
				Open_Project(Projects[i]);
				return 0;
			}
		}
		
		ImGui::End();
		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
	
	return 0;
}

void Open_Project(std::string path)
{
	std::string OS_start;

#ifdef _WIN32
	OS_start = "start";
#endif // _WIN32

#ifdef __linux__ // TODO : does this work?
	OS_start = "";
#endif // __linux__

	system((OS_start + " bin/" + path).c_str());
}