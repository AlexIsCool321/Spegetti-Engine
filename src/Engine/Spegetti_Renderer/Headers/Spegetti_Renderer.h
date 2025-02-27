﻿#ifndef Spegetti_Renderer_H
#define Spegetti_Renderer_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>

#include <Spegetti_Console.h>
#include <Spegetti_Files.h>

using namespace Spegetti_Console;
using namespace Spegetti_Files;

namespace Spegetti_Renderer
{
	void Init();

	namespace Graphics
	{
		struct Vertex
		{
			Vertex(glm::vec3 Position, int Vertex_Group, glm::vec3 Normal, glm::vec2 UV_Coords);

			int Vertex_Group;

			glm::vec3 Position;
			glm::vec3 Normal;

			glm::vec2 UV_Coords;
		};

		struct Shader
		{
			std::string vertex_shader;
			std::string fragment_shader;

			Shader(std::string vertex_path, std::string fragment_path);
		};

		class Material
		{
		private:
			unsigned int shaderProgram;

		public:
			Material(Shader shader);

			void Use();

			bool Has_Uniform(const std::string& name);

			void SetBool(const std::string& name, bool value) const;
			void SetInt(const std::string& name, int value) const;
			void SetFloat(const std::string& name, float value) const;

			void SetVector2(const std::string& name, glm::vec2 value) const;
			void SetVector3(const std::string& name, glm::vec3 value) const;
			void SetVector4(const std::string& name, glm::vec4 value) const;

			void SetMat2(const std::string& name, glm::mat2 value) const;
			void SetMat3(const std::string& name, glm::mat3 value) const;
			void SetMat4(const std::string& name, glm::mat4 value) const;

			void SetTexture(const std::string& name, const char* texture_path);
		};

		class Mesh
		{
		private:

			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;
			std::vector<Material> materials;
			
			unsigned int VAO, VBO, EBO, ID;

		public:

			glm::mat4 model;

			Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Material> materials);
			~Mesh();

			void Draw(glm::mat4 view_transform);
		};

		struct Camera
		{
			bool active = true;

			glm::mat4 view;
			glm::mat4 projection;

			glm::vec3 Position;
			glm::vec3 Rotation;

			Camera();

			void Draw(Mesh* mesh);
		};
	}

	namespace OS
	{
		class Window
		{
		private:

			GLFWwindow* window;

		public:

			Window(std::string name, int size_x, int size_y);
			~Window();

			GLFWwindow* GetWindow();
			void Update();
			void PushContext();
		};
	}
}

#endif // !Spegetti_Renderer_H