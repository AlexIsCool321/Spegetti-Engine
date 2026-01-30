#include <Logging/Requests.hpp>

#include <stdarg.h>
#include <stdio.h>

#include <ctype.h>

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

		char buffer[1024];

		va_list args;
		va_start(args, message);
		vsnprintf(buffer, sizeof(buffer), message, args);
		va_end(args);

		for (int i = 0; buffer[i] != '\0'; i++)
		{
			unsigned char c = (unsigned char)buffer[i];
			buffer[i] = toupper(c);
		}

		printf("%s\n", buffer);
	}
}