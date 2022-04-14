#include "Application.h"

#include "Engine.h"

namespace Eclipse
{
	namespace Engine
	{
		Application* Application::Instance = nullptr;
		EclipseEvent<> Application::TestEvent{};

		auto Application::Run(SceneManagement::Scene* mainScene) -> void
		{
			if (Instance->m_Engine)
				Instance->m_Engine->Run(mainScene);
			else
			{
				// TODO: Debug: Failed To Run Engine.
			}
			// Engine.run.

			/*Core::Window::InitWindow(Instance->settings.windowWidth, Instance->settings.windowHeight, Instance->settings.windowTitle.c_str());

			Instance->Created();
			Instance->Awake();
			Instance->Start();

			while (!Instance->ShouldClose())
			{
				Instance->Update();
				Instance->LateUpdate();

				Core::Rendering::BeginDrawing();
				Core::Rendering::ClearBackground(Instance->settings.refreshColor);
				Instance->Draw();
				Instance->Gui();
				Core::Rendering::EndDrawing();
			}
			Instance->Dispose();
			Instance->Deleted();*/
		}
		auto Application::Stop() -> void
		{
			Instance->m_shouldClose = true;
		}
		auto Application::ShouldClose() const -> bool
		{
			if (!Instance)
				return true;
			return m_shouldClose;
		}
		auto Application::SetBackgroundColor(Core::Data::ECC color) -> void
		{
			Instance->settings.refreshColor = color;
		}
		Application::Application()
		{
			if (!m_Engine)
				m_Engine = new Engine();
			if (!Instance)
				Instance = this;
			else delete this;
		}

		Application::~Application()
		{
			delete m_Engine;
		}
	}
}