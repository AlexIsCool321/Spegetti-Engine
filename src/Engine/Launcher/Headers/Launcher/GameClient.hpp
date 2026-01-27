#ifndef LAUNCHER_GAMECLIENT_HPP
#define LAUNCHER_GAMECLIENT_HPP

#include <Game/Properties.hpp>

namespace Launcher
{
	class GameClient
	{
	protected:
		Game::Properties* m_properties;

	public:
		GameClient();
		~GameClient();

		virtual Game::Properties* GetPropreties();
	};

	GameClient* CreateGameClient(const char* game);
}
#endif