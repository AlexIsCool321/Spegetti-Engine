#include <Spegetti_Console.h>

namespace Spegetti_Console
{
	void Log(std::string message)
	{
		std::cout << "LOG : " << message << std::endl;
	}

	void Warn(std::string message)
	{
		std::cout << "WARN : " << message << "!" << std::endl;
	}

	void Error(std::string message)
	{
		std::cout << "!ERROR! : " << message << "!" << std::endl;
	}

	void Fatal_Error(std::string message)
	{
		std::cout << "==!!!FATAL ERROR!!!== : " << message << "! [=!ENGINE STOP!=]" << std::endl;
		abort();
	}


	void Create_Command()
	{
		return;
	}

	void Call_Command()
	{
		return;
	}
}