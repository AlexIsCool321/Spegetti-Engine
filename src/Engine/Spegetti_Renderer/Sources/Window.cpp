#include <Spegetti_Renderer.h>
#include <Spegetti_Logic.h>

#include <stb_image/stb_image.h>

using namespace Spegetti_Logic;

void Resize_Window(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

namespace Spegetti_Renderer
{
	namespace OS
	{
		Window::Window(const char* name, const int width, const int height)
		{
			this->GLFW_Window = glfwCreateWindow(width, height, name, NULL, NULL);
			if (this->GLFW_Window == NULL)
			{
				Fatal_Error("FAILED TO CREATE WINDOW");
				return;
			}
			glfwMakeContextCurrent(this->GLFW_Window);
			glfwSetWindowSizeCallback(this->GLFW_Window, Resize_Window);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				Fatal_Error("FAILED TO INIT GLAD");
				return;
			}

			glViewport(0, 0, width, height);
			glEnable(GL_DEPTH_TEST);

		}

		Window::~Window()
		{
			glfwDestroyWindow(this->GLFW_Window);
		}


		glm::vec2 Window::Get_Size()
		{
			int width, height;
			glfwGetWindowSize(this->GLFW_Window, &width, &height);

			return glm::vec2(width, height);
		}

		GLFWwindow* Window::Get_Window()
		{
			return this->GLFW_Window;
		}


		bool Window::Should_Close()
		{
			return glfwWindowShouldClose(this->GLFW_Window);
		}

		void Window::Close_Window()
		{
			glfwDestroyWindow(this->GLFW_Window);
		}


		void Window::Set_Icon(const char* path)
		{
			GLFWimage images[1];
			images[0].pixels = stbi_load(path, &images[0].width, &images[0].height, 0, 4);
			glfwSetWindowIcon(this->GLFW_Window, 1, images);
			stbi_image_free(images[0].pixels);
		}


		void Window::Update()
		{
			Update_Delta();

			glfwSwapBuffers(this->GLFW_Window);
			glfwPollEvents();

			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::Push_Context()
		{
			glfwMakeContextCurrent(this->GLFW_Window);
		}
	}
}