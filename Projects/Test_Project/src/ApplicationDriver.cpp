// Core Engine
#include <EclipseEngine/include/Application.h>
#include <EclipseEngine/include/WindowModule.h>
#include <EclipseGraphics/include/GraphicsModule.h>
#include <EclipseDebugging/include/DebugModule.h>

#include "ApplicationDemo.h"

int main()
{
	Eclipse::Engine::Application::Create<ApplicationDemo>({"Tutorial_3 - Hello There... Window", 1000,1000,100,100});

	Eclipse::Engine::Application::Initialize<Eclipse::Engine::WindowModule, Eclipse::Graphics::GraphicsModule, Eclipse::Debug::DebugModule>(Eclipse::Engine::Application::Instance);

	Eclipse::Engine::Application::Run();
}