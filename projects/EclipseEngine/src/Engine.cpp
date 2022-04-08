#include <pch.h>
#include <EclipseGraphics/include/Renderer.h>
#include <EclipseGui/include/ImGuiRenderer.h>

#include "Engine.h"
#include "Resources.h"
#include "Scene.h"
#include "SceneManager.h"
#include "SystemManager.h"

namespace Eclipse
{
	namespace Engine
	{
		Engine::Engine()
		{
			SystemManager::CreateSystem<Rendering::Renderer>();
			SystemManager::CreateSystem<Gui::ImGuiRenderer>();
			SystemManager::CreateSystem<SceneManagement::SceneManager>();

			Engine::Created();
		}
		void Engine::Created()
		{
		}

		void Engine::Awake()
		{
			SystemManager::Awake();
			Resources::LoadShaderProgram("./Data/Shaders/default.vs",
				"./Data/Shaders/default.fs", "defaultShader");
		}

		void Engine::Start()
		{
			SystemManager::Start();
		}

		void Engine::Update()
		{
			SystemManager::Update();
		}

		void Engine::LateUpdate()
		{
			SystemManager::LateUpdate();
		}

		void Engine::FixedUpdate()
		{
			SystemManager::FixedUpdate();
		}

		void Engine::Draw()
		{
			SystemManager::Draw();
		}

		void Engine::Gui()
		{
			SystemManager::Gui();
		}

		void Engine::RetrieveGuiData(ImGuiTypes::ImGuiCall& call)
		{
			BaseModel::RetrieveGuiData(call);
		}

		void Engine::Dispose()
		{
			SystemManager::Dispose();
		}

		void Engine::Deleted()
		{
		}
	}
}