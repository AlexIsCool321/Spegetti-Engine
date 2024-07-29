#pragma once

#include "Sources/Spegetti Engine.cpp"

#include "Sources/Camera.cpp"

namespace Spegetti_Engine
{

	void Init();

	namespace Entities
	{
		class Camera
		{
		public:

			Camera();

			void Start();

			void Update();

			void Destroy();

			~Camera();

		private:



		};
	}
}