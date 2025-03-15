#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Model::Model()
		{
			this->Transform = glm::mat4(1.0f);
		}

		Model::Model(const char* path)
		{
			this->Transform = glm::mat4(1.0f);
			this->Load_Model(path);
		}


		Model::Model(Mesh mesh)
		{
			this->Transform = glm::mat4(1.0f);
			this->Add_Mesh(mesh);
		}

		Model::Model(std::vector<Mesh> meshes)
		{
			this->Transform = glm::mat4(1.0f);

			for (int i = 0; i < meshes.size(); i++)
			{
				this->Add_Mesh(meshes[i]);
			}
		}


		Model::~Model()
		{
			for (int i = 0; i < this->Meshes.size(); i++)
			{
				this->Meshes[i].~Mesh();
			}
		}

		
		void Model::Update_Transform()
		{
			static glm::mat4 Old_Transform = this->Transform;

			for (int i = 0; i < this->Meshes.size(); i++)
			{
				this->Meshes[i].Model = this->Transform;
			}
		}


		void Model::Load_Model(const char* path)
		{
			std::string file;
			std::ifstream stream(path, std::ios::in);

			std::vector<glm::vec3> Positions;
			std::vector<glm::vec3> Normals;
			std::vector<glm::vec2> UV_Coords;

			std::vector<unsigned int> Indices;
			std::vector<unsigned int> Normal_Indices;
			std::vector<unsigned int> UV_Indices;

			bool Writing_To_Mesh = false;
			int Mesh_Index = 0;

			Material material = Material("engine/materials/default.mat");

			if (stream.is_open())
			{
				std::string line = "";
				while (std::getline(stream, line))
				{
					if (First_Token(line) == "v") // Positions
					{
						glm::vec3 Position;
						Position.x = std::stof(Split(line, 1, ' '));
						Position.y = std::stof(Split(line, 2, ' '));
						Position.z = std::stof(Split(line, 3, ' '));

						Positions.push_back(Position);
					}
					
					if (First_Token(line) == "vn") // Normals
					{
						glm::vec3 Normal;
						Normal.x = std::stof(Split(line, 1, ' '));
						Normal.y = std::stof(Split(line, 2, ' '));
						Normal.z  = std::stof(Split(line, 3, ' '));

						Normals.push_back(Normal);
					}
					
					if (First_Token(line) == "vt") // UV Coords
					{
						glm::vec2 UV_Coord;
						UV_Coord.x = std::stof(Split(line, 1, ' '));
						UV_Coord.y = std::stof(Split(line, 2, ' '));

						UV_Coords.push_back(UV_Coord);
					}
					
					if (First_Token(line) == "f") // Faces / Indices
					{
						for (int i = 0; i < 3; i++)
						{
							std::string face = Split(line, i + 1, ' ');

							Indices			.push_back(std::stoi(Split(face, 2, '/')));
							Normal_Indices	.push_back(std::stoi(Split(face, 0, '/')));
							UV_Indices		.push_back(std::stoi(Split(face, 1, '/')));

						}
					}
				} 
				stream.close();

				std::vector<Vertex> Vertices;

				for (int i = 0; i < Indices.size(); i++)
				{
					Vertex vertex;

					std::cout << Positions[Indices[i] - 1].x << std::endl;
					vertex.Position = Positions[Indices[i] - 1];
					//vertex.Normal = Normals[Normal_Indices[i]];
					vertex.UV_Coords = UV_Coords[UV_Indices[i] - 1];

					Vertices.push_back(vertex);
				}

				this->Meshes.push_back(Mesh
				(
					Vertices,
					Indices,
					material
				));
			}
			else
			{
				Error("FAILE TO LOAD MODEL : [ " + (std::string)path + " ]");
			}
		}
		 

		void Model::Add_Mesh(Mesh mesh)
		{
			this->Meshes.push_back(mesh);
		}


		void Model::Set_Material(Material material, int mesh_index)
		{
			this->Meshes[mesh_index].material = material;
		}

		void Model::Set_Material(Material material)
		{
			for (int i = 0; i < this->Meshes.size(); i++)
			{
				this->Meshes[i].material = material;
				this->Meshes[i].Set_Up_Mesh();
			}
		}
	}
}