#include <Spegetti_Renderer.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Texture::Texture()
		{
			this->ID = 0;
			this->Width = 0;
			this->Height = 0;
			this->Channels = 0;

			this->Load_Texture("engine/textures/debug.png", Repeat, Closest);
		}

		Texture::Texture(const char* texture_path, Texture_Repetition texture_repetition, Texture_Interpolation texture_interpolation)
		{
			this->ID = 0;
			this->Width = 0;
			this->Height = 0;
			this->Channels = 0;
			
			this->Load_Texture(texture_path, texture_repetition, texture_interpolation);
		}

		Texture::~Texture()
		{
			glDeleteTextures(1, &this->ID);
		}

		void Texture::Load_Texture(const char* texture_path, Texture_Repetition texture_repetition, Texture_Interpolation texture_interpolation)
		{
			GLint Repetition = 0;
			if (texture_repetition == Repeat)
			{
				Repetition = GL_REPEAT;
			}
			else if (texture_repetition == Extend)
			{
				Repetition = GL_CLAMP_TO_EDGE;
			}
			else if (texture_repetition == Clip)
			{
				Repetition = GL_CLAMP_TO_BORDER;
			}
			else if (texture_repetition == Mirror)
			{
				Repetition = GL_MIRRORED_REPEAT;
			}
			else
			{
				Repetition = GL_REPEAT;
			}

			GLint Interpolation = 0;
			if (texture_interpolation == Linear)
			{
				Interpolation = GL_LINEAR;
			}
			else if (texture_interpolation == Closest)
			{
				Interpolation = GL_NEAREST;
			}
			else
			{
				Interpolation = GL_LINEAR;
			}

			glActiveTexture(GL_TEXTURE1);

			glGenTextures(1, &this->ID);
			stbi_set_flip_vertically_on_load(true);
			unsigned char* data = stbi_load(texture_path, &this->Width, &this->Height, &this->Channels, 0);
			if (data)
			{
				GLenum format;
				if (this->Channels == 1)
					format = GL_RED;
				else if (this->Channels == 3)
					format = GL_RGB;
				else if (this->Channels == 4)
					format = GL_RGBA;
				else
					format = GL_RGB;
				
				glBindTexture(GL_TEXTURE_2D, this->ID);
				glTexImage2D(GL_TEXTURE_2D, 0, format, this->Width, this->Height, 0, format, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
				std::cout << this->ID << std::endl;
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Repetition);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Repetition);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Interpolation);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Interpolation);

				stbi_image_free(data);
			}
			else
			{
				Error("FAILED TO LOAD TEXTURE : [ " + std::string(texture_path) + " ]");
				stbi_image_free(data);
			}
		}


		unsigned int Texture::Get_ID()
		{
			return this->ID;
		}
	}
}