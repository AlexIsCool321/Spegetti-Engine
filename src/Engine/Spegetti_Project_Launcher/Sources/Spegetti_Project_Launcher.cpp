#include <Spegetti_Project_Launcher.h>

int main()
{
	Init();

	Window window = Window("Game", 1200, 800);
	
	Shader shader = Shader("engine/shaders/pbr.vs", "engine/shaders/pbr.fs");
	Material material = Material(shader);
	
	Camera* camera = &Camera();
	
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
	
	float x = 0;

	bool forward = false;
	bool backward = false;

	material.SetTexture("albedo", "engine/textures/crowbar/albedo.png");

	while (!glfwWindowShouldClose(window.GetWindow()))
	{
		std::cout << GetFPS() << std::endl;
		window.PushContext();
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		// Render Code

		FreeCam(camera);
		
		mesh.model = glm::rotate(mesh.model, (float)glfwGetTime() * GetDelta(), glm::vec3(0, 0, 1));

		camera->Draw(&mesh);
		window.Update();
	}
	
	window.~Window();
	return 0;
}