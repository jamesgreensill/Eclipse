#include <pch.h>
#include "SystemManager.h"
#include "System.h"

namespace Eclipse
{
	namespace Engine
	{

// deprecated

		std::unordered_map<std::type_index, System*> SystemManager::systems = {};

		void SystemManager::Awake()
		{
			for (auto& system : systems)
			{
				system.second->Awake();
			}
		}

		void SystemManager::Start()
		{
			for (auto& system : systems)
			{
				system.second->Start();
			}
		}

		void SystemManager::Update()
		{
			for (auto& system : systems)
			{
				system.second->Update();
			}
		}

		void SystemManager::LateUpdate()
		{
			for (auto& system : systems)
			{
				system.second->LateUpdate();
			}
		}

		void SystemManager::FixedUpdate()
		{
			for (auto& system : systems)
			{
				system.second->FixedUpdate();
			}
		}

		void SystemManager::Draw()
		{
			for (auto& system : systems)
			{
				system.second->Draw();
			}
		}

		void SystemManager::Gui()
		{
			for (auto& system : systems)
			{
				system.second->Gui();
			}
		}

		void SystemManager::Dispose()
		{
			for (auto& system : systems)
			{
				system.second->Dispose();
			}
		}
	}
}