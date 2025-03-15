#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Material::Material()
		{
			this->ID = 0;
			Shader shader = Shader("engine/shaders/pbr.vs", "engine/shaders/pbr.fs");
			this->Load_Shader(&shader);
		}

		Material::Material(Shader* shader)
		{
			this->Load_Shader(shader);
		}

		Material::Material(const char* material_path)
		{
			this->Load_Material(*material_path);
		}

		void Material::Load_Material(const char& path)
		{
			std::string file;
			std::ifstream stream(&path, std::ios::in);

			if (stream.is_open())
			{
				std::string line = "";

				while (std::getline(stream, line))
				{
					if (First_Token(line) == "shader")
					{
						if (!(Split(line, 1, ' ') == "" || Split(line, 2, ' ') == ""))
						{
							Shader shader = Shader(Split(line, 1, ' '), Split(line, 2, ' '));
							this->Load_Shader(&shader);
						}
					}

					if (First_Token(line) == "texture")
					{
						Texture texture = Texture(Split(line, 2, ' ').c_str());
						this->Set_Texture(Split(line, 1, ' ').c_str(), &texture);
					}

					if (First_Token(line) == "bool")
					{
						this->Set_Bool(Split(line, 1, ' ').c_str(), std::stoi(Split(line, 2, ' ')));
					}

					if (First_Token(line) == "float")
					{
						this->Set_Float(Split(line, 1, ' ').c_str(), std::stof(Split(line, 2, ' ')));
					}

					if (First_Token(line) == "int")
					{
						this->Set_Int(Split(line, 1, ' ').c_str(), std::stoi(Split(line, 2, ' ')));
					}

					if (First_Token(line) == "vec2")
					{
						glm::vec2 vector = glm::vec2(std::stof(Split(line, 2, ' ')), std::stof(Split(line, 3, ' ')));
						this->Set_Vector2(Split(line, 1, ' ').c_str(), vector);
					}

					if (First_Token(line) == "vec3")
					{
						glm::vec3 vector = glm::vec3(std::stof(Split(line, 2, ' ')), std::stof(Split(line, 3, ' ')), std::stof(Split(line, 4, ' ')));
						this->Set_Vector3(Split(line, 1, ' ').c_str(), vector);
					}

					if (First_Token(line) == "vec4")
					{
						glm::vec4 vector = glm::vec4(std::stof(Split(line, 2, ' ')), std::stof(Split(line, 3, ' ')), std::stof(Split(line, 4, ' ')), std::stof(Split(line, 5, ' ')));
						this->Set_Vector4(Split(line, 1, ' ').c_str(), vector);
					}
				}
			}
			else
			{
				Error("FAILED TO LOAD MAERIAL : [ " + (std::string)&path + " ]");
			}

			stream.close();

			this->Use();
		}


		void Material::Use()
		{
			glUseProgram(this->ID);
		}


		void Material::Load_Shader(Shader* shader)
		{
			if (shader == nullptr) return;

			// Get Shader Sources
			std::string vertexSource	= Read_File(shader->Vertex_Shader);
			std::string fragmentSource	= Read_File(shader->Fragment_Shader);
			
			const char* vertexShaderSource = vertexSource.c_str();
			const char* fragmentShaderSource = fragmentSource.c_str();

			// Vertex Shader
			unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
			glCompileShader(vertexShader);
			
			int success;
			char reason[512];
			glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(vertexShader, 512, NULL, reason);
				std::string reason_string = reason;
				Error("FAILED TO COMPILE VERTEX SHADER : [ " + reason_string + " ]");
			}

			// Fragement Shader
			unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
			glCompileShader(fragmentShader);

			glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(fragmentShader, 512, NULL, reason);
				std::string reason_string = reason;
				Error("FAILED TO COMPILE FRAGMENT SHADER : [ " + reason_string + " ]");
			}

			// Shader Program
			this->ID = glCreateProgram();
			glAttachShader(this->ID, vertexShader);
			glAttachShader(this->ID, fragmentShader);
			glLinkProgram(this->ID);

			glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
			if (!success) {
				glGetProgramInfoLog(this->ID, 512, NULL, reason);
				std::string reason_string = reason;
				Error("FAILED TO LINK SHADERS : [ " + reason_string + " ]");
			}
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			glUseProgram(this->ID);
		}


		bool Material::Has_Uniform(const char* name)
		{
			return (glGetUniformLocation(this->ID, name) != -1);
		}


		void Material::Set_Bool(const char* name, bool value) const
		{
			glUniform1i(glGetUniformLocation(this->ID, name), (int)value);
		}

		void Material::Set_Int(const char* name, int value) const
		{
			glUniform1i(glGetUniformLocation(this->ID, name), value);
		}

		void Material::Set_Float(const char* name, float value) const
		{
			glUniform1f(glGetUniformLocation(this->ID, name), value);
		}


		void Material::Set_Vector2(const char* name, glm::vec2 value) const
		{
			glUniform2f(glGetUniformLocation(this->ID, name), value.x, value.y);
		}

		void Material::Set_Vector3(const char* name, glm::vec3 value) const
		{
			glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z);
		}

		void Material::Set_Vector4(const char* name, glm::vec4 value) const
		{
			glUniform4f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z, value.w);
		}


		void Material::Set_Mat2(const char* name, glm::mat2 value) const
		{
			glUniformMatrix2fv(glGetUniformLocation(this->ID, name), 1, GL_FALSE, glm::value_ptr(value));
		}

		void Material::Set_Mat3(const char* name, glm::mat3 value) const
		{
			glUniformMatrix3fv(glGetUniformLocation(this->ID, name), 1, GL_FALSE, glm::value_ptr(value));
		}

		void Material::Set_Mat4(const char* name, glm::mat4 value) const
		{
			glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, GL_FALSE, glm::value_ptr(value));
		}


		void Material::Set_Texture(const char* name, Texture* texture) const
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture->Get_ID());

			glUniform1i(glGetUniformLocation(this->ID, name), texture->Get_ID());
		}
	}
}