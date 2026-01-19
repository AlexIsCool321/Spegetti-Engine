#include <Launcher/LoadGame.hpp>

#include <dlfcn.h>
#include <iostream>

namespace Launcher
{
	Game::Properties* LoadGame(const char* game)
	{
		typedef Game::Properties* (*InitFunc)();
		
		std::string path = "./" + std::string(game) + "/libClient.so";

		void* handle = dlopen(path.c_str(), RTLD_LAZY | RTLD_GLOBAL);
		if (!handle)
		{
			std::cout << "ERROR : FAILED TO OPEN [ " << path << " ]! : [ " << dlerror() << " ]" << std::endl;
			return nullptr;
		}

		// Clear error
		dlerror();

		InitFunc init = (InitFunc)dlsym(handle, "Init");
		const char* dlsym_error = dlerror();
		if (dlsym_error)
		{
			std::cout << "ERROR : FAILED TO LOAD SYMBOL! : [ " << dlsym_error << " ]" << std::endl;
			dlclose(handle);
			return nullptr;
		}

		Game::Properties* properties = init();

		std::cout << "LOG : Loaded [ " << properties->title << " ]." << std::endl;

		return properties;
	}
}