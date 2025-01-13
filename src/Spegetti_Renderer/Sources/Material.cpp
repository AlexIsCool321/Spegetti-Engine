#include <Spegetti_Renderer.h>

namespace Spegetti_Renderer
{
	namespace Graphics
	{
		Material::Material(Shader* shader, int Vertex_Group)
		{
			this->shader = shader;
			this->Vertex_Group = Vertex_Group;
		}

		void Material::Use()
		{
			shader->Use();
		}


		void Material::SetTexture(const std::string& name, const char* texture_path)
		{
			shader->SetTexture(name, texture_path);
		}
		

		void Material::SetBool(const std::string& name, bool value)
		{
			shader->SetBool(name, value);
		}

		void Material::SetInt(const std::string& name, int value)
		{
			shader->SetInt(name, value);
		}

		void Material::SetFloat(const std::string& name, float value)
		{
			shader->SetFloat(name, value);
		}


		void Material::SetVector2(const std::string& name, glm::vec2 value)
		{
			shader->SetVector2(name, value);
		}

		void Material::SetVector3(const std::string& name, glm::vec3 value)
		{
			shader->SetVector3(name, value);
		}

		void Material::SetVector4(const std::string& name, glm::vec4 value)
		{
			shader->SetVector4(name, value);
		}


		void Material::SetMat2(const std::string& name, glm::mat2 value)
		{
			shader->SetMat2(name, value);
		}

		void Material::SetMat3(const std::string& name, glm::mat3 value)
		{
			shader->SetMat3(name, value);
		}

		void Material::SetMat4(const std::string& name, glm::mat4 value)
		{
			shader->SetMat4(name, value);
		}
	}
}