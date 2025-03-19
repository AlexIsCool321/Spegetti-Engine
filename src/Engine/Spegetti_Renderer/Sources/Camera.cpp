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
		}

		Camera::Camera(Clip_Space_Mode mode, float fov, OS::Window* window, float near, float far)
		{
			this->Position = glm::vec3(0, 0, 0);
			this->Rotation = glm::vec3(0, 0, 0);

			this->FOV = fov;

			this->Change_Clip_Space_Mode(mode, fov, window, 0.01f, 500.0f);
			this->View = glm::mat4(1.0f);
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


		void Camera::Reload_Models()
		{
			for (int i = 0; i < this->Mesh_Draw_Stack.size(); i++)
			{
				this->Mesh_Draw_Stack[i]->Set_Up_Mesh();
			}
			
			for (int i = 0; i < this->Model_Draw_Stack.size(); i++)
			{
				for (int j = 0; j < this->Model_Draw_Stack[i]->Meshes.size(); j++)
				{
					this->Model_Draw_Stack[i]->Meshes[j].Set_Up_Mesh();
				}
			}
		}


		void Camera::Change_Draw_Mode(Draw_Mode mode)
		{
			this->Mode = mode;
			
			if (mode == Normal)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			else if (mode == Unlit)
			{
				
			}
			else if (mode == Wireframe)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			else if (mode == Surface_Normal)
			{

			}
			else if (mode == Albedo)
			{

			}
			else if (mode == Rougness)
			{

			}
			else if (mode == Normal_Map)
			{

			}
			else
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			
			this->Reload_Models();
		}

		void Camera::Draw()
		{
			this->Update_View();
			this->Change_Draw_Mode(this->Mode);
			
			for (int i = 0; i < this->Model_Draw_Stack.size(); i++)
			{
				for (int j = 0; j < this->Model_Draw_Stack[i]->Meshes.size(); j++)
				{
					if (this->Model_Draw_Stack[i] != nullptr)
					{
						this->Model_Draw_Stack[i]->Meshes[j].Set_Projection(this->Projection);
						this->Model_Draw_Stack[i]->Meshes[j].Set_View_Direction(this->View);
						
						if (*this->Model_Draw_Stack[i]->Meshes[j].material.Mode == Cull_Mode::Back)
						{
							glEnable(GL_CULL_FACE);
							glCullFace(GL_BACK);
							glFrontFace(GL_CCW);
						}
						else if (*this->Model_Draw_Stack[i]->Meshes[j].material.Mode == Cull_Mode::Front)
						{
							glEnable(GL_CULL_FACE);
							glCullFace(GL_FRONT);
							glFrontFace(GL_CCW);
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
					this->Mesh_Draw_Stack[i]->Set_View_Direction(this->View);

					if (*this->Mesh_Draw_Stack[i]->material.Mode == Cull_Mode::Back)
					{
						glEnable(GL_CULL_FACE);
						glCullFace(GL_BACK);
						glFrontFace(GL_CCW);
					}
					else if (*this->Mesh_Draw_Stack[i]->material.Mode == Cull_Mode::Front)
					{
						glEnable(GL_CULL_FACE);
						glCullFace(GL_FRONT);
						glFrontFace(GL_CCW);
					}
					else
					{
						glDisable(GL_CULL_FACE);
					}

					this->Mesh_Draw_Stack[i]->Draw();
				}
			}
		}
	}
}