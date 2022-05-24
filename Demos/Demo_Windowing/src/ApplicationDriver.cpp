// Core Engine
#include <EclipseEngine/include/Application.h>

#include <EclipseDebugging/include/DebugModule.h>
#include <EclipseEngine/include/WindowModule.h>

#include "ApplicationDemo.h"

int main()
{
	Eclipse::Engine::Application::Create<ApplicationDemo>({});

	Eclipse::Engine::Application::Initialize<Eclipse::Engine::WindowModule, Eclipse::Debug::DebugModule>(Eclipse::Engine::Application::Instance);

	Eclipse::Engine::Application::Run();
}