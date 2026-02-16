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

	Camera camera = CreateCamera(Vector3(0, 0, -2), Vector3(0, 0, 0), 90.0f);

	{
		const char* vertex		= ReadFile("shaders/pbr.vs");
		printf("\n\n%s\n\n", vertex);

		const char* fragment	= ReadFile("shaders/pbr.fs");
		printf("\n\n%s\n\n", fragment);

		unsigned int shader = CreateShader(vertex, fragment);

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