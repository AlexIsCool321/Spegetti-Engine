#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		View_Port::View_Port(OS::Window* window)
		{
			this->Force_Size_Update(window);
		}

		void View_Port::Force_Size_Update(OS::Window* window)
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);

			glGenFramebuffers(1, &this->gBuffer);
			glBindFramebuffer(GL_FRAMEBUFFER, this->gBuffer);

			// Position Buffer
			glGenTextures(1, &this->View);
			glBindTexture(GL_TEXTURE_2D, this->View);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, (int)window->Get_Size().x, (int)window->Get_Size().y, 0, GL_RGBA, GL_FLOAT, NULL);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, this->View, 0);

			unsigned int attachments[1] = { GL_COLOR_ATTACHMENT0 };
			glDrawBuffers(1, attachments);

			if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			{
				Error("FAILED TO CREATE FRAMEBUFFER(S)");
			}
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}


		void View_Port::Use()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, this->gBuffer);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glBindFramebuffer(GL_FRAMEBUFFER, this->gBuffer);
		}

		unsigned int View_Port::Get_ID()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);

			return this->View;
		}
	}
}