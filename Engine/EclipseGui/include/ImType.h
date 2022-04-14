#pragma once
#include <functional>
#include <string>

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			class ImType
			{
			public:

				virtual ~ImType();
				ImType(std::function<void()> cDraw);
				ImType();
				void Draw();

			protected:
				virtual auto OnDraw() -> void;
				std::string name;

				std::function<void()> customDraw = nullptr;
			};
		}
	}
}
