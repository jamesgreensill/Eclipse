#include "CoreModule.h"
#include "Core.h"
#include "Application.h"
#include "AssetLoader.h"
#include "SceneManager.h"

namespace Eclipse
{
	namespace Engine
	{
		void CoreModule::Boot()
		{
			// Add SceneManager.
			m_SystemsContainer.AddComponent<SceneManagement::SceneManager>();
		}

		void CoreModule::Created()
		{
		}

		void CoreModule::Deleted()
		{
		}

		void CoreModule::OnAwake()
		{
			AssetLoader::Awake();
		}
	}
}