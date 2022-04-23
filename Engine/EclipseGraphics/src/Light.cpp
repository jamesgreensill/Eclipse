#include "Light.h"

#include <EclipseEngine/include/Object.h>
#include <EclipseEngine/include/Scene.h>
#include <EclipseEngine/include/Core.h>
#include <EclipseEngine/include/Transform.h>
#include <EclipseEngine/include/SceneManager.h>

#include "ShaderProgram.h"


//#include "ImFloat.h"
//#include "ImString.h"
//#include "Object.h"
//#include "Scene.h"
//#include "ShaderProgram.h"
//#include "Transform.h"
//#include "Eclipse.h"
//
//#include "imgui/imgui.h"
//
//#include "ImRGBA.h"
//
//#include "SceneManager.h"

namespace Eclipse
{
	namespace Components
	{
		std::vector<Light*> Light::Lights = {};

		void Light::Bind(unsigned int index, Graphics::ShaderProgram* shader) const
		{
			Transform* transform = object->transform;
			const std::string prefix = "lights[" + std::to_string(index) + "].";

			External::Debug::DebugAPI::Debug("Binding Light");

			shader->BindUniform(prefix + uniLightDirection, transform->GetForward());
			shader->BindUniform(prefix + uniLightPosition, transform->GetGlobalPosition());
			shader->BindUniform(prefix + uniAmbientLightColor, m_AmbientColor);
			shader->BindUniform(prefix + uniDiffuseLightColor, m_DiffuseColor);
			shader->BindUniform(prefix + uniSpecularLightColor, m_SpecularColor);
			shader->BindUniform(prefix + uniLightIntensity, m_Intensity);
			shader->BindUniform(prefix + uniLightLinear, Linear);
			shader->BindUniform(prefix + uniLightQuadratic, Quadratic);
			shader->BindUniform(prefix + uniLightType, static_cast<int>(m_Type));
		}

		// Deprecated but needed for reference.

		void Light::RetrieveGuiData()
		{
			//call.Push(new Engine::ImGuiTypes::ImString(&m_Name));
			//call.Push(new Engine::ImGuiTypes::ImRGBA("Ambient Color", &m_AmbientColor.x, &m_AmbientColor.y, //&m_AmbientColor.z, &m_AmbientColor.w));
			//call.Push(new Engine::ImGuiTypes::ImRGBA("Diffuse Color", &m_DiffuseColor.x, &m_DiffuseColor.y, //&m_DiffuseColor.z, &m_DiffuseColor.w));
			//call.Push(new Engine::ImGuiTypes::ImRGBA("Specular Color", &m_SpecularColor.x, &m_SpecularColor.y, //&m_SpecularColor.z, &m_SpecularColor.w));
			//call.Push(new Engine::ImGuiTypes::ImFloat("m_Intensity", &m_Intensity));
			//call.Push(new Engine::ImGuiTypes::ImFloat("Linear", &Linear));
			//call.Push(new Engine::ImGuiTypes::ImFloat("Quadratic", &Quadratic));
			//
			//call.Push(new Engine::ImGuiTypes::ImType([=]
			//	{
			//		ImGui::Text("Light m_Type");
			//
			//		if (ImGui::BeginTable("m_Type", 3))
			//		{
			//			ImGui::TableNextColumn();
			//			if (ImGui::Button("-"))
			//			{
			//				lightIndex--;
			//				if (lightIndex < 0)
			//					lightIndex = static_cast<int>(LightType::COUNT) - 1;
			//
			//				m_Type = static_cast<LightType>(lightIndex);
			//			}
			//			ImGui::TableNextColumn();
			//			switch (m_Type)
			//			{
			//			case LightType::Directional:
			//				ImGui::Text("Directional");
			//				break;
			//			case LightType::Point:
			//				ImGui::Text("Point");
			//				break;
			//			case LightType::Spot:
			//				ImGui::Text("Spot");
			//				break;
			//			case LightType::COUNT:
			//				ImGui::Text("Error");
			//				break;
			//			}
			//
			//			ImGui::TableNextColumn();
			//			if (ImGui::Button("+"))
			//			{
			//				lightIndex++;
			//				if (lightIndex > static_cast<int>(LightType::COUNT) - 1)
			//					lightIndex = 0;
			//
			//				m_Type = static_cast<LightType>(lightIndex);
			//			}
			//
			//			ImGui::EndTable();
			//		}
			//	}));
		}

		void Light::Created()
		{
		}

		void Light::Awake()
		{
			// emplace light into lights array.
			Lights.emplace_back(this);
		}

		void Light::Dispose()
		{
			// remove this light from lights array.
			const auto& it = std::find(Lights.begin(), Lights.end(), this);
			if (it != Lights.end())
			{
				Lights.erase(it);
			}
		}

		void Light::Deleted()
		{
		}

		void Light::Reset()
		{
			m_Type = LightType::Directional;
			//m_AmbientColor = glm::vec4(0.2f);
			//m_DiffuseColor = glm::vec4(0.2f);
			//m_SpecularColor = glm::vec4(0.2f);
			m_Intensity = 1;
			Linear = 1;
			Quadratic = 1;
		}
	}
}