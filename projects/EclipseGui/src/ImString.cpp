#include <pch.h>
#include "ImString.h"

#include "ImGuiHelper.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			auto ImString::OnDraw() -> void
			{
				if (string_)
					ImGui::DrawStringControl(string_);
			}

			ImString::ImString(std::string* value) : string_(value) {}
		}
	}
}