#include <System/Init.hpp>

#include <System/Specific/SDL3/SDL3_Init.hpp>

namespace System
{
	void Init()
	{
		SDL3_Init();
	}

	void Terminate()
	{
		SDL3_Terminate();
	}
}