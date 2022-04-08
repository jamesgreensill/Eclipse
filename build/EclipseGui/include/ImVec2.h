#pragma once
#include "ImType.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			struct v2
			{
				float* x;
				float* y;
			};

			class ImVec2 final : public ImType
			{
			public:
				auto OnDraw() -> void override;

				explicit ImVec2(const std::string& n, v2 v);
				explicit ImVec2(const std::string& n, float* x, float* y, float* z);
			private:
				v2 vec2_ = { nullptr,nullptr };
			};
		}
	}
}
