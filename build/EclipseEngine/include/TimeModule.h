
#pragma once
#include "EngineModule.h"

namespace Eclipse
{
	namespace Engine
	{
		class TimeModule :
			public EngineModule
		{
		public:
			void Created() override;
			void Deleted() override;
			void Boot() override;
		};
	}
}

