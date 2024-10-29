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

		Transform3::Transform3(glm::vec3 Position, glm::vec3 Rotation, glm::vec3 Scale)
		{

			this->Position = Position;
			this->Rotation = Rotation;
			this->Scale = Scale;

		}

		Transform3::Transform3(float value)
		{

			this->Position = glm::vec3(value);
			this->Rotation = glm::vec3(value);
			this->Scale = glm::vec3(value);

		}

		Transform2::Transform2(glm::vec2 Position, float Rotation, glm::vec2 Scale)
		{

			this->Position = Position;
			this->Rotation = Rotation;
			this->Scale = Scale;

		}

		Transform2::Transform2(float value)
		{

			this->Position = glm::vec2(value);
			this->Rotation = value;
			this->Scale = glm::vec2(value);

		}

	}

	namespace OS
	{

		char* ReadFile(const std::string& filePath) {

			if (!Spegetti::TestInit()) return NULL;


			std::ifstream file(filePath, std::ios::in | std::ios::binary | std::ios::ate);

			if (!file)
			{

				std::cerr << "ERROR : FAILED TO READ FILE!!! {" << filePath << "}" << std::endl;
				return nullptr;

			}

			std::streamsize size = file.tellg();
			file.seekg(0, std::ios::beg);

			char* buffer = new char[size + 1];

			if (file.read(buffer, size))
			{

				buffer[size] = '\0';

			}
			else
			{

				std::cerr << "ERROR : FAILED TO READ FILE!!! {" << filePath << "}" << std::endl;
				delete[] buffer;
				buffer = nullptr;

			}

			file.close();
			return buffer;

		}

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