#include <pch.h>
#include "ImInt.h"
#include "ImGuiHelper.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			auto ImInt::OnDraw() -> void
			{
				ImGui::DrawIntControl(name, x_);
			}

			ImInt::ImInt(const std::string& n, int* x) : x_(x)
			{
				name = n;
			}
		}
	}
}