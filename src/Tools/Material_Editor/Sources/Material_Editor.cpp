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

const std::string Shader_Path = "engine/shades/pbr";

struct Uniform
{
	enum Type
	{
		VEC2,
		VEC3,
		VEC4,
		INT,
		FLOAT,
		TEXTURE
	};
	
	std::string name;
	Type type;

	Uniform(std::string name, Type type)
	{
		this->name = name;
		this->type = type;
	}
};

std::vector<Uniform> Get_Uniforms(const char* path);

std::vector<Uniform> uniforms;

int main()
{
	uniforms = Get_Uniforms(Shader_Path.c_str());
	
	std::vector<int> int_values;
	std::vector<float> float_values;

	std::vector<glm::vec2> vec2_values;
	std::vector<glm::vec3> vec3_values;
	std::vector<glm::vec4> vec4_values;

	std::vector<unsigned int> texture_values;

	Init_Spegetti_Renderer();

	Window window = Window("Material Editor", 800, 600);
	window.Set_Icon("bin/UV_Viewer.png");

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window.Get_Window(), true);

	ImGui_ImplOpenGL3_Init("#version 130");

	io.IniFilename = NULL;

	while (!window.Should_Close())
	{
		Update_Delta();

		// Update Window
		window.Update();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::Begin("Launcher");
		ImGui::Separator();
		
		for (int i = 0; i < 25; i++)
		{
			ImGui::Text("A");
		}

		ImGui::End();
		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	}

	Quit_Spegetti_Renderer();
	
	return 0;
}

std::vector<Uniform> Get_Uniforms(const char* path)
{
	std::string file;
	std::ifstream stream(Shader_Path + ".vs", std::ios::in);

	std::vector<Uniform> uniforms;

	if (stream.is_open())
	{
		std::string line = "";
		while (std::getline(stream, line))
		{
			if (First_Token(line) == "uniform vec2") // vec2
			{
				uniforms.push_back(Uniform(Split(First_Token(line), 3, ' '), Uniform::VEC2));
			}

			if (First_Token(line) == "uniform vec3") // vec3
			{
				uniforms.push_back(Uniform(Split(First_Token(line), 3, ' '), Uniform::VEC3));
			}

			if (First_Token(line) == "uniform vec4") // vec4
			{
				uniforms.push_back(Uniform(Split(First_Token(line), 3, ' '), Uniform::VEC4));
			}

			if (First_Token(line) == "uniform int") // int
			{
				uniforms.push_back(Uniform(Split(First_Token(line), 3, ' '), Uniform::INT));
			}

			if (First_Token(line) == "uniform float") // float
			{
				uniforms.push_back(Uniform(Split(First_Token(line), 3, ' '), Uniform::FLOAT));
			}

			if (First_Token(line) == "uniform sampler2D") // texture
			{
				uniforms.push_back(Uniform(Split(First_Token(line), 3, ' '), Uniform::TEXTURE));
			}
		}
		stream.close();
	}
	else
	{
		Error("FAILED TO LOAD SHADER : [ " + (std::string)Shader_Path + " ]");
	}

	stream = std::ifstream(Shader_Path + ".fs", std::ios::in);

	if (stream.is_open())
	{
		std::string line = "";
		while (std::getline(stream, line))
		{
			if (First_Token(line) == "uniform vec2") // vec2
			{
				uniforms.push_back(Uniform(Split(First_Token(line), 3, ' '), Uniform::VEC2));
			}

			if (First_Token(line) == "uniform vec3") // vec3
			{
				uniforms.push_back(Uniform(Split(First_Token(line), 3, ' '), Uniform::VEC3));
			}

			if (First_Token(line) == "uniform vec4") // vec4
			{
				uniforms.push_back(Uniform(Split(First_Token(line), 3, ' '), Uniform::VEC4));
			}

			if (First_Token(line) == "uniform int") // int
			{
				uniforms.push_back(Uniform(Split(First_Token(line), 3, ' '), Uniform::INT));
			}

			if (First_Token(line) == "uniform float") // float
			{
				uniforms.push_back(Uniform(Split(First_Token(line), 3, ' '), Uniform::FLOAT));
				Log("S");
			}

			if (First_Token(line) == "uniform sampler2D") // texture
			{
				uniforms.push_back(Uniform(Split(First_Token(line), 3, ' '), Uniform::TEXTURE));
			}
		}
		stream.close();
	}

	return uniforms;
}