#pragma once
#include "EngineModule.h"

namespace Eclipse
{
	namespace Engine
	{

		/// <summary>
		/// CoreModule is the base class for engine modules.
		/// </summary>
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
