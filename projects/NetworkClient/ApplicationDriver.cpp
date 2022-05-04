#include <EclipseDebugging/include/DebugModule.h>
#include "NetworkClientApplication.h"


using namespace Eclipse;
using namespace Engine;

int main()
{
	Application::Create<NetworkClientApplication>({});
	Application::Initialize<Eclipse::Debug::DebugModule>(Application::Instance);
	Application::Run();
}

