#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Vertex::Vertex(glm::vec3 Position, int Vertex_Group, glm::vec3 Normal, glm::vec2 UV_Coords)
		{
			this->Position = Position;
			this->Vertex_Group = Vertex_Group;
			this->Normal = Normal;
			this->UV_Coords = UV_Coords;
		}
	}
}