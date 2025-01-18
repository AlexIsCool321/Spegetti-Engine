#include <Spegetti_Files.h>

namespace Spegetti_Files
{
	std::string ReadFile(std::string filepath)
	{
		std::string file;
		std::ifstream stream(filepath, std::ios::in);
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
			std::cout << "ERROR : COULDN'T OPEN! : [ " << filepath << " ]" << std::endl;
		}
		return file;
	}
}