#include <pch.h>
#include "Material.h"
#include "Resources.h"

namespace Eclipse
{
	namespace Rendering
	{
		Material::Material(std::string shaderName)
		{
			ambientColor = glm::vec4(1);
			diffuseColor = glm::vec4(1);
			specularColor = glm::vec4(1);

			specularPower = 1;
			shader = (Engine::Resources::GetShaderProgram(shaderName.c_str()));

			if (!shader)
			{
				//shader = Engine::Resources::GetDefaultShader();
			}
		}

		auto Material::Bind() const -> void
		{
			shader->BindUniform(uniMatAmbientColor, ambientColor);
			shader->BindUniform(uniMatDiffuseColor, diffuseColor);
			shader->BindUniform(uniMatSpecularColor, specularColor);
			shader->BindUniform(uniMatSpecularPower, specularPower);

			if (albedoTexture)
			{
				shader->BindUniform(uniMatAlbedoTexture, 0);
				albedoTexture->Bind(shader, 0);
			}
		}
	}
}