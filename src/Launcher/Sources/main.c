#include <Core/Core.h>
#include <PlugNPlay/PlugNPlay.h>

#include <stdio.h>

int main(int argc, char** argv)
{
	LoadPlugIn("plugins", "GLFW_Window");
	LoadPlugIn("plugins", "MGL_Renderer");

	InitSystem();

	AddSearchPath("engine");

	Surface* surface = CreateSurface();
	Instance* instance = CreateInstance();

	IWindow* window = CreateWindow(800, 600, "Window");
	AttachSurfaceAndInstanceToWindow(window, surface, instance);

	void* address = GetWindowProcedureAddress(window);
	InitRenderer(address);

	Model* model;

	Camera camera = CreateCamera(Vector3(0, 0, -3), Vector3(0, 0, 0), 90.0f);

	ReadFile("test.txt");

	{
		unsigned int shader;

		{
			const char* vertexShaderSource =
				"#version 330 core\n"
				"layout (location = 0) in vec3 aPos;\n"

				"uniform mat4 uView;"
				"uniform mat4 uProjection;"

				"void main()\n"
				"{\n"
				"   gl_Position = uProjection * inverse(uView) * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
				"}\0";
			
			const char* fragmentShaderSource =
				"#version 330 core\n"
				"out vec4 FragColor;\n"
				"void main()\n"
				"{\n"
				"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
				"}\0";

			shader = CreateShader(vertexShaderSource, fragmentShaderSource);
		}

		Vertex vertices[3] =
		{
			CreateVertex(Vector3(	-0.5,	-0.5,	 0.0	)),
			CreateVertex(Vector3(	 0.0,	 0.5,	 0.0	)),
			CreateVertex(Vector3(	 0.5,	-0.5,	 0.0	))
		};

		unsigned int indices[3] =
		{
			0, 1, 2
		};

		Mesh* mesh = CreateMesh(vertices, sizeof(vertices)/sizeof(Vertex), indices, sizeof(indices)/sizeof(unsigned int), shader);

		Mesh* meshes[1] =
		{
			mesh
		};

		model = CreateModel(meshes, 1);
	}

	for(;;)
	{
		UpdateWindow(window);

		if (!IsWindowOpen(window)) break;

		// Renderering
		ClearScreen(Vector3(0, 1, 1));

		DrawModel(model, &camera);
		
		SwapWindowBuffers(window);
	}

	DestroyWindow(window);

	DestroyModel(model);

	TerminateSystem();
	TerminateRenderer();

	UnloadAllPlugIns();

	return 0;
}