#pragma once
#include <EclipseEngine/include/API.h>

namespace Eclipse
{
	namespace Debug
	{
		/*
			===============================================================================================
			External API that is connected to the main engine. Through a message bus and callback linking.
			This API provides basic Debugging functionality, for the engine and engine users.
			===============================================================================================
		*/
		class DebugApi :
			public Eclipse::Engine::API
		{
		public:
			void LoadInterface() override;
		};

	}
}

