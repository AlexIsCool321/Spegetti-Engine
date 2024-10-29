#ifndef Entity_System_H
#define Entity_System_H

#include <iostream>
#include <Spegetti.h>

using namespace Spegetti;

namespace Entity_System
{

	class Entity
	{

	public:

		Math::Transform2 Transfrom = Math::Transform2(0);

		Entity();
		~Entity();

	};

}

#endif