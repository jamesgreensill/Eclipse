#include "WindowModule.h"

#include "Application.h"
#include "Core.h"

namespace Eclipse
{
	namespace Engine
	{
		void WindowModule::Created()
		{
		}

		void WindowModule::Deleted()
		{
		}

		void WindowModule::RetrieveGuiData()
		{
			EngineModule::RetrieveGuiData();
		}

		void WindowModule::PreEngineInit()
		{
			EngineModule::PreEngineInit();
		}

		void WindowModule::EngineInit()
		{
			Core::Window::InitWindow(Application::Instance->settings.windowWidth, Application::Instance->settings.windowHeight, Application::Instance->settings.windowTitle.c_str());
		}

		void WindowModule::PostEngineInit()
		{
			EngineModule::PostEngineInit();
		}

		void WindowModule::PostBoot()
		{
			EngineModule::PostBoot();
		}

		void WindowModule::Boot()
		{
		}

		void WindowModule::OnAwake()
		{
			EngineModule::OnAwake();
		}

		void WindowModule::OnStart()
		{
			EngineModule::OnStart();
		}

		void WindowModule::OnLateStart()
		{
			EngineModule::OnLateStart();
		}

		void WindowModule::OnFrameBegin()
		{
		}

		void WindowModule::OnFixedUpdate()
		{
			EngineModule::OnFixedUpdate();
		}

		void WindowModule::OnUpdate()
		{
			EngineModule::OnUpdate();
		}

		void WindowModule::OnLateUpdate()
		{
			EngineModule::OnLateUpdate();
		}

		void WindowModule::OnPreDraw()
		{
			Core::Window::BeginDrawing();
		}

		void WindowModule::OnDraw()
		{
			EngineModule::OnDraw();
		}

		void WindowModule::OnPostDraw()
		{
			Core::Window::EndDrawing();
		}

		void WindowModule::OnGizmos()
		{
			EngineModule::OnGizmos();
		}

		void WindowModule::OnPreGui()
		{
			EngineModule::OnPreGui();
		}

		void WindowModule::OnGui()
		{
			EngineModule::OnGui();
		}

		void WindowModule::OnPostGui()
		{
			EngineModule::OnPostGui();
		}

		void WindowModule::OnFrameEnd()
		{
			EngineModule::OnFrameEnd();
		}

		void WindowModule::OnDispose()
		{
			Core::Window::CloseWindow();
		}
	}
}