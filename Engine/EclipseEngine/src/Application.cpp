#include "Application.h"

#include "Engine.h"

namespace Eclipse
{
	namespace Engine
	{
		Application* Application::Instance = nullptr;

		auto Application::Run() -> void
		{
			if (Instance->m_Engine)
				Instance->m_Engine->Run();
			else
			{
				// TODO: Debug: Failed To Run Engine.
			}

		}
		auto Application::Stop() -> void
		{
			Instance->m_shouldClose = true;
		}
		auto Application::ShouldClose() const -> bool
		{
			if (!Instance)
				return true;
			return Core::Window::WindowShouldTerminate(Instance);
		}
		auto Application::SetBackgroundColor(Core::Data::ECC color) -> void
		{
			Instance->settings.refreshColor = color;
		}
		Application::Application()
		{
			// singleton pattern.
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

		void Application::OnCreated(){}
		void Application::OnDisposed(){}
		void Application::OnBoot(){}
		void Application::OnEngineInit(){}
		void Application::OnAwake(){}
	}
}