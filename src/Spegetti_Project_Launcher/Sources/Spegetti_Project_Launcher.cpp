#include <Spegetti_Renderer.h>
#include <Spegetti_Console.h>
#include <Spegetti_Files.h>

#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace Spegetti_Renderer;
using namespace Graphics;
using namespace OS;

using namespace Spegetti_Console;

using namespace Spegetti_Files;

int main()
{
	Init();

	Window window = Window("Game", 1200, 800);
	
	Shader* shader = &Shader("engine/shaders/pbr.vs", "engine/shaders/pbr.fs");
	Material material = Material(shader, 1);

	std::vector<Vertex> vertices =
	{
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), 1, glm::vec3(0, 0, 1), glm::vec2(0, 0)), // Bottom Left
		Vertex(glm::vec3( 0.5f, -0.5f, 0.0f), 1, glm::vec3(0, 0, 1), glm::vec2(1, 0)), // Bottom Right
		Vertex(glm::vec3(-0.5f,  0.5f, 0.0f), 1, glm::vec3(0, 0, 1), glm::vec2(0, 1)), // Top Left
		Vertex(glm::vec3( 0.5f,  0.5f, 0.0f), 1, glm::vec3(0, 0, 1), glm::vec2(1, 1))  // Top Right
	};
	
	std::vector<unsigned int> indices = 
	{
		3, 1, 2, // 1
		1, 0, 2  // 2	
	};
	
	std::vector<Material> materials = 
	{
		material
	};

	Mesh mesh = Mesh(vertices, indices, materials);

	while (!glfwWindowShouldClose(window.GetWindow()))
	{
		window.PushContext();
		// Render Code

		glm::mat4 transform = glm::mat4(1.0f);

		//glm::translate(transform, glm::vec3(5, 0, 0));
		glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0, 1, 0));

		mesh.Draw(transform);

		window.Update();
	}

	window.~Window();
	return 0;
}