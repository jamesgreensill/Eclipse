#include "NetworkServerApplication.h"

#include "EclipseEngine/include/Object.h"
#include "EclipseNetworking/include/NetworkServer.h"
#include "EclipseChat/include/ConsoleChatWriter.h"
#include "EclipseChat/include/NetworkChatInterface.h"
#include "EclipseEngine/include/SceneManager.h"

#include "EclipseEngine/include/Console.h"
#include "EclipseNetworking/include/NetworkIdentifiers.h"

using namespace Eclipse;
using namespace Engine;
using namespace Networking;

void NetworkServerApplication::OnEngineInit()
{

    Console::WriteLine("Enter port to start server.");
    const std::string& portString = Console::ReadLine();

    short port;
    try
    {
        port = static_cast<short>(std::stoi(portString));
    }
    catch (...)
    {
        External::Debug::DebugAPI::Error("Port input was invalid.");
        Application::Stop();
        return;
    }

    // create object
    const auto serverObject = new Object();
    const auto server = serverObject->m_ComponentContainer.AddComponent<NetworkServer>();
    const auto chatInterface = serverObject->m_ComponentContainer.AddComponent<Chat::NetworkChatInterface>();
    serverObject->m_ComponentContainer.AddComponent<Chat::ChatManager>();
    serverObject->m_ComponentContainer.AddComponent<Chat::ConsoleChatWriter>();

    // add to scene.
    SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(serverObject);

    server->handler.OnPacketReceived.AddEvent(static_cast<unsigned>(EID_MESSAGE), new EclipseEvent<NetworkPacket&>);

    if (chatInterface)
        chatInterface->StartInterface();
    if (server)
    {
        server->networkPort = port;
        server->StartProcess();
    }
}