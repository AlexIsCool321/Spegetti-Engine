#ifndef RENDERER_RENDERSERVER_HPP
#define RENDERER_RENDERSERVER_HPP

#include <System/Window.hpp>

namespace Renderer
{
	class RenderServer
	{
	public:
		RenderServer(System::Window& window);
		virtual ~RenderServer();
	};
}

#endif