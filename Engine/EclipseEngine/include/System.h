#pragma once
#include "BaseModel.h"
#include "ESingle.h"

namespace Eclipse
{
	namespace Engine
	{
		class EngineModule;
		class System :
			public BaseModel {
		public:

			/// <summary>
			/// Pointer to the module this system is linked too.
			/// </summary>
			EngineModule* engineModule = nullptr;
		};
	}
}
