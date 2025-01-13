#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	void Init()
	{
		if (!glfwInit())
		{
			Fatal_Error("FAILED TO INIT GLFW");
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		Log("Successfully Init!");
	}
}