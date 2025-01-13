#ifndef Spegetti_Console_H
#define Spegetti_Console_H

#include <iostream>
#include <string>
#include <cstdlib>

namespace Spegetti_Console
{
	void Log(std::string Message);
	void Warn(std::string Message);
	void Error(std::string Message);
	void Fatal_Error(std::string Message);

	void Create_Command();
	void Call_Command();
}

#endif // !Spegetti_Console_H
