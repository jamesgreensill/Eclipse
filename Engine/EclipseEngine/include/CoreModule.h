#pragma once
#include "EngineModule.h"

namespace Eclipse
{
	namespace Engine
	{
		class CoreModule :
			public EngineModule
		{
			void Boot() override;
			void Created() override;
			void Deleted() override;
		public:
			void OnAwake() override;
		};
	}
}
