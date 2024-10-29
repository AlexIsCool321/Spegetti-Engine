#ifndef Spegetti_H
#define Spegetti_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <glm/glm.hpp>

#include <iostream>
/*
enum Graphics_Drivers
{
	OpenGL2,//not supported
	OpenGL3,//not supported
	OpenGL4,//supported

	Vulkan,//not supported

	Metal//not supported

};

Graphics_Drivers Driver = Graphics_Drivers::OpenGL4;
*/
namespace Spegetti
{

	void Init();

	bool TestInit();

	namespace Math
	{

		struct Transform
		{

			Transform(glm::vec3 Position, glm::vec3 Rotation, glm::vec3 Scale);
			Transform(float value);

			glm::vec3 Position, Rotation, Scale;

		};

	}

	namespace Componets
	{

		class Camera
		{

		public:

			Math::Transform Transform;

			Camera();
			~Camera();

		};

		class Mesh
		{

		public:

			Math::Transform Transform;

			Mesh();
			~Mesh();

			void Draw();

		};

	}

	namespace Graphics
	{

		struct Texture
		{



		};

	}

	namespace OS
	{

		class Window
		{

		private:

			GLFWwindow* window;

		public:

			Window(glm::vec2 size, const char* title);
			~Window();

			void Update();

			void Push_Contex();

			GLFWwindow* Get_Window();

		};

	}

}

#endif