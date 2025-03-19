#include <Launcher.h>

int main()
{
	std::string OS_start;

#ifdef _WIN32
	OS_start = "start";
#endif // _WIN32

#ifdef __linux__ // TODO : does this work?
	OS_start = "";
#endif // __linux__

	std::string Project;

	std::cin >> Project;

	Project = OS_start + " bin/" + Project;
	system(Project.c_str());
	
	return 0;
}