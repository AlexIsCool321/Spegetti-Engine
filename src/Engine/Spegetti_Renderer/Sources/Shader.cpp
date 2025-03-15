#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Shader::Shader(const char* vertex_path, const char* fragment_path)
		{
			this->Vertex_Shader = vertex_path;
			this->Fragment_Shader = fragment_path;
		};

		Shader::Shader(std::string vertex_path, std::string fragment_path)
		{
			this->Vertex_Shader = vertex_path;
			this->Fragment_Shader = fragment_path;
		};
	}
}