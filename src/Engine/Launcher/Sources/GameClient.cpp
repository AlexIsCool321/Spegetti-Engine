#include <Launcher/GameClient.hpp>

#ifdef __linux__
	#include <Launcher/specific/linux/Linux_GameClient.hpp>
#endif

namespace Launcher
{
	GameClient::GameClient()
	{
		this->m_properties = nullptr;
	}

	GameClient::~GameClient()
	{
		delete this->m_properties;
	}


	Game::Properties* GameClient::GetPropreties()
	{
		return this->m_properties;
	}


	GameClient* CreateGameClient(const char* game)
	{
#ifdef __linux__
		return new Linux_GameClient(game);
#endif

		return nullptr;
	}
}