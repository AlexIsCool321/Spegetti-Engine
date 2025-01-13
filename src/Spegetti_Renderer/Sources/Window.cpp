#include <Spegetti_Renderer.h>

bool GInit = false;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

namespace Spegetti_Renderer
{
	namespace OS
	{
		Window::Window(std::string name, int size_x, int size_y)
		{
			this->window = glfwCreateWindow(size_x, size_y, name.c_str(), NULL, NULL);
			if (this->window == NULL)
			{
				std::cout << "Failed to create GLFW window" << std::endl;
				glfwTerminate();
				return;
			}
			glfwMakeContextCurrent(this->window);
			glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);

			if (GInit == false)
			{
				if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
				{
					std::cout << "ERROR : FAILED TO INIT GLAD!" << std::endl;
					return;
				}
				GInit = true;
			}
			glViewport(0, 0, size_x, size_y);
		}

		Window::~Window()
		{
			glfwDestroyWindow(this->window);
		}

		GLFWwindow* Window::GetWindow()
		{
			return this->window;
		}

		void Window::Update()
		{
			//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glfwSwapBuffers(this->window);
			glfwPollEvents();
		}

		void Window::PushContext()
		{
			glfwMakeContextCurrent(this->window);
		}
	}
}