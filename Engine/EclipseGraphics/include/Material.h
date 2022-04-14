#pragma once
#include <vector>

#include "ShaderProgram.h"
#include "glm/glm.hpp"

#include "assimp/texture.h"
#include "Texture.h"

namespace Eclipse
{
	namespace Graphics
	{
		struct Texture;
#define uniMatAmbientColor "materialAmbientColor"
#define uniMatDiffuseColor "materialDiffuseColor"
#define uniMatSpecularColor "materialSpecularColor"
#define uniMatSpecularPower "materialSpecularPower"
#define uniMatAlbedoTexture "materialAlbedoTexture"

		class ShaderProgram;
		class Material
		{
		public:
			Material(std::string shaderName);
			
			auto Bind() const ->void;

			glm::vec4 ambientColor;
			glm::vec4 diffuseColor;
			glm::vec4 specularColor;
			float specularPower;

			Texture* albedoTexture;
			//Texture* diffuseTexture;
			//Texture* specularTexture;

			ShaderProgram* shader;
		};
	}
}
