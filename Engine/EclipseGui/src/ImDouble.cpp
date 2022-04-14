#include <pch.h>
#include "ImDouble.h"

#include "ImGuiHelper.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			auto ImDouble::OnDraw() -> void
			{
				ImGui::DrawDoubleControl(name, x_);
			}

			ImDouble::ImDouble(const std::string& n, double* x) : x_(x)
			{
				name = n;
			}
		}
	}
}