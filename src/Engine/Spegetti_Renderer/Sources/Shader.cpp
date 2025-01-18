#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Shader::Shader(std::string vertex_path, std::string fragment_path)
		{
			this->vertex_shader = vertex_path;
			this->fragment_shader = fragment_path;
		};
	}
}