#include <pch.h>
#include "Light.h"

#include "ImFloat.h"
#include "ImString.h"
#include "Object.h"
#include "Scene.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Eclipse.h"

#include "imgui/imgui.h"

#include "ImRGBA.h"

#include "SceneManager.h"

namespace Eclipse
{
	namespace Components
	{
		void Light::Bind(unsigned int index, Rendering::ShaderProgram* shader) const
		{
			Transform* transform = object->transform;
			const std::string prefix = "lights[" + std::to_string(index) + "].";

			Core::Debug::Debug("Binding Light");

			shader->BindUniform(prefix + uniLightDirection, transform->GetForward());
			shader->BindUniform(prefix + uniLightPosition, transform->GetGlobalPosition());
			shader->BindUniform(prefix + uniAmbientLightColor, AmbientColor);
			shader->BindUniform(prefix + uniDiffuseLightColor, DiffuseColor);
			shader->BindUniform(prefix + uniSpecularLightColor, SpecularColor);
			shader->BindUniform(prefix + uniLightIntensity, Intensity);
			shader->BindUniform(prefix + uniLightLinear, Linear);
			shader->BindUniform(prefix + uniLightQuadratic, Quadratic);
			shader->BindUniform(prefix + uniLightType, static_cast<int>(Type));
		}

		Light::Light() { Reset(); }

		void Light::RetrieveGuiData(Eclipse::Engine::ImGuiTypes::ImGuiCall& call)
		{
			call.Push(new Engine::ImGuiTypes::ImString(&name));
			call.Push(new Engine::ImGuiTypes::ImRGBA("Ambient Color", &AmbientColor.x, &AmbientColor.y, &AmbientColor.z, &AmbientColor.w));
			call.Push(new Engine::ImGuiTypes::ImRGBA("Diffuse Color", &DiffuseColor.x, &DiffuseColor.y, &DiffuseColor.z, &DiffuseColor.w));
			call.Push(new Engine::ImGuiTypes::ImRGBA("Specular Color", &SpecularColor.x, &SpecularColor.y, &SpecularColor.z, &SpecularColor.w));
			call.Push(new Engine::ImGuiTypes::ImFloat("Intensity", &Intensity));
			call.Push(new Engine::ImGuiTypes::ImFloat("Linear", &Linear));
			call.Push(new Engine::ImGuiTypes::ImFloat("Quadratic", &Quadratic));

			call.Push(new Engine::ImGuiTypes::ImType([=]
				{
					ImGui::Text("Light Type");

					if (ImGui::BeginTable("Type", 3))
					{
						ImGui::TableNextColumn();
						if (ImGui::Button("-"))
						{
							lightIndex--;
							if (lightIndex < 0)
								lightIndex = static_cast<int>(LightType::COUNT) - 1;

							Type = static_cast<LightType>(lightIndex);
						}
						ImGui::TableNextColumn();
						switch (Type)
						{
						case LightType::Directional:
							ImGui::Text("Directional");
							break;
						case LightType::Point:
							ImGui::Text("Point");
							break;
						case LightType::Spot:
							ImGui::Text("Spot");
							break;
						case LightType::COUNT:
							ImGui::Text("Error");
							break;
						}

						ImGui::TableNextColumn();
						if (ImGui::Button("+"))
						{
							lightIndex++;
							if (lightIndex > static_cast<int>(LightType::COUNT) - 1)
								lightIndex = 0;

							Type = static_cast<LightType>(lightIndex);
						}

						ImGui::EndTable();
					}
				}));
		}

		void Light::Created()
		{
			Engine::SceneManagement::SceneManager::Instance->GetActiveScene()->AddLight(this);
		}

		void Light::Deleted()
		{
			Engine::SceneManagement::SceneManager::Instance->GetActiveScene()->RemoveLight(this);
		}

		void Light::Reset()
		{
			Type = LightType::Directional;
			AmbientColor = glm::vec4(0.2f);
			DiffuseColor = glm::vec4(0.2f);
			SpecularColor = glm::vec4(0.2f);
			Intensity = 1;
			Linear = 1;
			Quadratic = 1;
		}
	}
}