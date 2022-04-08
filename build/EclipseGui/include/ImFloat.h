#pragma once
#include "ImType.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			class ImFloat final :
				public ImType
			{
			public:
				auto OnDraw() -> void override;
				explicit ImFloat(const std::string& n, float* x);
			private:
				float* x_ = nullptr;
			};
		}
	}
}
