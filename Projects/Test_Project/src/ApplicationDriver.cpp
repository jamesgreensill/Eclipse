// Core Engine
#include <EclipseEngine/include/Application.h>
#include <EclipseEngine/include/WindowModule.h>
#include <EclipseGraphics/include/GraphicsModule.h>
#include <EclipseDebugging/include/DebugModule.h>

#include "ApplicationDemo.h"

int main()
{
    Eclipse::Engine::Application::Create<ApplicationDemo>({});

    Eclipse::Engine::Application::Initialize<>(Eclipse::Engine::Application::Instance);

    Eclipse::Engine::Application::Run();
}