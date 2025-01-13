#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Camera::Camera()
		{
			this->Position = glm::vec3(0, 0, 0);
			this->Rotation = glm::vec3(0, 0, 0);
			this->projection = glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 0.1f, 100.0f);
			this->view = glm::mat4(1.0f);
		}


		void Camera::Draw(Mesh* mesh)
		{
			if (this->active)
			{
				//mesh->Draw(this->projection * this->view * mesh->transform);
				std::cout << glm::value_ptr(this->view) << std::endl;
				mesh->Draw(this->view);
			}
		}
	}
}