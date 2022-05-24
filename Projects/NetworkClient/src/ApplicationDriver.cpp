#include <EclipseDebugging/include/DebugModule.h>
#include "ApplicationDemo.h"


using namespace Eclipse;
using namespace Engine;

int main()
{
	Application::Create<ApplicationDemo>({});
	Application::Initialize<Eclipse::Debug::DebugModule>(Application::Instance);
	Application::Run();
}

