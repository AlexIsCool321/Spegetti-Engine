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
		}

		Texture::Texture(const char* texture_path)
		{
			this->ID = 0;
			this->Width = 0;
			this->Height = 0;
			this->Channels = 0;

			this->Load_Texture(texture_path);
		}

		Texture::~Texture()
		{
			glDeleteTextures(1, &this->ID);
		}


		void Texture::Load_Texture(const char* texture_path)
		{
			glGenTextures(1, &this->ID);
			glBindTexture(GL_TEXTURE_2D, this->ID);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			
			unsigned char* data = stbi_load(texture_path, &this->Width, &this->Height, &this->Channels, 0);
			if (data)
			{
				GLenum format = (this->Channels == 3) ? GL_RGB : GL_RGBA;
				glTexImage2D(GL_TEXTURE_2D, 0, format, this->Width, this->Height, 0, format, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			else
			{
				this->ID = 0;
				Error("Failed to load texture" + (std::string)texture_path);
			}
			
			stbi_image_free(data);
		}


		unsigned int Texture::Get_ID()
		{
			return this->ID;
		}
	}
}