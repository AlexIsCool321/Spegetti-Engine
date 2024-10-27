#include "Headers/Spegetti.h"

bool init = false;
bool glinit = false;

void Resize(GLFWwindow* window, int width, int height)
{

	glViewport(0, 0, width, height);

}

namespace Spegetti
{
	void Init()
	{

		if (!glfwInit())
		{

			std::cout << "ERROR : FAILED TO INIT GLFW!!!" << std::endl;
			glfwTerminate();
			exit(1);

		}

		init = true;

	}

	bool TestInit()
	{

		if (init)
		{

			return true;

		}

		std::cout << "ERROR : YOU HAVEN'T INIT SPEGETTI (CALL THE Init() FUNCTION BTW)!!!" << std::endl;
		return false;

	}

	namespace Math
	{

		Transform::Transform(glm::vec3 Position, glm::vec3 Rotation, glm::vec3 Scale)
		{

			this->Position = Position;
			this->Rotation = Rotation;
			this->Scale = Scale;

		}

		Transform::Transform(float value)
		{

			this->Position = glm::vec3(value);
			this->Rotation = glm::vec3(value);
			this->Scale = glm::vec3(value);

		}

	}

	namespace OS
	{

		Window::Window(glm::vec2 size, const char* title)
			{

				if (!Spegetti::TestInit()) return;

				this->window = glfwCreateWindow((int)size.x, (int)size.y, title, nullptr, nullptr);
				if (!this->window)
				{

					std::cout << "ERROR : FAILED TO CREATE A WINDOW!!!" << std::endl;
					return;

				}
				glfwMakeContextCurrent(this->window);
				glfwSetFramebufferSizeCallback(this->window, Resize);

				if (glinit == false)
				{
					if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
					{
						std::cout << "ERROR : FAILED TO INIT GLAD!" << std::endl;
						return;
					}

					glinit = true;

				}
				glViewport(0, 0, (int)size.x, (int)size.y);

			}

		Window::~Window()
			{

				if (!Spegetti::TestInit()) return;

				glfwDestroyWindow(this->window);

				this->window = nullptr;
				glfwDestroyWindow(this->window);

			}

		void Window::Update()
			{

				if (!Spegetti::TestInit()) return;

				glfwPollEvents();
				glfwSwapBuffers(this->window);

			}

		void Window::Push_Contex()
			{

				if (!Spegetti::TestInit()) return;

				glfwMakeContextCurrent(this->window);

			}

		GLFWwindow* Window::Get_Window()
			{

				if (!Spegetti::TestInit()) return NULL;

				return this->window;

			}
		
	}
}