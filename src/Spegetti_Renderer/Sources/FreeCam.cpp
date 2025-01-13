#include <FreeCam.h>

bool toggled = false;
glm::vec3 velocity;

void Move(Camera* camera)
{
	if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_TAB) == GLFW_TRUE)
	{
		toggled = !toggled;
	}

	if (toggled)
	{
		bool Forward = glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_W);
		bool Backward = glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_S);
		bool Left = glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_A);
		bool Right = glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_D);
		bool Up = glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_SPACE);
		bool Down = glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_LEFT_CONTROL);


		
		camera->view = glm::rotate(camera->view, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
		camera->view = glm::scale(camera->view, glm::vec3(0.5, 0.5, 0.5));

	}
}

void accelerate(glm::vec3 Wish_Velocity)
{

}