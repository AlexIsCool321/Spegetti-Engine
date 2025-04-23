#ifndef Spegetti_Entity_System_H
#define Spegetti_Entity_System_H

#include <Spegetti_Renderer.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Spegetti_Entity_System
{
	struct Entity
	{
		glm::vec3 Position;
		glm::vec3 Rotation;
		glm::vec3 Scale;

		glm::mat4 Transform;

		// Entity init
		Entity();

		// Entity init with Position and Rotation
		Entity(glm::vec3 position, glm::vec3 rotation);

		// Entity init with Position, Rotation, and Scale
		Entity(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);

		// Entity init with Transfrom
		Entity(glm::mat4 transform);


		// Starts the Entity's Logic
		void Start();

		// Updates the Entity
		void Think();

		// Removes the Entity
		void Kill();
	};
}

#endif // !Spegetti_Entity_System_H
