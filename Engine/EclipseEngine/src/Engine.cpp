#include "Engine.h"
#include "Application.h"
#include "EngineModule.h"
#include "Resources.h"
#include "SceneManager.h"
#include "SystemManager.h"

namespace Eclipse
{
	namespace Engine
	{
		std::unordered_map<std::string, bool> Engine::EngineConditions = {};

		void Engine::Run(SceneManagement::Scene* mainScene)
		{
			Created();
			Boot();
			PostBoot();
			PreEngineInit();
			EngineInit();
			PostEngineInit();

			/*
			 *
			 *	If there is a valid scene. Then load it.
			 *
			 */
			if (mainScene)
			{
				SceneManagement::SceneManager::Instance->AddScene(mainScene);
			}
			else
			{
				SceneManagement::SceneManager::Instance->AddScene(new SceneManagement::Scene());
			}
			SceneManagement::SceneManager::Instance->Load(0);

			Awake();
			Start();
			LateStart();
			while (!Application::Instance->ShouldClose())
			{
				FrameBegin();
				FixedUpdate();
				Update();
				LateUpdate();
				PreDraw();
				Draw();
				PostDraw();
				Gizmos();
				PreGui();
				Gui();
				PostGui();
				FrameEnd();
			}
			Dispose();
			Deleted();
		}

		void Engine::PreEngineInit()
		{
			FFMCP(PreEngineInit, m_ModuleContainer.m_Components)
		}

		void Engine::EngineInit()
		{
			FFMCP(EngineInit, m_ModuleContainer.m_Components)
		}

		void Engine::PostEngineInit()
		{
			FFMCP(PostEngineInit, m_ModuleContainer.m_Components)
		}

		void Engine::PostBoot()
		{
			FFMCP(PostBoot, m_ModuleContainer.m_Components)
		}

		void Engine::LateStart()
		{
			FFMCP(LateStart, m_ModuleContainer.m_Components)
		}

		void Engine::FrameBegin()
		{
			FFMCP(FrameBegin, m_ModuleContainer.m_Components)
		}

		void Engine::PostGui()
		{
			FFMCP(PostGui, m_ModuleContainer.m_Components)
		}

		void Engine::FrameEnd()
		{
			FFMCP(FrameEnd, m_ModuleContainer.m_Components)
		}

		void Engine::PreDraw()
		{
			FFMCP(PreDraw, m_ModuleContainer.m_Components)
		}

		void Engine::PostDraw()
		{
			FFMCP(PostDraw, m_ModuleContainer.m_Components)
		}

		void Engine::Gizmos()
		{
			FFMCP(Gizmos, m_ModuleContainer.m_Components)
		}

		void Engine::PreGui()
		{
			FFMCP(PreGui, m_ModuleContainer.m_Components)
		}

		void Engine::Boot()
		{
			// TODO: Create boolean to check and create CoreModule.
			if (true)
			{
				auto* coreModule = m_ModuleContainer.GetComponent<CoreModule>();
				if (!coreModule)
				{
					coreModule = m_ModuleContainer.AddComponent<CoreModule>();
				}
				if (!coreModule)
				{
					// TODO: Debug Check
					return;
				}
				m_Core = coreModule;
			}
			FFMCP(Boot, m_ModuleContainer.m_Components)
		}

		void Engine::Created()
		{
		}

		void Engine::Awake()
		{
			FFMCP(Awake, m_ModuleContainer.m_Components)
		}

		void Engine::Start()
		{
			FFMCP(Start, m_ModuleContainer.m_Components)
		}

		void Engine::Update()
		{
			FFMCP(Update, m_ModuleContainer.m_Components)
		}

		void Engine::LateUpdate()
		{
			FFMCP(LateUpdate, m_ModuleContainer.m_Components)
		}

		void Engine::FixedUpdate()
		{
			FFMCP(FixedUpdate, m_ModuleContainer.m_Components)
		}

		void Engine::Draw()
		{
			FFMCP(Draw, m_ModuleContainer.m_Components)
		}

		void Engine::Gui()
		{
			FFMCP(Gui, m_ModuleContainer.m_Components)
		}

		void Engine::Dispose()
		{
			FFMCP(Dispose, m_ModuleContainer.m_Components)
		}

		void Engine::Deleted()
		{
		}

		bool Engine::GetCondition(const std::string& name)
		{
			const auto it = EngineConditions.find(name);
			if(it != EngineConditions.end())
			{
				return it->second;
			}
			return false;
		}

		void Engine::SetCondition(const std::string& name, const bool& value)
		{
			const auto it = EngineConditions.find(name);
			if (it != EngineConditions.end())
			{
				EngineConditions[name] = value;
			}
			AddCondition(name, value);
		}

		void Engine::AddCondition(const std::string& name, const bool& value)
		{
			EngineConditions.emplace(name, value);
		}
	}
}