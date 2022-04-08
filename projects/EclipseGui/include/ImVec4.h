#pragma once
#include "ImType.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			struct v4
			{
				float* x;
				float* y;
				float* z;
				float* w;
			};
			class ImVec4 :
				public ImType
			{
			public:
				auto OnDraw() -> void override;

				explicit ImVec4(const std::string& n, v4 v);
				explicit ImVec4(const std::string& n, float* x, float* y, float* z, float* w);
			private:
				v4 vec4_ = { nullptr,nullptr,nullptr, nullptr };
			};
		}
	}
}
