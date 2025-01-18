#include <Spegetti_Logic.h>

int frames = 0;
int OldFPS = -1;
float FPSOldTime = 0;

float DTOldTime = 0;

namespace Spegetti_Logic
{
    int GetFPS()
    {
        if ((float)glfwGetTime() - FPSOldTime > 1)
        {
            FPSOldTime = (float)glfwGetTime();
            OldFPS = frames;
            frames = 0;
            return OldFPS;
        }
        else
        {
            frames++;
            return OldFPS;
        }
    }

	float GetDelta()
	{
        float deltaTime = ((float)glfwGetTime() - DTOldTime);

        DTOldTime = (float)glfwGetTime();

        return deltaTime;
	}
}