#pragma once
#include "BaseModel.h"
namespace Eclipse
{
	namespace Engine
	{
		class EngineModule;
		class System :
			public BaseModel {
		public:
			EngineModule* engineModule = nullptr;
		};
	}
}
