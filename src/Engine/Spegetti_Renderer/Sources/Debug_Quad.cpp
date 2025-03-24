#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Mesh Debug_Quad()
		{
			Material material = Material();

			std::vector<Vertex> vertices =
			{
				Vertex(glm::vec3(	-1.0f,	-1.0f,	0.0f	), 1, glm::vec3(	1,	0,	0	), glm::vec2(	0,	0	)),	// Bottom Left
				Vertex(glm::vec3(	 1.0f,	-1.0f,	0.0f	), 1, glm::vec3(	1,	0,	0	), glm::vec2(	1,	0	)),	// Bottom Right
				Vertex(glm::vec3(	-1.0f,	 1.0f,	0.0f	), 1, glm::vec3(	1,	0,	0	), glm::vec2(	0,	1	)),	// Top Left
				Vertex(glm::vec3(	 1.0f,	 1.0f,	0.0f	), 1, glm::vec3(	1,	0,	0	), glm::vec2(	1,	1	))	// Top Right
			};
			
			std::vector<unsigned int> indices =
			{
				3, 1, 2,	// 1
				1, 0, 2		// 2	
			};

			return Mesh
			(
				vertices,
				indices,
				material
			);
		}
	}
}