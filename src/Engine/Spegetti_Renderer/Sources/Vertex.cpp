#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Vertex::Vertex()
		{
			this->Vertex_Group = 0;

			this->Position	= glm::vec3(0.0f);
			this->Normal	= glm::vec3(0.0f, 1.0f, 0.0f);
			
			this->UV_Coords	= glm::vec2(0.0f);

			this->Tangent	= glm::vec3(0.0f);
			this->Bitangent	= glm::vec3(0.0f);
		}

		Vertex::Vertex(glm::vec3 position, int vertex_group, glm::vec3 normal, glm::vec2 uv_coords, glm::vec3 tangent, glm::vec3 bitangent)
		{
			this->Vertex_Group	= vertex_group;

			this->Position		= position;
			this->Normal		= normal;

			this->UV_Coords		= uv_coords;

			this->Tangent		= tangent;
			this->Bitangent		= bitangent;
		}
	}
}