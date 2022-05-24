// Core Engine
#include <EclipseEngine/include/Application.h>

#include "ApplicationDemo.h"

int main()
{
	Eclipse::Engine::Application::Create<ApplicationDemo>({});

	Eclipse::Engine::Application::Initialize</*INSERT MODULES HERE*/>(Eclipse::Engine::Application::Instance);

	Eclipse::Engine::Application::Run();
}