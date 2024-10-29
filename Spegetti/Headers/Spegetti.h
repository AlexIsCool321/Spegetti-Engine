#ifndef Spegetti_H
#define Spegetti_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <iostream>

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