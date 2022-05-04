#pragma once
#include <glm/glm.hpp>
#include <EclipseEngine/include/EngineMacros.h>

#include "ShaderProgram.h"
#include "Texture.h"

namespace Eclipse
{
	// TODO:
	// convert to resource and create custom .mat file type

	namespace Graphics
	{
		struct Texture;
#define uniMatAmbientColor "materialAmbientColor"
#define uniMatDiffuseColor "materialDiffuseColor"
#define uniMatSpecularColor "materialSpecularColor"
#define uniMatSpecularPower "materialSpecularPower"
#define uniMatAlbedoTexture "materialAlbedoTexture"
#define uniMatDiffuseTexture "materialDiffuseTexture"
#define uniMatSpecularTexture "materialSpecularTexture"

		class ShaderProgram;
		struct Material
		{
			auto Bind() const ->void;

			/*
				Getter & Setter Wrappers.
			*/

			GET(AmbientColor, return ambientColor;);
			SET(AmbientColor, glm::vec4, ambientColor = value; );
			GET(DiffuseColor, return diffuseColor;);
			SET(DiffuseColor, glm::vec4, diffuseColor = value; );
			GET(SpecularColor, return specularColor;);
			SET(SpecularColor, glm::vec4, specularColor = value; );
			GET(SpecularPower, return specularPower; );
			SET(SpecularPower, float, specularPower = value; );
			GET(AlbedoTexture, return albedoTextureKey;);
			SET(AlbedoTexture, Engine::ResourceKey, albedoTextureKey = value;);
			GET(SpecularTexture, return specularTextureKey;);
			SET(SpecularTexture, Engine::ResourceKey, specularTextureKey = value;);
			GET(DiffuseTexture, return diffuseTextureKey;);
			SET(DiffuseTexture, Engine::ResourceKey, diffuseTextureKey = value;);
			GET(Shader, return shaderKey;);
			SET(Shader, Engine::ResourceKey, shaderKey = value;);

			/**
			 * \brief Constructor
			 */
			Engine::ResourceKey shaderKey = INVALID_RESOURCE_KEY;
			Engine::ResourceKey albedoTextureKey = INVALID_RESOURCE_KEY;
			Engine::ResourceKey specularTextureKey = INVALID_RESOURCE_KEY;
			Engine::ResourceKey diffuseTextureKey = INVALID_RESOURCE_KEY;
			glm::vec4 specularColor = { 1,1,1,1 };
			glm::vec4 ambientColor = { 1,1,1,1 };
			glm::vec4 diffuseColor = { 1,1,1,1 };
			float specularPower = 1.0f;
		};
	}
}
