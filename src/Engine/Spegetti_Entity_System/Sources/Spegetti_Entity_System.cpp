#include <Spegetti_Entity_System.h>

namespace Spegetti_Entity_System
{
	
	Entity::Entity()
	{
		this->Position	= glm::vec3(0);
		this->Rotation	= glm::vec3(0);
		this->Scale		= glm::vec3(1);
	}

	Entity::Entity(glm::vec3 position, glm::vec3 rotation)
	{

	}

	Entity::Entity(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	{

	}

	Entity::Entity(glm::mat4 transform)
	{

	}


	void Entity::Start()
	{

	}

	void Entity::Think()
	{

	}

	void Entity::Kill() 
	{

	}
}
