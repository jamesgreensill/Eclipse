#pragma once
#include <glm/vec4.hpp>

#include "Component.h"

namespace Eclipse
{
	namespace Rendering
	{
		class ShaderProgram;
	}

	namespace Components
	{
#define uniLightDirection "lightDirection"
#define uniLightPosition "lightPosition"
#define uniAmbientLightColor "lightAmbientColor"
#define uniDiffuseLightColor "lightDiffuseColor"
#define uniSpecularLightColor "lightSpecularColor"
#define uniLightLinear "lightLinear"
#define uniLightQuadratic "lightQuadratic"
#define uniLightIntensity "lightIntensity"
#define uniLightType "lightType"

		class Light final :
			public Component
		{
		public:
			enum class LightType
			{
				Point,
				Directional,
				Spot,
				COUNT,
			};

			auto Bind(unsigned int index, Rendering::ShaderProgram* shader) const -> void;
			Light();

			LightType Type;
			glm::vec4 AmbientColor{};
			glm::vec4 DiffuseColor{};
			glm::vec4 SpecularColor{};

			float Intensity{};
			float Linear{};
			float Quadratic{};
		private:

			int lightIndex = 0;

			auto RetrieveGuiData(Eclipse::Engine::ImGuiTypes::ImGuiCall& call) -> void override;

			void Created() override;
			void Deleted() override;
			void Reset() override;
		};
	}
}
