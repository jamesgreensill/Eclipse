#include "DebugModule.h"
#include <EclipseEngine/include/ApiLoader.h>

#include "DebugApi.h"
#include "DebugSystem.h"

namespace Eclipse
{
	namespace Debug
	{
		void DebugModule::Boot()
		{
			// Loads the Debug API.
			Engine::ApiLoader::Load<DebugApi>();
		}

		void DebugModule::Created()
		{
		}

		void DebugModule::Deleted()
		{
		}

		void DebugModule::RetrieveGuiData()
		{
			EngineModule::RetrieveGuiData();
		}
	}
}
