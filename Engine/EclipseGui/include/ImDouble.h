#pragma once
#include "ImType.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			class ImDouble  :
				public ImType
			{
			public:
				auto OnDraw() -> void override;
				explicit ImDouble(const std::string& n, double* x);
			private:
				double* x_ = nullptr;
			};
		}
	}
}
