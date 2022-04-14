#pragma once
#include "ImType.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			struct RGBA
			{
				float* r;
				float* g;
				float* b;
				float* a;
			};
			class ImRGBA :
				public ImType
			{
			public:
				auto OnDraw() -> void override;

				explicit ImRGBA(const std::string& n, RGBA color);
				explicit ImRGBA(const std::string& n, float* r, float* g, float* b, float* a);
			private:
				RGBA _color = { nullptr,nullptr,nullptr, nullptr };
			};
		}
	}
}
