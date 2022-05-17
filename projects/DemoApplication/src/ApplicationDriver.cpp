// Core Engine
#include <EclipseEngine/include/Application.h>
#include <EclipseEngine/include/WindowModule.h>

// Debug
#include <EclipseDebugging/include/DebugModule.h>

// Graphics
#include <EclipseGraphics/include/GraphicsModule.h>


#include "ApplicationDemo.h"

int main()
{
	Eclipse::Engine::Application::Create<ApplicationDemo>({});

	Eclipse::Engine::Application::Initialize<Eclipse::Debug::DebugModule, Eclipse::Engine::WindowModule, Eclipse::Graphics::GraphicsModule>(Eclipse::Engine::Application::Instance);

	Eclipse::Engine::Application::Run();
}