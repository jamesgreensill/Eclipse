#pragma once
#include "ImType.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			class ImString :
				public ImType
			{
			public:
				auto OnDraw() -> void override;
				ImString(std::string* value);
			private:
				std::string* string_ = nullptr;
			};
		}
	}
}
