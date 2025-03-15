#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	void Init_Spegetti_Renderer()
	{
		// -------------------------------------------------
		// GLFW Init
		// -------------------------------------------------
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
		// -------------------------------------------------
		// GLFW Init
		// -------------------------------------------------

		Log("Successfully Init!");
	}

	void Quit_Spegetti_Renderer()
	{
		glfwTerminate();
		Log("Successfully Quit!");
	}
}