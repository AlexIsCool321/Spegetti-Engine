#ifndef LOGGING_REQUESTS_HPP
#define LOGGING_REQUESTS_HPP

namespace Logging
{
	void Log(const char* message, ...);
	void Warn(const char* message, ...);
	void Error(const char* message, ...);
}

#endif