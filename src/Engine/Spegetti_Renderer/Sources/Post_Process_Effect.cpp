#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Post_Process_Effect::Post_Process_Effect()
		{
			Shader shader = Shader("engine/shaders/light.vs", "engine/shaders/light.fs");
			
			this->Effect_Material = Material(&shader);
			this->Effect_Material.Load_Shader(&shader);

			this->Effect_Material.Change_Cull_Mode(Material::Cull_Mode::None);

			static std::vector<Vertex> Vertices =
			{
				Vertex(glm::vec3(-1.0f,	-1.0f,	0.0f), 1, glm::vec3(1,	0,	0), glm::vec2(0,	0), glm::vec3(0,	0,	0), glm::vec3(0,	0,	0)),	// Bottom Left
				Vertex(glm::vec3(1.0f,	-1.0f,	0.0f), 1, glm::vec3(1,	0,	0), glm::vec2(1,	0), glm::vec3(0,	0,	0), glm::vec3(0,	0,	0)),	// Bottom Right
				Vertex(glm::vec3(-1.0f,	 1.0f,	0.0f), 1, glm::vec3(1,	0,	0), glm::vec2(0,	1), glm::vec3(0,	0,	0), glm::vec3(0,	0,	0)),	// Top Left
				Vertex(glm::vec3(1.0f,	 1.0f,	0.0f), 1, glm::vec3(1,	0,	0), glm::vec2(1,	1), glm::vec3(0,	0,	0), glm::vec3(0,	0,	0))		// Top Right
			};

			static std::vector<unsigned int> Indices =
			{
				3, 1, 2,	// 1
				1, 0, 2		// 2	
			};

			glGenVertexArrays(1, &this->VAO);
			glGenBuffers(1, &this->VBO);
			glGenBuffers(1, &this->EBO);

			glBindVertexArray(this->VAO);
			glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

			glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(Vertex), &Vertices[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(unsigned int), &Indices[0], GL_STATIC_DRAW);

			// Vertices' Positions
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
			// Vertices' UV Coords
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, UV_Coords));

			glBindVertexArray(0);
		}

		Post_Process_Effect::Post_Process_Effect(Material* material)
		{
			static std::vector<Vertex> Vertices =
			{
				Vertex(glm::vec3(-1.0f,	-1.0f,	0.0f), 1, glm::vec3(1,	0,	0), glm::vec2(0,	0), glm::vec3(0,	0,	0), glm::vec3(0,	0,	0)),	// Bottom Left
				Vertex(glm::vec3(1.0f,	-1.0f,	0.0f), 1, glm::vec3(1,	0,	0), glm::vec2(1,	0), glm::vec3(0,	0,	0), glm::vec3(0,	0,	0)),	// Bottom Right
				Vertex(glm::vec3(-1.0f,	 1.0f,	0.0f), 1, glm::vec3(1,	0,	0), glm::vec2(0,	1), glm::vec3(0,	0,	0), glm::vec3(0,	0,	0)),	// Top Left
				Vertex(glm::vec3(1.0f,	 1.0f,	0.0f), 1, glm::vec3(1,	0,	0), glm::vec2(1,	1), glm::vec3(0,	0,	0), glm::vec3(0,	0,	0))		// Top Right
			};

			static std::vector<unsigned int> Indices =
			{
				3, 1, 2,	// 1
				1, 0, 2		// 2	
			};

			glGenVertexArrays(1, &this->VAO);
			glGenBuffers(1, &this->VBO);
			glGenBuffers(1, &this->EBO);

			glBindVertexArray(this->VAO);
			glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

			glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(Vertex), &Vertices[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(unsigned int), &Indices[0], GL_STATIC_DRAW);

			// Vertices' Positions
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
			// Vertices' UV Coords
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, UV_Coords));

			glBindVertexArray(0);

			Shader shader = Shader("engine/shaders/light.vs", "engine/shaders/light.fs");

			this->Effect_Material = Material(&shader);

			this->Effect_Material.Load_Shader(&shader);
			this->Effect_Material.Change_Cull_Mode(Material::Cull_Mode::None);
		}


		void Post_Process_Effect::Set_Material(Material* material)
		{
			this->Effect_Material = *material;
		}

		Material* Post_Process_Effect::Get_Material()
		{
			return &this->Effect_Material;
		}


		void Post_Process_Effect::Draw()
		{
			this->Effect_Material.Use();

			glBindVertexArray(this->VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}
	}
}