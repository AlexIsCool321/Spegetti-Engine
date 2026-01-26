#ifndef RENDERER_MESH_HPP
#define RENDERER_MESH_HPP

namespace Renderer
{
	class Mesh
	{
	public:
		Mesh();
		virtual ~Mesh();

		virtual void Draw();
	};
}

#endif