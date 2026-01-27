#include <Launcher/specific/linux/Linux_GameClient.hpp>

#include <Logging/Logging.hpp>

#include <string.h>
#include <dlfcn.h>

namespace Launcher
{
	Linux_GameClient::Linux_GameClient(const char* game)
	{
		typedef Game::Properties* (*InitFunc)();
		
		char path[256];
		snprintf(path, sizeof(path), "./%s/libClient.so", game);

		this->m_handle = dlopen(path, RTLD_LAZY | RTLD_GLOBAL);
		if (!this->m_handle)
		{
			Logging::Error("FAILED TO OPEN [ %s ]! : [ %s ]", path, dlerror());
			return;
		}

		// Clear error
		dlerror();

		InitFunc init = (InitFunc)dlsym(this->m_handle, "Init");
		const char* dlsym_error = dlerror();
		if (dlsym_error)
		{
			Logging::Error("FAILED TO LOAD SYMBOL! : [ %s ]", dlsym_error);
			dlclose(this->m_handle);
			return;
		}

		this->m_properties = init();

		Logging::Log("LOG : Loaded [ %s ].", this->m_properties->title);
	}

	Linux_GameClient::~Linux_GameClient()
	{
		dlclose(this->m_handle);

		Logging::Log("LOG : Unloaded [ %s ].", this->m_properties->title);

		delete this->m_properties;
	}
}