#include <pch.h>
#include "Application.h"

#include "Engine.h"

namespace Eclipse
{
	namespace Engine
	{
		Application* Application::Instance = nullptr;

		auto Application::Created() -> void
		{
			m_shouldClose = false;
			m_Engine = new Engine();
			Instance->OnCreated();
		}
		auto Application::Awake() const -> void
		{
			m_Engine->Awake();
			Instance->OnAwake();
		}
		auto Application::Start() const -> void
		{
			m_Engine->Start();
			Instance->OnStart();
		}
		auto Application::Update() const -> void
		{
			m_Engine->Update();
			Instance->OnUpdate();
		}
		auto Application::LateUpdate() const -> void
		{
			m_Engine->LateUpdate();
			Instance->OnLateUpdate();
		}
		auto Application::FixedUpdate() const -> void
		{
			m_Engine->FixedUpdate();
			Instance->OnFixedUpdate();
		}
		auto Application::Draw() const -> void
		{
			m_Engine->Draw();
			Instance->OnDraw();
		}
		auto Application::Gui() const -> void
		{
			m_Engine->Gui();
			Instance->OnGui();
		}
		auto Application::Dispose() const -> void
		{
			m_Engine->Dispose();
			Instance->OnDispose();
		}
		auto Application::Deleted() const -> void
		{
			Instance->OnDeleted();
			delete m_Engine;
		}
		auto Application::OnCreated() -> void
		{
			DEBUG(Application Created!)
		}
		auto Application::OnAwake() -> void
		{
			Core::Debug::Log("Awake not overridden.");
		}
		auto Application::OnStart() -> void
		{
			Core::Debug::Log("Start not overridden.");
		}
		auto Application::OnUpdate() -> void
		{
			Core::Debug::Log("Update not overridden");
		}
		auto Application::OnLateUpdate() -> void
		{
			Core::Debug::Log("Late Update not overridden");
		}
		auto Application::OnFixedUpdate() -> void
		{
			Core::Debug::Log("Fixed Update not overridden");
		}
		auto Application::OnDraw() -> void
		{
			Core::Debug::Log("Draw not overridden");
		}
		auto Application::OnGui() -> void
		{
			Core::Debug::Log("Gui not overridden");
		}
		auto Application::OnDispose() -> void
		{
			Core::Debug::Log("Dispose not overridden");
		}
		auto Application::OnDeleted() -> void
		{
			DEBUG(Application Deleted!)
		}
		auto Application::Run() -> void
		{
			Core::Window::InitWindow(Instance->settings.windowWidth, Instance->settings.windowHeight, Instance->settings.windowTitle.c_str());

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
			Instance->Deleted();
		}
		auto Application::Stop() -> void
		{
			Instance->m_shouldClose = true;
		}
		auto Application::ShouldClose() const -> bool
		{
			if (!Instance)
				return true;
			return m_shouldClose || Core::Window::WindowShouldTerminate();
		}
		auto Application::SetBackgroundColor(Core::Data::ECC color) -> void
		{
			Instance->settings.refreshColor = color;
		}

		Application::~Application()
		{
			delete m_Engine;
		}
	}
}