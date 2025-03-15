#ifndef Spegetti_Files_H
#define Spegetti_Files_H

#include <iostream>
#include <vector>

#include <string>
#include <sstream>

namespace Spegetti_Files
{
	// Returns the specified file as a std::string
	std::string Read_File(std::string filepath);

	// Returns the first Token from a std::string
	std::string First_Token(const std::string string);

	// Returns the last Token from a std::string
	std::string Last_Token(const std::string string);

	// Splits a std::string by a specified character
	std::string Split(const std::string& string, const int token, const char delimiter);
}

#endif // !Spegetti_Files_H
