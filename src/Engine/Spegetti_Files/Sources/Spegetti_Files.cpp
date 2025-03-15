#include <Spegetti_Files.h>
#include <fstream>

#include <Spegetti_Console.h>

using namespace Spegetti_Console;

namespace Spegetti_Files
{
	std::string Read_File(std::string path)
	{
		std::string file;
		std::ifstream stream(path, std::ios::in);
		if (stream.is_open())
		{
			std::string line = "";
			while (std::getline(stream, line))
			{
				file += "\n" + line;
			}
			stream.close();
		}
		else
		{
			Error("FAILE TO OPEN : [ " + path + " ]");
		}
		return file;
	}

	std::string First_Token(const std::string string)
	{
		if (!string.empty())
		{
			int token_start	= (int)string.find_first_not_of(" \t");
			int token_end	= (int)string.find_first_of(" \t", (int)token_start);
			if (token_start != std::string::npos && token_end != std::string::npos)
			{
				return string.substr(token_start, token_end - token_start);
			}
			else if (token_start != std::string::npos)
			{
				return string.substr(token_start);
			}
		}
		return "";
	}

	std::string Last_Token(const std::string string)
	{
		int token_start	= (int)string.find_first_not_of(" \t");
		int space_start	= (int)string.find_first_of(" \t", token_start);
		int tail_start	= (int)string.find_first_not_of(" \t", space_start);
		int tail_end	= (int)string.find_last_not_of(" \t");
		if (tail_start != std::string::npos && tail_end != std::string::npos)
		{
			return string.substr(tail_start, tail_end - tail_start + 1);
		}
		else if (tail_start != std::string::npos)
		{
			return string.substr(tail_start);
		}
		return "";
	}

	std::string Split(const std::string& string, const int token, const char delimiter)
	{
		std::vector<std::string> Out;
		std::string Buffer;

		std::stringstream ss(string);
		while (getline(ss, Buffer, delimiter))
		{
			Out.push_back(Buffer);
		}
		return Out[token];
	}
}