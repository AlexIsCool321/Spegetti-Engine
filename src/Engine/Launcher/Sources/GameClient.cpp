#include <Launcher/GameClient.hpp>

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
}