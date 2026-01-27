#include <Engine/Engine.hpp>

#include <Engine/Model.hpp>

Properties* Init()
{
	Properties* properties = new Properties();
		
	properties->title = "Engine";

	properties->entityRegistry->RegisterEntity<Engine::Model>("Model");

	Engine::Global_Properties = properties;
	return properties;
}