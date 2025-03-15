#ifndef Spegetti_Console_H
#define Spegetti_Console_H

#include <iostream>
#include <string>

namespace Spegetti_Console
{
	// Sends a Message to the Console
	void Log(std::string message);

	// Sends a Warning to the Console
	void Warn(std::string message);

	// Sends an Error to the Console
	void Error(std::string message);

	// Sends an Error to the Console and closes the program
	void Fatal_Error(std::string message);


	// Creates a callable Command for the Console
	void Create_Command();

	// Call a specified Command
	void Call_Command();
}

#endif // !Spegetti_Console_H
