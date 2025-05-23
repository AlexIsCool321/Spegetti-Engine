#include <Spegetti_Renderer.h>

using namespace Spegetti_Renderer::Graphics;

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Mesh::Mesh()
		{
			this->Vertices	= std::vector<Vertex>();
			this->material	= &Material();
			this->Indices	= std::vector<unsigned int>();
			this->Model		= glm::mat4(1.0f);

			this->Set_Up_Mesh();
		}

		Mesh::Mesh(const Mesh& other)
		{
			this->Vertices	= other.Vertices;
			this->Indices	= other.Indices;
			this->material	= other.material;

			this->Model = other.Model;

			this->Set_Up_Mesh();
		}

		Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, Material* material)
		{
			this->Vertices	= vertices;
			this->material	= material;
			this->Indices	= indices;

			this->Model		= glm::mat4(1.0f);

			this->Set_Up_Mesh();
		}

		Mesh::~Mesh()
		{
			glDeleteVertexArrays(1, &this->VAO);
			glDeleteBuffers(1, &this->VBO);
			glDeleteBuffers(1, &this->EBO);
		}


		Mesh Mesh::operator=(const Mesh& other) const
		{
			if (this != &other)
			{
				return Mesh(other.Vertices, other.Indices, other.material);
			}
			return *this;
		}
		

		void Mesh::Set_Up_Mesh()
		{
			glGenVertexArrays(1, &this->VAO);
			glGenBuffers(1, &this->VBO);
			glGenBuffers(1, &this->EBO);

			glBindVertexArray(this->VAO);
			glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

			glBufferData(GL_ARRAY_BUFFER, this->Vertices.size() * sizeof(Vertex), &this->Vertices[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->Indices.size() * sizeof(unsigned int), &this->Indices[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->Indices.size() * sizeof(unsigned int), &this->Indices[0], GL_STATIC_DRAW);
			
			// Vertices' Positions
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
			// Vertices' Normals
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
			// Vertices' UV Coords
			glEnableVertexAttribArray(2);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, UV_Coords));
			// Vertices' Tangents
			glEnableVertexAttribArray(3);
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
			// Vertices' Bitangents
			glEnableVertexAttribArray(4);
			glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));

			glBindVertexArray(0);
		}


		void Mesh::Set_View_Position(glm::vec3 view)
		{
			this->material->Set_Vector3("view_position", view);
		}
		
		void Mesh::Set_View_Matrix(glm::mat4 view)
		{
			this->material->Set_Mat4("view", view);
		}

		void Mesh::Set_Projection(glm::mat4 projection)
		{
			this->material->Set_Mat4("projection", projection);
		}


		void Mesh::Draw()
		{
			this->material->Use();
			this->material->Set_Mat4("model", this->Model);

			glBindVertexArray(this->VAO);
			glDrawElements(GL_TRIANGLES, (GLsizei)this->Indices.size(), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}
	}
}