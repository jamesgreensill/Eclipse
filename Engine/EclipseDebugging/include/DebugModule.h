#pragma once
#include <EclipseEngine/include/EngineModule.h>

namespace Eclipse
{
	namespace Debug
	{
		/*
			This module is what connects the DebugAPI to the main engine.
		*/
		class DebugModule :
			public Engine::EngineModule
		{
		public:
			void Created() override;
			void Deleted() override;
			void RetrieveGuiData() override;
			void Boot() override;
		};
	}
}
