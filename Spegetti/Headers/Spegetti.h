#ifndef Spegetti_H
#define Spegetti_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>

namespace Spegetti
{

	void Init();

	bool TestInit();

	namespace Math
	{

		struct Transform3
		{

			Transform3(glm::vec3 Position, glm::vec3 Rotation, glm::vec3 Scale);
			Transform3(float value);

			glm::vec3 Position, Rotation, Scale;

		};

		struct Transform2
		{

			Transform2(glm::vec2 Position, float Rotation, glm::vec2 Scale);
			Transform2(float value);

			glm::vec2 Position, Scale;
			float Rotation;

		};

	}

	namespace Componets
	{

		class Camera
		{

		public:

			Math::Transform3 Transform;

			Camera();
			~Camera();

		};

		class Mesh
		{

		public:

			Math::Transform3 Transform;

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

		char* ReadFile(const std::string& filePath);

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