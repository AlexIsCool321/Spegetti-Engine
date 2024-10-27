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

		Math::Transform Transfrom = Math::Transform(0);

		Entity();
		~Entity();

	};

}

#endif