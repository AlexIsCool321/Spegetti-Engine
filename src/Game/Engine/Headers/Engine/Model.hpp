#ifndef MODEL_HPP
#define MODEL_HPP

#include <Engine/Engine.hpp>

namespace Engine
{
	class Model : public Entity
	{
	private:
		Renderer::Model* m_model;
		
	public:
		void OnCreate();
		void OnUpdate();
		void OnDestroy();
	};
}

#endif