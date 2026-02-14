#include <Core/Core.h>
#include <PlugNPlay/PlugNPlay.h>

int main(int argc, char** argv)
{
	LoadPlugIn("plugins", "GLFW_Window");
	LoadPlugIn("plugins", "MGL_Renderer");

	InitSystem();

	Surface* surface = CreateSurface();
	Instance* instance = CreateInstance();

	Surface* surface = CreateSurface();
	Instance* instance = CreateInstance();

	IWindow* window = CreateWindow(800, 600, "Window");
	AttachSurfaceAndInstanceToWindow(window, surface, instance);

	void* address = GetWindowProcedureAddress(window);
	InitRenderer(address);

	const char* vertexShaderSource =
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	
	const char* fragmentShaderSource =
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";

	uint8_t shader = CreateShader(vertexShaderSource, fragmentShaderSource);

	for(;;)
	{
		UpdateWindow(window);

		if (!IsWindowOpen(window)) break;

		SwapWindowBuffers(window);
	}

	DestroyWindow(window);

	TerminateSystem();
	TerminateRenderer();

	UnloadAllPlugIns();

	return 0;
}