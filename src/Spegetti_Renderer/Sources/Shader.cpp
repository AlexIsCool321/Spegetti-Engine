#include <Spegetti_Renderer.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

int texture_count = 0;

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Shader::Shader(const char* vertex_path, const char* fragment_path)
		{
			// Get Shader Sources
			std::string vertexSource = ReadFile("engine/shaders/pbr.vs");
			std::string fragmentSource = ReadFile("engine/shaders/pbr.fs");

			const char* vertexShaderSource = vertexSource.c_str();
			const char* fragmentShaderSource = fragmentSource.c_str();

			// Vertex Shader
			unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
			glCompileShader(vertexShader);

			int success;
			char infoLog[512];
			glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
				std::cout << "ERROR : FAILED TO COMPILE VERTEX SHADER! : [ " << infoLog << " ]" << std::endl;
			}

			// Fragement Shader
			unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
			glCompileShader(fragmentShader);

			glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
				std::cout << "ERROR : FAILED TO COPMILE THE FRAGMENT SHADER : [ " << infoLog << " ]" << std::endl;
			}

			// Shader Program
			this->shaderProgram = glCreateProgram();
			glAttachShader(this->shaderProgram, vertexShader);
			glAttachShader(this->shaderProgram, fragmentShader);
			glLinkProgram(this->shaderProgram);

			glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
			if (!success) {
				glGetProgramInfoLog(this->shaderProgram, 512, NULL, infoLog);
				std::cout << "ERROR : FAILED TO LINK SHADES! : [ " << infoLog << " ]" << std::endl;
			}
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			glUseProgram(this->shaderProgram);
		}


		void Shader::Use()
		{
			glUseProgram(this->shaderProgram);
		}

		bool Shader::Has_Uniform(const std::string& name)
		{
			if (glGetUniformLocation(this->shaderProgram, name.c_str()) != -1)
			{
				Log(name + " |  true");
				return true;
			}
			else
			{
				Log(name + " |  false");
				return false;
			}
		}


		void Shader::SetBool(const std::string& name, bool value) const
		{
			glUniform1i(glGetUniformLocation(this->shaderProgram, name.c_str()), (int)value);
		}

		void Shader::SetInt(const std::string& name, int value) const
		{
			glUniform1i(glGetUniformLocation(this->shaderProgram, name.c_str()), value);
		}

		void Shader::SetFloat(const std::string& name, float value) const
		{
			glUniform1f(glGetUniformLocation(this->shaderProgram, name.c_str()), value);
		}


		void Shader::SetVector2(const std::string& name, glm::vec2 value) const
		{
			glUniform2f(glGetUniformLocation(this->shaderProgram, name.c_str()), value.x, value.y);
		}

		void Shader::SetVector3(const std::string& name, glm::vec3 value) const
		{
			glUniform3f(glGetUniformLocation(this->shaderProgram, name.c_str()), value.x, value.y, value.z);
		}

		void Shader::SetVector4(const std::string& name, glm::vec4 value) const
		{
			glUniform4f(glGetUniformLocation(this->shaderProgram, name.c_str()), value.x, value.y, value.z, value.w);
		}


		void Shader::SetMat2(const std::string& name, glm::mat2 value) const
		{
			glUniformMatrix2fv(glGetUniformLocation(this->shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
		}

		void Shader::SetMat3(const std::string& name, glm::mat3 value) const
		{
			glUniformMatrix3fv(glGetUniformLocation(this->shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
		}

		void Shader::SetMat4(const std::string& name, glm::mat4 value) const
		{
			glUniformMatrix4fv(glGetUniformLocation(this->shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
		}


		void Shader::SetTexture(const std::string& name, const char* texture_path)
		{
			GLint texLocation = glGetUniformLocation(this->shaderProgram, name.c_str());
			
			if (texLocation != -1) {
				int width, height, nrChannels;
				unsigned char* data = stbi_load(texture_path, &width, &height, &nrChannels, 0);
				if (!data) {
					return;
				}
	
				GLuint texture;
				glGenTextures(1, &texture);
				glBindTexture(GL_TEXTURE_2D, texture);
	
				// Texture Wrapping
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
				GLenum format = (nrChannels == 3) ? GL_RGB : GL_RGBA;
				glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
	
				stbi_image_free(data);
	
				if (texture == 0) {
					return;
				}
	
				glActiveTexture(GL_TEXTURE0 + texture_count);
	
				glBindTexture(GL_TEXTURE_2D, texture);
	
					glUniform1i(texLocation, texture_count);
					texture_count++;
				}
		}
	}
}