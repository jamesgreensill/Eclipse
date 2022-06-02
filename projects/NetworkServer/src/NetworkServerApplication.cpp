#include "NetworkServerApplication.h"

#include "EclipseChat/include/ConsoleChatWriter.h"
#include "EclipseChat/include/NetworkChatInterface.h"
#include "EclipseEngine/include/Console.h"
#include "EclipseEngine/include/Object.h"
#include "EclipseEngine/include/ObjectFactory.h"

#include "EclipseNetworking/include/EclipseServer.h"
#include "EclipseNetworking/include/NetworkIdentifiers.h"
#include "EclipseNetworking/include/NetworkServer.h"

using namespace Eclipse;
using namespace Engine;
using namespace Networking;

enum TID
{
    TEST = ID_USER_PACKET_ENUM + 1,
};

void NetworkServerApplication::OnEngineInit()
{
    // create object
    const auto serverObject = new Object();
    ObjectFactory::CompositeObject<NetworkServer, Chat::NetworkChatInterface, Chat::ChatManager, Chat::ConsoleChatWriter>(*serverObject);
    // add to scene.
    SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(serverObject);

    // get client component
    const auto server = serverObject->m_ComponentContainer.GetComponent<NetworkServer>();

    auto chatInterface = serverObject->m_ComponentContainer.GetComponent<Chat::NetworkChatInterface>();

    server->handler.OnPacketReceived.AddEvent(static_cast<unsigned>(EID_MESSAGE), new EclipseEvent<EclipsePacket&>);

    Console::WriteLine("Enter port to start server.");
    std::string portString;
    std::getline(std::cin, portString);

    short port;
    try
    {
        port = static_cast<short>(std::stoi(portString));
    }
    catch (...)
    {
        External::Debug::DebugAPI::Error("Port input was invalid.");
        return;
    }

    if (chatInterface)
        chatInterface->StartInterface();
    if (server)
    {
        server->networkPort = port;
        server->StartProcess();
    }
}