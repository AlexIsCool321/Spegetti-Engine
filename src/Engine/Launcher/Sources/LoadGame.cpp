#include <Launcher/LoadGame.hpp>

#include <Logging/Logging.hpp>

#include <dlfcn.h>

namespace Launcher
{
	Game::Properties* LoadGame(const char* game)
	{
		typedef Game::Properties* (*InitFunc)();
		
		std::string path = "./" + std::string(game) + "/libClient.so";

		void* handle = dlopen(path.c_str(), RTLD_LAZY | RTLD_GLOBAL);
		if (!handle)
		{
			Logging::Error("FAILED TO OPEN [ %s ]! : [ %s ]", path.c_str(), dlerror());
			return new Game::Properties();
		}

		// Clear error
		dlerror();

		InitFunc init = (InitFunc)dlsym(handle, "Init");
		const char* dlsym_error = dlerror();
		if (dlsym_error)
		{
			Logging::Error("FAILED TO LOAD SYMBOL! : [ %s ]", dlsym_error);
			dlclose(handle);
			return new Game::Properties();
		}

		Game::Properties* properties = init();

		Logging::Log("LOG : Loaded [ %s ].", properties->title);

		return properties;
	}
}