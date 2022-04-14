#pragma once
#include "ImType.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			struct v3
			{
				float* x;
				float* y;
				float* z;
			};

			class ImVec3 final : public ImType
			{
			public:
				auto OnDraw() -> void override;

				explicit ImVec3(const std::string& n, v3 v);
				explicit ImVec3(const std::string& n, float* x, float* y, float* z);
			private:
				v3 vec3_ = { nullptr,nullptr,nullptr };
			};
		}
	}
}
