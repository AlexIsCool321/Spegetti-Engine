#include <Logging/Requests.hpp>

#include <iostream>

namespace Logging
{
	void Log(const char* message, ...)
	{
		std::cout << "LOG : " << message << std::endl;
	}

	void Warn(const char* message, ...)
	{
		std::cout << "WARN : " << message << std::endl;
	}

	void Error(const char* message, ...)
	{
		std::cout << "ERROR : " << message << std::endl;
	}
}