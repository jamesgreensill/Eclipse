#pragma once
#include <vector>
#include <glm/vec4.hpp>

#include <EclipseEngine/include/Component.h>

#include <EclipseEngine/include/EngineMacros.h>

namespace Eclipse
{
	namespace Graphics
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

			static std::vector<Light*> Lights;


			/*
			
				Getter & Setter wrappers.
			
			*/
			GET(Type, return m_Type; );
			SET(Type, LightType, m_Type = value; );
			GET(AmbientColor, return m_AmbientColor; );
			SET(AmbientColor, glm::vec4, m_AmbientColor = value; );
			GET(SpecularColor, return m_SpecularColor; );
			SET(SpecularColor, glm::vec4, m_SpecularColor = value; );
			GET(DiffuseColor, return m_DiffuseColor; );
			SET(DiffuseColor, glm::vec4, m_DiffuseColor = value; );
			GET(Intensity, return m_Intensity; );
			SET(Intensity, float, m_Intensity = value; );

			auto Bind(unsigned int index, Graphics::ShaderProgram* shader) const -> void;
		private:

			/*
			
				Base class overrides.
			
			*/
			auto RetrieveGuiData() -> void override;
			auto Created() -> void override;
			auto Awake() -> void override;
			auto Dispose() -> void override;
			auto Deleted() -> void override;
			auto Reset() -> void override;

			LightType m_Type = LightType::Directional;
			glm::vec4 m_AmbientColor = glm::vec4(1);
			glm::vec4 m_DiffuseColor = glm::vec4(1);
			glm::vec4 m_SpecularColor = glm::vec4(1);
			float m_Intensity = 1;

			// not sure if these will be used.
			float Linear{};
			float Quadratic{};
		};
	}
}
