#ifndef Spegetti_Memory_H
#define Spegetti_Memory_H

#include <iostream>
#include <vector>

namespace Spegetti_Memory
{
	template <typename Type> int Save(Type value);

	template <typename Type> Type Load(int ID);

	void Delete(int ID);

	template <typename Type> void Delete(Type value);
}

#endif // !Spegetti_Memory_H
