#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Light::Light()
		{
			this->Position = glm::vec3(0.0f, 0.0f, 0.0f);

			this->Color = glm::vec3(1.0f, 1.0f, 1.0f);

			this->Constant = 1.0f;
			this->Linear = 0.09f;
			this->Quadratic = 0.032f;
		}

		Light::Light(glm::vec3 position, glm::vec3 color, float Constant, float Linear, float Quadratic)
		{
			this->Position	= position;
			
			this->Color		= color;
			
			this->Constant	= Constant;
			this->Linear	= Linear;
			this->Quadratic	= Quadratic;
		}
	}
}