#include <pch.h>
#include "ImType.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			ImType::~ImType()
			{
				customDraw = nullptr;
			}

			ImType::ImType(std::function<void()> cDraw) : customDraw(std::move(cDraw)) {}

			ImType::ImType() : ImType(nullptr) {}

			void ImType::Draw()
			{
				if (!customDraw)
				{
					OnDraw();
				}
				else customDraw();
			}

			auto ImType::OnDraw() -> void
			{
			}
		}
	}
}