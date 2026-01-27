#ifndef LAUNCHER_LINUX_GAMECLIENT_HPP
#define LAUNCHER_LINUX_GAMECLIENT_HPP

#include <Launcher/GameClient.hpp>

namespace Launcher
{
	class Linux_GameClient : public GameClient
	{
	private:
		void* m_handle;
			
	public:
		Linux_GameClient(const char* game);
		~Linux_GameClient();
	};
}

#endif