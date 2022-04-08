#include <pch.h>

#include "ImVec4.h"
#include "ImGuiHelper.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			void ImVec4::OnDraw()
			{
				if (vec4_.x && vec4_.y && vec4_.z && vec4_.w)
				{
					ImGui::DrawVec4Control(name, vec4_.x, vec4_.y, vec4_.z, vec4_.w);
				}
			}

			ImVec4::ImVec4(const std::string& n, v4 v) : vec4_(v){name = n;}
			ImVec4::ImVec4(const std::string& n, float* x, float* y, float* z, float* w) : ImVec4(n,{x,y,z,w}){}
		}
	}
}