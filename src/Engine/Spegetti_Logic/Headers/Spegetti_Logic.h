#ifndef Spegetti_Logic_H
#define Spegetti_Logic_H

namespace Spegetti_Logic
{
	// Gets the FPS
	int Get_FPS();

	// Updates the Delta
	void Update_Delta();

	// Returns the Delta between Frames in Seconds
	double Get_Delta();

	class Resource
	{
	public:
		// Resource init
		Resource()
		{

		}

		// Resource deconstructor
		~Resource()
		{

		}
	};
}

#endif // !Spegetti_Logic_H
