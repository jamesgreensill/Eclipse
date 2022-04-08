#include <pch.h>
#include "ImVec3.h"
#include "ImGuiHelper.h"

#include <string>

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			auto ImVec3::OnDraw() -> void
			{
				if (vec3_.x && vec3_.y && vec3_.z)
					ImGui::DrawVec3Control(name, vec3_.x, vec3_.y, vec3_.z);
			}

			ImVec3::ImVec3(const std::string& n, const v3 v) : vec3_(v){name = n;}
			ImVec3::ImVec3(const std::string& n, float* x, float* y, float* z) : ImVec3(n, { x,y,z }) {}
		}
	}
}