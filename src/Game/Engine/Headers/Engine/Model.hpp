#ifndef MODEL_HPP
#define MODEL_HPP

#include <Core/Core.hpp>

namespace Engine
{
	class Model : public Noodle::Entity
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