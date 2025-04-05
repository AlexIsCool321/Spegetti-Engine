#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Camera::Camera(OS::Window* window)
		{
			this->Position = glm::vec3(0, 0, 0);
			this->Rotation = glm::vec3(0, 0, 0);

			this->FOV = 90.0f;

			this->Change_Clip_Space_Mode(Perspective, 90.0f, window, 0.01f, 500.0f);
			this->View = glm::mat4(1.0f);

			this->Reload_Models(window);

			Shader shader = Shader("engine/shaders/light.vs", "engine/shaders/light.fs");
			Material material = Material(&shader);
			
			this->Lighting_Effect = Post_Process_Effect(&material);
		}

		Camera::Camera(Clip_Space_Mode mode, float fov, OS::Window* window, float near, float far)
		{
			this->Position = glm::vec3(0, 0, 0);
			this->Rotation = glm::vec3(0, 0, 0);

			this->FOV = fov;

			this->Change_Clip_Space_Mode(mode, fov, window, 0.01f, 500.0f);
			this->View = glm::mat4(1.0f);

			this->Reload_Models(window);

			Shader shader = Shader("engine/shaders/light.vs", "engine/shaders/light.fs");
			Material material = Material(&shader);

			this->Lighting_Effect = Post_Process_Effect(&material);
		}

		Camera::~Camera()
		{
			for (int i = 0; i < this->Model_Draw_Stack.size(); i++)
			{
				delete this->Model_Draw_Stack[i];
			}

			for (int i = 0; i < this->Mesh_Draw_Stack.size(); i++)
			{
				delete this->Mesh_Draw_Stack[i];
			}
		}


		void Camera::Change_Clip_Space_Mode(Clip_Space_Mode mode, float fov, OS::Window* window, float near, float far)
		{
			glm::vec2 size = window->Get_Size();
			
			if (mode == Orthographic)
			{
				this->Projection = glm::ortho(0.0f, size.x, 0.0f, size.y, near, far);
			}
			else
			{
				this->Projection = glm::perspective(glm::radians(fov), size.x / size.y, near, far);
			}
		}


		void Camera::Update_View()
		{
			// Rotation
			this->Front = glm::normalize(glm::vec3(cos(this->Rotation.y) * cos(this->Rotation.x), sin(this->Rotation.x), sin(this->Rotation.y) * cos(this->Rotation.x)));

			this->Right	= glm::normalize(glm::cross(this->Front, glm::vec3(0, 1, 0)));
			this->Up	= glm::normalize(glm::cross(this->Right, this->Front));

			glm::vec3 Rot_Position = this->Position;

			this->View = glm::lookAt(Rot_Position, Rot_Position + this->Front, this->Up);

			// Position
			static glm::vec3 Old_Position = glm::vec3(0.0f);

			this->View = glm::translate(this->View, Old_Position - this->Position);
			Old_Position = this->Position;
		}


		void Camera::Add_Mesh_To_Draw_Stack(Mesh* mesh)
		{
			if (mesh != nullptr)
			{
				this->Mesh_Draw_Stack.push_back(mesh);
			}
		}

		void Camera::Add_Model_To_Draw_Stack(Model* model)
		{
			if (model != nullptr)
			{
				this->Model_Draw_Stack.push_back(model);
			}
		}


		void Camera::Reload_Models(OS::Window* window)
		{
			if (this->Mode != Camera::Forward)
			{
				if (this->gBuffer != 0)
				{
					return;
				}
				
				glBindFramebuffer(GL_FRAMEBUFFER, 0);

				glGenFramebuffers(1, &this->gBuffer);
				glBindFramebuffer(GL_FRAMEBUFFER, this->gBuffer);

				// Position Buffer
				glGenTextures(1, &this->gPosition);
				glBindTexture(GL_TEXTURE_2D, this->gPosition);
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, (int)window->Get_Size().x, (int)window->Get_Size().y, 0, GL_RGBA, GL_FLOAT, NULL);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, this->gPosition, 0);

				// Normal Buffer
				glGenTextures(1, &this->gNormal);
				glBindTexture(GL_TEXTURE_2D, this->gNormal);
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, (int)window->Get_Size().x, (int)window->Get_Size().y, 0, GL_RGBA, GL_FLOAT, NULL);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, this->gNormal, 0);

				// Albedo Buffer
				glGenTextures(1, &this->gAlbedoSpec);
				glBindTexture(GL_TEXTURE_2D, this->gAlbedoSpec);
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (int)window->Get_Size().x, (int)window->Get_Size().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, GL_TEXTURE_2D, this->gAlbedoSpec, 0);

				unsigned int attachments[3] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2 };
				glDrawBuffers(3, attachments);

				// Depth Buffer
				glGenRenderbuffers(1, &this->gDepth);
				glBindRenderbuffer(GL_RENDERBUFFER, this->gDepth);
				glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, (int)window->Get_Size().x, (int)window->Get_Size().y);
				glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, this->gDepth);

				if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
				{
					Error("FAILED TO CREATE FRAMEBUFFER(S)");
				}
				glBindFramebuffer(GL_FRAMEBUFFER, 0);
			}
			else
			{
				glBindFramebuffer(GL_FRAMEBUFFER, 0);
			}
		}


		void Camera::Set_Lighting_Material(Material* material)
		{
			this->Lighting_Effect.Set_Material(material);
		}


		void Camera::Change_Draw_Mode(Draw_Mode mode)
		{
			if (this->Mode == mode)
			{
				return;
			}

			this->Mode = mode;

			if (mode == Default)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			else if (mode == Forward)
			{
				this->Reload_Models(nullptr);
			}
			else if (mode == Unlit)
			{
				
			}
			else if (mode == Wireframe)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			else if (mode == Frag_Position)
			{

			}
			else if (mode == Albedo)
			{

			}
			else if (mode == Roughness)
			{

			}
			else if (mode == Normal)
			{

			}
			else if (mode == Normal_Map)
			{

			}
			else
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}

			this->Reload_Models(nullptr);
		}

		void Camera::Draw(OS::Window* window)
		{
			if (this->Mode == !Camera::Forward)
			{
				glBindFramebuffer(GL_FRAMEBUFFER, gBuffer);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			}
			
			this->Update_View();
			this->Change_Draw_Mode(this->Mode);
			
			for (int i = 0; i < this->Model_Draw_Stack.size(); i++)
			{
				for (int j = 0; j < this->Model_Draw_Stack[i]->Meshes.size(); j++)
				{
					if (this->Model_Draw_Stack[i] != nullptr)
					{
						this->Model_Draw_Stack[i]->Meshes[j].Set_Projection(this->Projection);
						this->Model_Draw_Stack[i]->Meshes[j].Set_View_Matrix(this->View);
						
						this->Model_Draw_Stack[i]->Meshes[j].Set_View_Position(this->Position);

						if (*this->Model_Draw_Stack[i]->Meshes[j].material.Mode == Material::Cull_Mode::Back)
						{
							//glEnable(GL_CULL_FACE);
							//glCullFace(GL_BACK);
							//glFrontFace(GL_CCW);
						}
						else if (*this->Model_Draw_Stack[i]->Meshes[j].material.Mode == Material::Cull_Mode::Front)
						{
							//glEnable(GL_CULL_FACE);
							//glCullFace(GL_FRONT);
							//glFrontFace(GL_CCW);
						}
						else
						{
							glDisable(GL_CULL_FACE);
						}

						this->Model_Draw_Stack[i]->Meshes[j].Draw();
					}
				}
			}
			
			for (int i = 0; i < this->Mesh_Draw_Stack.size(); i++)
			{
				if (this->Mesh_Draw_Stack[i] != nullptr)
				{
					this->Mesh_Draw_Stack[i]->Set_Projection(this->Projection);
					this->Mesh_Draw_Stack[i]->Set_View_Matrix(this->View);
					
					this->Mesh_Draw_Stack[i]->Set_View_Position(this->Position);

					if (*this->Mesh_Draw_Stack[i]->material.Mode == Material::Cull_Mode::Back)
					{
						//glEnable(GL_CULL_FACE);
						//glCullFace(GL_BACK);
						//glFrontFace(GL_CCW);
					}
					else if (*this->Mesh_Draw_Stack[i]->material.Mode == Material::Cull_Mode::Front)
					{
						//glEnable(GL_CULL_FACE);
						//glCullFace(GL_FRONT);
						//glFrontFace(GL_CCW);
					}
					else
					{
						glDisable(GL_CULL_FACE);
					}

					this->Mesh_Draw_Stack[i]->Draw();
				}
			}
			
			if (this->Mode == !Camera::Forward)
			{
				glBindFramebuffer(GL_FRAMEBUFFER, 0);
			
			
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				this->Lighting_Effect.Get_Material()->Use();

				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, gPosition);
				glActiveTexture(GL_TEXTURE1);
				glBindTexture(GL_TEXTURE_2D, gNormal);
				glActiveTexture(GL_TEXTURE2);
				glBindTexture(GL_TEXTURE_2D, gAlbedoSpec);
				
				this->Lighting_Effect.Get_Material()->Set_Vector3("View_Position", this->Position);
				this->Lighting_Effect.Get_Material()->Set_Int("Mode", (int)this->Mode);
				
				this->Lighting_Effect.Draw();

				

				glBindFramebuffer(GL_READ_FRAMEBUFFER, gBuffer);
				glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
			
				glBlitFramebuffer(0, 0, window->Get_Size().x, window->Get_Size().y, 0, 0, window->Get_Size().x, window->Get_Size().y, GL_DEPTH_BUFFER_BIT, GL_NEAREST);
			}
		}
	}
}