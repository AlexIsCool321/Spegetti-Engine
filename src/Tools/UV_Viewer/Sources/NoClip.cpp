#include <NoClip.h>

#define PI 3.1415926

float Speed = 3.0f;

void Mouse_Wheel(GLFWwindow* window, double wheel_x, double wheel_y)
{
	Speed += (float)wheel_y * (Speed * 0.25f);

	if (Speed < 0.25)
		Speed = 0.25;

	if (Speed > 100)
		Speed = 100;
}

double Mouse_X(Window* window)
{
	static double Old_Mouse_X = 0;
	
	double Position_X, Position_Y;
	glfwGetCursorPos(window->Get_Window(), &Position_X, &Position_Y);
	
	double Mouse_Motion_X = Old_Mouse_X - Position_X;

	Old_Mouse_X = Position_X;

	return Mouse_Motion_X;
}

double Mouse_Y(Window* window)
{
	static double Old_Mouse_Y = 0;

	double Position_X, Position_Y;
	glfwGetCursorPos(window->Get_Window(), &Position_X, &Position_Y);

	double Mouse_Motion_Y = Old_Mouse_Y - Position_Y;

	Old_Mouse_Y = Position_Y;

	return Mouse_Motion_Y;
}

void FreeCam(Camera* camera, Window* window)
{
	//Inputs
	int Forward = 0;
	int Backward = 0;
	int Left = 0;
	int Right = 0;

	int Up = 0;
	int Down = 0;


	// Camera
	const double Sensitivity = 0.005;

	double Moved_X = Mouse_X(window) * Sensitivity;
	double Moved_Y = Mouse_Y(window) * Sensitivity;
	
	if (glfwGetMouseButton(window->Get_Window(), GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
	{
		glfwSetInputMode(window->Get_Window(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		camera->Rotation.y -= (float)Moved_X;
		camera->Rotation.x += (float)Moved_Y;
	}
	else
	{
		glfwSetInputMode(window->Get_Window(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	}
	camera->Rotation.x = glm::clamp(camera->Rotation.x, (float)-PI / 2, (float)PI / 2);


	// Movement Speed
	
	glfwSetScrollCallback(window->Get_Window(), Mouse_Wheel);


	// Movement
	
	Forward		= glfwGetKey(window->Get_Window(), GLFW_KEY_W)				== GLFW_PRESS ? 0 : 1;
	Backward	= glfwGetKey(window->Get_Window(), GLFW_KEY_S)				== GLFW_PRESS ? 0 : 1;
	Left		= glfwGetKey(window->Get_Window(), GLFW_KEY_A)				== GLFW_PRESS ? 0 : 1;
	Right		= glfwGetKey(window->Get_Window(), GLFW_KEY_D)				== GLFW_PRESS ? 0 : 1;

	Up			= glfwGetKey(window->Get_Window(), GLFW_KEY_SPACE)			== GLFW_PRESS ? 0 : 1;
	Down		= glfwGetKey(window->Get_Window(), GLFW_KEY_LEFT_CONTROL)	== GLFW_PRESS ? 0 : 1;
	
	glm::vec3 Input_Direction = glm::vec3
	(
		Right	- Left,
		Up		- Down,
		Forward	- Backward
	);

	camera->Position -= Input_Direction.z * camera->Front	* glm::vec3(Speed) * glm::vec3((float)Get_Delta());
	camera->Position -= Input_Direction.y * camera->Up		* glm::vec3(Speed) * glm::vec3((float)Get_Delta());
	camera->Position -= Input_Direction.x * camera->Right	* glm::vec3(Speed) * glm::vec3((float)Get_Delta());

	camera->Update_View();
}