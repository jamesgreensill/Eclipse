#pragma once
#include "ImType.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			class ImInt final :
				public ImType
			{
			public:
				auto OnDraw() -> void override;
				explicit ImInt(const std::string& n, int* x);
			private:
				int* x_ = nullptr;
			};
		}
	}
}
