#include <Spegetti_Logic.h>

#include <GLFW/glfw3.h>

#include <iostream>

double deltaTime = 0;

namespace Spegetti_Logic
{
	int Get_FPS()
	{
		static int frames = 0;
		static int Old_FPS = -1;
		static double Old_Time = 0;

		if (glfwGetTime() - Old_Time > 1)
		{
			Old_Time = glfwGetTime();
			Old_FPS = frames;
			frames = 0;
			return Old_FPS;
		}
		else
		{
			frames++;
			return Old_FPS;
		}
	}

	void Update_Delta()
	{
		static double Old_Time = 0;

		deltaTime = glfwGetTime() - Old_Time;
		Old_Time = glfwGetTime();
	}

	double Get_Delta()
	{
		return deltaTime;
	}
}