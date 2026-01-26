#ifndef RENDERER_MODEL_HPP
#define RENDERER_MODEL_HPP

#include <vector>
#include <Renderer/Mesh.hpp>

namespace Renderer
{
	class Model
	{
	private:
		std::vector<Mesh*> m_meshes;

	public:
		Model();
		virtual ~Model();

		virtual void AddMesh(Mesh* mesh);

		virtual void Draw();
	};
}

#endif