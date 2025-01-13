#include <Spegetti_Console.h>

namespace Spegetti_Console
{
	void Log(std::string Message)
	{
		std::cout << "LOG : " << Message << std::endl;
	}

	void Warn(std::string Message)
	{
		std::cout << "WARN : " << Message << "!" << std::endl;
	}

	void Error(std::string Message)
	{
		std::cout << "!ERROR! : " << Message << "!" << std::endl;
	}

	void Fatal_Error(std::string Message)
	{
		std::cout << "==!!!FATAL ERROR!!!== : " << Message << "! [=!ENGINE STOP!=]" << std::endl;
		abort();
	}

	void Create_Command();
	void Call_Command();
}