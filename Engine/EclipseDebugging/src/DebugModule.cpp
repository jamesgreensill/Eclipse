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
			Engine::ApiLoader::Load<DebugApi>();
			//m_SystemsContainer.AddComponent<DebugSystem>();
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
