#ifndef Spegetti_Renderer_H
#define Spegetti_Renderer_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <fstream>
#include <sstream>

#include <iostream>
#include <vector>

#include <Spegetti_Console.h>
#include <Spegetti_Files.h>

using namespace Spegetti_Console;
using namespace Spegetti_Files;

namespace Spegetti_Renderer
{
	// Init Spegetti Renderer
	void Init_Spegetti_Renderer();

	// Quit Spegetti Renderer
	void Quit_Spegetti_Renderer();
	
	namespace Graphics
	{
		struct Vertex
		{
			int Vertex_Group;

			glm::vec3 Position;
			glm::vec3 Normal;

			glm::vec2 UV_Coords;
			
			// Vertex init
			Vertex();

			// Vertex init with Position, Vertex Group, Normal, and UV Coords
			Vertex(glm::vec3 position, int vertex_group, glm::vec3 normal, glm::vec2 uv_coords);
		};

		struct Shader
		{
			std::string Vertex_Shader;
			std::string Fragment_Shader;

			// Shader init
			Shader(const char* vertex_path, const char* fragment_path);
			
			// Shader init with std::string
			Shader(std::string vertex_path, std::string fragment_path);
		};
		
		class Texture
		{
		private:
			unsigned int ID;

		public:
			int Width, Height, Channels;

			// Texture init
			Texture();
			
			// Texture init with Texture Path
			Texture(const char* texture_path);
			
			// Texture deconstructor
			~Texture();


			// Load a Texture from the specified Path
			void Load_Texture(const char* texture_path);

			// Get the ID of the Texture
			unsigned int Get_ID();
		};

		class Material
		{
		private:
			unsigned int ID;

		public:
			// Material init
			Material();

			// Material init with Shader
			Material(Shader* shader);
			
			// Material init with material_path
			Material(const char* material_path);


			// Load a Shader
			void Load_Shader(Shader* shader);

			// Load a Material from a File
			void Load_Material(const char& path);
			

			// Forces OpenGl to Use this Material
			void Use();


			// Returns if the specified Uniform is in the Shader
			bool Has_Uniform(const char* name);


			// Sets a Bool Uniform in the Shader
			void Set_Bool(const char* name, bool value) const;

			// Sets a Int Uniform in the Shader
			void Set_Int(const char* name, int value) const;

			// Sets a Float Uniform in the Shader
			void Set_Float(const char* name, float value) const;


			// Sets a Vec2 Uniform in the Shader
			void Set_Vector2(const char* name, glm::vec2 value) const;

			// Sets a Vec3 Uniform in the Shader
			void Set_Vector3(const char* name, glm::vec3 value) const;

			// Sets a Vec4 Uniform in the Shader
			void Set_Vector4(const char* name, glm::vec4 value) const;


			// Sets a Mat2 Uniform in the Shader
			void Set_Mat2(const char* name, glm::mat2 value) const;

			// Sets a Mat3 Uniform in the Shader
			void Set_Mat3(const char* name, glm::mat3 value) const;

			// Sets a Mat4 Uniform in the Shader
			void Set_Mat4(const char* name, glm::mat4 value) const;


			// Sets a Sampler2D Uniform in the Shader
			void Set_Texture(const char* name, Texture* texture) const;
		};

		struct Mesh
		{
			std::vector<Vertex> Vertices;
			std::vector<unsigned int> Indices;
			Material material;
			
			std::string Name;

			unsigned int VAO, VBO, EBO;

			glm::mat4 Model;

			// Mesh init
			Mesh();

			// Mesh init with Mesh
			Mesh(const Mesh& mesh);

			// Mesh init with Vertices, Indices, and Materials
			Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, Material material);

			// Mesh deconstructor
			~Mesh();


			// Mesh = eqation
			Mesh operator=(const Mesh &other) const;
			

			// Sets up the Mesh
			void Set_Up_Mesh();


			// Set the the View that the Mesh will be Drawn at
			void Set_View_Direction(glm::mat4 view);

			// Set the the Projection that the Mesh will be Drawn at
			void Set_Projection(glm::mat4 projection);


			// Draw the Mesh
			void Draw();
		};
		
		struct Model
		{
			std::vector<Mesh> Meshes;

			glm::mat4 Transform;

			// Model init
			Model();

			// Model init with Model Path
			Model(const char* path);

			// Model init with a Mesh
			Model(Mesh mesh);

			// Model init with multiple Meshes
			Model(std::vector<Mesh> meshes);

			// Model deconstructor
			~Model();
			
			
			// Update Transform
			void Update_Transform();


			// Load a Model from a specified Path
			void Load_Model(const char* path);


			// Add a Mesh to the Model
			void Add_Mesh(Mesh mesh);

			// Apply a Material to a specified Mesh
			void Set_Material(Material material, int mesh_index);

			// Apply a Material to all Meshes in the Model
			void Set_Material(Material material);
		};

		struct Camera
		{
			bool Active = true;

			std::vector<Model*> Model_Draw_Stack;
			std::vector<Mesh*> Mesh_Draw_Stack;

			glm::mat4 View			= glm::mat4(1.0f);
			glm::mat4 Projection	= glm::mat4(1.0f);

			glm::vec3 Position = glm::vec3(0.0f);
			glm::vec3 Rotation = glm::vec3(0.0f);

			glm::vec3 Front	= glm::vec3(0.0f);
			glm::vec3 Right	= glm::vec3(0.0f);
			glm::vec3 Up	= glm::vec3(0.0f);

			// Camera init
			Camera();

			// Camera deconstructor
			~Camera();


			// Updates the View matrix using the Position and Rotation vectors
			void Update_View();

			// Add a Mesh to the Camera's draw stack
			void Add_Mesh_To_Draw_Stack(Mesh* mesh);

			// Add a Model to the Camera's draw stack
			void Add_Model_To_Draw_Stack(Model* mesh);


			// Recompiles all Models and Meshes in the Camera's draw stack
			void Reload_Models();


			// Draw the Camera's draw stack
			void Draw();
		};

		// Debug Mesh
		Mesh Debug_Quad();
	}

	namespace OS
	{
		class Window
		{
		private:
			
			GLFWwindow* GLFW_Window;

		public:
			// Window init
			Window(const char* name, const int width, const int height);
			
			// Window deconstructor
			~Window();


			// Returns the GLFW Window
			GLFWwindow* Get_Window();

			// Should the window close
			bool Should_Close();

			// Force close the window
			void Close_Window();


			// Updates imported GLFW Window functions
			void Update();

			// Forces the context of the Window
			void Push_Context();
		};
	}
}

#endif // !Spegetti_Renderer_H