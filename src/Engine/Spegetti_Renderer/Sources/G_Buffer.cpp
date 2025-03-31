#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		G_Buffer::G_Buffer(Format format, Type type, Format_Type format_type, OS::Window* window)
		{
			GLint internal_format;
			GLenum internal_type;
			GLenum internal_format_type;
			
			if (format == Red)
			{
				internal_format = GL_RED;
			}
			else if (format == RG)
			{
				internal_format = GL_RG;
			}
			else if (format == RGB)
			{
				internal_format = GL_RGB;
			}
			else if (format == RGBA)
			{
				internal_format = GL_RGBA;
			}
			else if (format == SRGB)
			{
				internal_format = GL_SRGB;
			}

			else if (format == R8)
			{
				internal_format = GL_R8;
			}
			else if (format == R16)
			{
				internal_format = GL_R16;
			}

			else if (format == RG8)
			{
				internal_format = GL_RG8;
			}

			else if (format == RG16)
			{
				internal_format = GL_RG16;
			}

			else if (format == R3_G3_B2)
			{
				internal_format = GL_R3_G3_B2;
			}
			else if (format == RGB4)
			{
				internal_format = GL_RGB4;
			}
			else if (format == RGB5)
			{
				internal_format = GL_RGB5;
			}
			else if (format == RGB8)
			{
				internal_format = GL_RGB8;
			}
			else if (format == RGB10)
			{
				internal_format = GL_RGB10;
			}
			else if (format == RGB12)
			{
				internal_format = GL_RGB12;
			}
			else if (format == RGB16)
			{
				internal_format = GL_RGB16;
			}

			else if (format == RGBA2)
			{
				internal_format = GL_RGBA2;
			}
			else if (format == RGBA4)
			{
				internal_format = GL_RGBA4;
			}
			else if (format == RGBA8)
			{
				internal_format = GL_RGBA8;
			}

			else if (format == RGBA12)
			{
				internal_format = GL_RGBA12;
			}
			else if (format == RGBA16)
			{
				internal_format = GL_RGBA16;
			}

			else if (format == RGB5_A1)
			{
				internal_format = GL_RGB5_A1;
			}
			else if (format == RGB10_A2)
			{
				internal_format = GL_RGB10_A2;
			}

			else if (format == SRGB8)
			{
				internal_format = GL_SRGB8;
			}
			else if (format == SRGB8_A8)
			{
				internal_format = GL_SRGB8_ALPHA8;
			}
			else
			{
				internal_format = GL_RGB;
			}



			if (type == R)
			{
				internal_type = GL_RED;
			}
			else if (type == RG)
			{
				internal_type = GL_RG;
			}
			else if (type == RGB)
			{
				internal_type = GL_RG;
			}
			else if (type == BGR)
			{
				internal_type = GL_RGB;
			}
			else if (type == RGBA)
			{
				internal_type = GL_RGBA;
			}
			else if (type == BGRA)
			{
				internal_type = GL_BGRA;
			}

			else if (type == R_INT)
			{
				internal_type = GL_RED_INTEGER;
			}
			else if (type == RG_INT)
			{
				internal_type = GL_RG_INTEGER;
			}
			else if (type == RGB_INT)
			{
				internal_type = GL_RGB_INTEGER;
			}
			else if (type == BGR_INT)
			{
				internal_type = GL_BGR_INTEGER;
			}
			else if (type == RGBA_INT)
			{
				internal_type = GL_RGBA_INTEGER;
			}

			else if (type == STENCIL_INDEX)
			{
				internal_type = GL_STENCIL_INDEX;
			}
			else if (type == DEPTH_COMPONENT)
			{
				internal_type = GL_DEPTH_COMPONENT;
			}
			else if (type == DEPTH_STENCIL)
			{
				internal_type = GL_DEPTH_STENCIL;
			}

			else
			{
				internal_type = GL_RGBA;
			}


			if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RED;
			}
			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}

			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}
			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}

			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}
			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}

			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}
			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}

			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}
			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}
			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}
			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}
			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}
			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}

			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}
			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}
			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}
			else if (format_type == UNSIGNED_BYTE)
			{
				internal_format_type = GL_RG;
			}

			else
			{
				internal_format_type = GL_FLOAT;
			}


			glGenTextures(1, &ID);
			glBindTexture(GL_TEXTURE_2D, ID);
			glTexImage2D(GL_TEXTURE_2D, 0, internal_format, window->Get_Size().x, window->Get_Size().y, 0, internal_type, GL_FLOAT, NULL);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, ID, 0);
		}
	}
}