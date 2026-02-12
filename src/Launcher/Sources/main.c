#include <Core/Core.h>
#include <PlugNPlay/PlugNPlay.h>

int main(int argc, char** argv)
{
	LoadPlugIn("plugins", "SDL_Window");
	LoadPlugIn("plugins", "GL_Renderer");

	InitSystem();
	InitRenderer();

	IWindow* window = CreateWindow(800, 600, "Window");

	Vertex vertices[3] =
	{
		CreateVertex(CreateVec3(	 0.0,	 0.5,	 0.0	)),
		CreateVertex(CreateVec3(	 0.5,	 0.0,	 0.0	)),
		CreateVertex(CreateVec3(	 0.5,	 0.5,	 0.0	))
	};

	unsigned long indices[3] =
	{
		0, 1, 2
	};

	const char* vertex_shader = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	
	const char* fragment_shader = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";


	unsigned short shader = CreateShader(vertex_shader, fragment_shader);

	Mesh* mesh = CreateMesh(vertices, sizeof(vertices) / sizeof(Vertex), indices, sizeof(indices) / sizeof(unsigned long), shader);

	while(IsWindowOpen(window))
	{
		UpdateWindow(window);

		DrawMesh(mesh);

		SwapWindowBuffers(window);
	}

	DestroyWindow(window);

	DestroyMesh(mesh);

	TerminateSystem();
	TerminateRenderer();

	return 0;
}