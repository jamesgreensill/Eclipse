#pragma once
#include <EclipseEngine/include/API.h>

namespace Eclipse
{
	namespace Debug
	{
		class DebugApi :
			public Eclipse::Engine::API
		{
		public:
			void LoadInterface() override;
		};

	}
}

