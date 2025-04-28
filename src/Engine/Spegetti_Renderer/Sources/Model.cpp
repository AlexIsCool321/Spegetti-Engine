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

			//std::vector<glm::vec3> Tangent;
			//std::vector<glm::vec3> Bitangent;

			std::vector<unsigned int> Indices;
			std::vector<unsigned int> Normal_Indices;
			std::vector<unsigned int> UV_Indices;
			std::vector<unsigned int> Tangent_Indices;

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

							Indices			.push_back(std::stoi(Split(face, 0, '/')) - 1);
							UV_Indices		.push_back(std::stoi(Split(face, 1, '/')) - 1);
							Normal_Indices	.push_back(std::stoi(Split(face, 2, '/')) - 1); 
						}
						/*
						glm::vec3 edge1 = Positions[Indices[Indices.size() - 1]]	- Positions[Indices[Indices.size() - 2]];
						glm::vec3 edge2 = Positions[Indices[Indices.size()]]		- Positions[Indices[Indices.size() - 2]];

						glm::vec2 deltaUV1 = UV_Coords[UV_Indices[UV_Indices.size()	- 1]]	- UV_Coords[UV_Indices[UV_Indices.size() - 2]];
						glm::vec2 deltaUV2 = UV_Coords[UV_Indices[UV_Indices.size()]]		- UV_Coords[UV_Indices[UV_Indices.size() - 2]];

						float f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
						
						glm::vec3 tangent, bitangent;

						std::cout << f << std::endl;
						tangent.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
						tangent.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
						tangent.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);

						bitangent.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
						bitangent.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
						bitangent.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);

						for (int i = 0; i < 3; i++)
						{
							Tangent.push_back(tangent);
							Bitangent.push_back(bitangent);
						}
						*/
					}
				} 
				stream.close();
				
				std::vector<Vertex> Vertices;

				std::vector<unsigned int> Out_Indices;

				for (int i = 0; i < Indices.size(); i++)
				{
					Out_Indices.push_back(i);
					
					Vertex vertex;

					vertex.Position		= Positions[Indices[i]];
					vertex.UV_Coords	= UV_Coords[UV_Indices[i]];
					vertex.Normal		= Normals[Normal_Indices[i]];

					//vertex.Tangent = Tangent[i];
					//vertex.Bitangent = Bitangent[i];

					Vertices.push_back(vertex);
				}
				//std::cout << Indices.size() << " " << Tangent.size() << " " << Bitangent.size() << std::endl;
				this->Meshes.push_back(Mesh
				(
					Vertices,
					Out_Indices,
					&material
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


		void Model::Set_Material(Material* material, int mesh_index)
		{
			this->Meshes[mesh_index].material = material;
		}

		void Model::Set_Material(Material* material)
		{
			for (int i = 0; i < this->Meshes.size(); i++)
			{
				this->Meshes[i].material = material;
				this->Meshes[i].Set_Up_Mesh();
			}
		}
	}
}