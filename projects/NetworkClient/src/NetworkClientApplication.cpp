#include "NetworkClientApplication.h"

#include <EclipseEngine/include/Object.h>
#include <EclipseNetworking/include/NetworkClient.h>

#include "EclipseChat/include/ConsoleChatWriter.h"
#include "EclipseChat/include/NetworkChatInterface.h"

#include "ChatSender.h"
#include "EclipseEngine/include/Console.h"
#include "EclipseEngine/include/SceneManager.h"
#include "EclipseNetworking/include/NetworkIdentifiers.h"

using namespace Eclipse;
using namespace Engine;
using namespace Networking;

void NetworkClientApplication::OnCreated()
{
    Application::OnCreated();
}

void NetworkClientApplication::OnBoot()
{
    Application::OnBoot();
}

void NetworkClientApplication::OnEngineInit()
{
    Console::WriteLine("Enter the server IP.");
    std::string ipString = Console::ReadLine();

    Console::WriteLine("Enter port to start server.");
    std::string portString = Console::ReadLine();

    short port;
    try
    {
        port = static_cast<short>(std::stoi(portString));
    }
    catch (...)
    {
        External::Debug::DebugAPI::Error("Port input was invalid.");
        // query the engine to stop.
        Application::Stop();
        return;
    }

    // create object
    const auto client_object = new Object();

    client_object->m_ComponentContainer.AddComponent<Eclipse::Application::ChatSender>();

    const auto client = client_object->m_ComponentContainer.AddComponent<NetworkClient>();
    const auto chatInterface = client_object->m_ComponentContainer.AddComponent<Chat::NetworkChatInterface>();

    client_object->m_ComponentContainer.AddComponent<Chat::ChatManager>();
    client_object->m_ComponentContainer.AddComponent<Chat::ConsoleChatWriter>();

    SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(client_object);

   // client->handler.OnPacketReceived.AddEvent((unsigned)EID_MESSAGE, new EclipseEvent<NetworkPacket&>);

    if (chatInterface)
        chatInterface->StartInterface();

    if (client)
    {
        client->networkPort = port;
        client->networkAddress = ipString;
        client->StartProcess();
    }
}

void NetworkClientApplication::OnAwake()
{
    Application::OnAwake();
}

void NetworkClientApplication::OnDisposed()
{
    Application::OnDisposed();
}