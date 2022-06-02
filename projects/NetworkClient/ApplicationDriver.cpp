#include <EclipseDebugging/include/DebugModule.h>
#include <EclipseNetworking/include/NetworkingModule.h>

#include "NetworkClientApplication.h"

using namespace Eclipse;
using namespace Engine;

int main()
{
    Application::Create<NetworkClientApplication>({});
    Application::Initialize<Eclipse::Debug::DebugModule, Eclipse::Networking::NetworkingModule >(Application::Instance);
    Application::Run();
}