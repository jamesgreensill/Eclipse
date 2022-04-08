#pragma once
#include "Component.h"

namespace Eclipse
{
	namespace Components
	{
		class DebugComponent :
			public Component
		{
			void Created() override;

			void Draw() override;
			void Reset() override;
		};
	}
}
