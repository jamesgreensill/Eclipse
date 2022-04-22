#include "Material.h"

#include <glm/vec4.hpp>

#include "GraphicsModule.h"
#include "EclipseEngine/include/Engine.h"
#include "EclipseEngine/include/ResourceManager.h"
//#include "Resources.h"

namespace Eclipse
{
	namespace Graphics
	{
		auto Material::Bind() const -> void
		{
			const auto shader = Engine::ResourceManager::Get<ShaderProgram>(shaderKey);

			if (!shader)
				return;
			shader->BindUniform(uniMatAmbientColor, ambientColor);
			shader->BindUniform(uniMatDiffuseColor, diffuseColor);
			shader->BindUniform(uniMatSpecularColor, specularColor);
			shader->BindUniform(uniMatSpecularPower, specularPower);

			const auto albedoTexture = Engine::ResourceManager::Get<Texture>(albedoTextureKey);
			if (albedoTexture)
			{
				shader->BindUniform(uniMatAlbedoTexture, 0);
				albedoTexture->Bind(shader, albedoTexture->m_handle);
			}

			const auto diffuseTexture = Engine::ResourceManager::Get<Texture>(diffuseTextureKey);
			if (diffuseTexture)
			{
				shader->BindUniform(uniMatDiffuseTexture, 1);
				diffuseTexture->Bind(shader, diffuseTexture->m_handle);
			}

			const auto specularTexture = Engine::ResourceManager::Get<Texture>(specularTextureKey);
			if (specularTexture)
			{
				shader->BindUniform(uniMatSpecularTexture, 2);
				specularTexture->Bind(shader, specularTexture->m_handle);
			}
		}
	}
}