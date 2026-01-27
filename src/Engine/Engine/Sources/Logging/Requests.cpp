#include <Logging/Requests.hpp>

#include <cstdarg>
#include <cstdio>

namespace Logging
{
	void Log(const char* message, ...)
	{
		printf("LOG : ");
		
		va_list args;
		va_start(args, message);
		vprintf(message, args);
		printf("\n");
		va_end(args);
	}

	void Warn(const char* message, ...)
	{
		printf("WARN : ");
		
		va_list args;
		va_start(args, message);
		vprintf(message, args);
		printf("\n");
		va_end(args);
	}

	void Error(const char* message, ...)
	{
		printf("ERROR : ");
		
		va_list args;
		va_start(args, message);
		vprintf(message, args);
		printf("\n");
		va_end(args);
	}
}