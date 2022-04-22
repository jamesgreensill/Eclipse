#include "GraphicsModule.h"

#include <EclipseEngine/include/ObjectFactory.h>
#include <EclipseEngine/include/Application.h>
#include <EclipseEngine/include/ApiLoader.h>
#include <EclipseEngine/include/Engine.h>

#include "GraphicsApi.h"
#include "Renderer.h"
#include "Core.h"


namespace Eclipse
{
	namespace Graphics
	{
		Engine::EclipseEvent<> GraphicsModule::OnOpenGLLoad = {};

		void GraphicsModule::EngineInit()
		{
		}

		void GraphicsModule::PostEngineInit()
		{
			StartOpenGLInitialization();
			EndOpenGLInitialization();
		}

		void GraphicsModule::Created()
		{
		}

		void GraphicsModule::Deleted()
		{
		}

		void GraphicsModule::Boot()
		{
			Engine::ApiLoader::Load<GraphicsApi>();
			m_SystemsContainer.AddComponent<Renderer>();
		}

		void GraphicsModule::OnAwake()
		{
		}

		void GraphicsModule::OnFrameBegin()
		{
			Core::Window::ClearBackground(Engine::Application::Instance->settings.refreshColor);
		}

		void GraphicsModule::OnPreDraw()
		{
			Graphics::ClearScreen(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void GraphicsModule::OnPostDraw()
		{
			EngineModule::OnPostDraw();
		}
	}
}