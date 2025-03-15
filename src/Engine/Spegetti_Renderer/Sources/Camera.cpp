#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Camera::Camera()
		{
			this->Position	= glm::vec3(0, 0, 0);
			this->Rotation	= glm::vec3(0, 0, 0);

			this->Projection	= glm::perspective(glm::radians(90.0f), 1200.0f / 800.0f, 0.001f, 500.0f);
			this->View			= glm::mat4(1.0f);
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


		void Camera::Draw()
		{
			this->Update_View();

			for (int i = 0; i < this->Model_Draw_Stack.size(); i++)
			{
				for (int j = 0; j < this->Model_Draw_Stack[i]->Meshes.size(); j++)
				{
					if (this->Model_Draw_Stack[i] != nullptr)
					{
						this->Model_Draw_Stack[i]->Meshes[j].Set_Projection(this->Projection);
						this->Model_Draw_Stack[i]->Meshes[j].Set_View_Direction(this->View);
						
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

					this->Mesh_Draw_Stack[i]->Draw();
				}
			}
		}
	}
}