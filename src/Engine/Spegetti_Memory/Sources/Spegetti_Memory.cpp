#include <Spegetti_Memory.h>

template <typename Type> std::vector<Type> values;

namespace Spegetti_Memory
{
	template <typename Type> int Save(Type value)
	{
		while (true)
		{
			for (int i = 0; i < values.size(); i++)
			{
				if (values[i] == value)
				{
					return i;
				}
			}

			values.push_back(value);
		}
	}

	template <typename Type> Type Load(int ID)
	{
		return values[i];
	}

	void Delete(int ID)
	{
		
	}

	template <typename Type> void Delete(Type value)
	{

	}
}