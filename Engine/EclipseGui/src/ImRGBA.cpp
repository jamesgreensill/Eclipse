#include <pch.h>
#include "ImRGBA.h"

#include "ImGuiHelper.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			void ImRGBA::OnDraw()
			{
				if (_color.r && _color.g && _color.b && _color.a)
				{
					ImGui::DrawColorControl(name, _color.r, _color.g, _color.b, _color.a);
				}
			}
			ImRGBA::ImRGBA(const std::string& n, RGBA color) : _color(color)
			{
				name = n;
			}
			ImRGBA::ImRGBA(const std::string& n, float* r, float* g, float* b, float* a) : ImRGBA(n, {r,g,b,a}){}
		}
	}
}
