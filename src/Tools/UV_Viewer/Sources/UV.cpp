#include <UV.h>

Mesh Load_Model_UV(const char* path)
{
	std::string file;
	std::ifstream stream(path, std::ios::in);

	std::vector<glm::vec3> UV_Coords;

	std::vector<unsigned int> Indices;
	std::vector<unsigned int> Normal_Indices;
	std::vector<unsigned int> UV_Indices;

	Material material = Material("engine/materials/default.mat");

	if (stream.is_open())
	{
		std::string line = "";
		while (std::getline(stream, line))
		{
			if (First_Token(line) == "vt") // UV Coords
			{
				glm::vec3 UV_Coord;
				UV_Coord.x = std::stof(Split(line, 1, ' '));
				UV_Coord.z = std::stof(Split(line, 2, ' '));

				UV_Coords.push_back(UV_Coord);
			}

			if (First_Token(line) == "f") // Faces / Indices
			{
				for (int i = 0; i < 3; i++)
				{
					std::string face = Split(line, i + 1, ' ');

					UV_Indices.push_back(std::stoi(Split(face, 1, '/')) - 1);
				}
			}
		}
		stream.close();

		std::vector<Vertex> Vertices;

		std::vector<unsigned int> Out_Indices;
		for (int i = 0; i < UV_Indices.size(); i++)
		{
			Out_Indices.push_back(i);

			Vertex vertex;

			vertex.Position = UV_Coords[UV_Indices[i]];
			vertex.UV_Coords = glm::vec2(UV_Coords[UV_Indices[i]].x, UV_Coords[UV_Indices[i]].z);
			
			Vertices.push_back(vertex);
		}

		return Mesh(Vertices, Out_Indices, material);
	}
	else
	{
		Error("FAILE TO LOAD MODEL : [ " + (std::string)path + " ]");
		return Debug_Quad();
	}
}