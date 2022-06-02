#include "NetworkClientApplication.h"

#include <EclipseEngine/include/Object.h>
#include <EclipseEngine/include/ObjectFactory.h>
#include <EclipseNetworking/include/NetworkClient.h>

#include "EclipseChat/include/ConsoleChatWriter.h"
#include "EclipseChat/include/NetworkChatInterface.h"

#include "ChatSender.h"
#include "EclipseEngine/include/Console.h"
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
	std::string ipString;
	std::getline(std::cin, ipString);

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
		// query the engine to stop.
		Application::Stop();
		return;
	}

	// create object
	const auto clientObject = new Object();
	ObjectFactory::CompositeObject<Eclipse::Application::ChatSender, NetworkClient, Chat::NetworkChatInterface, Chat::ChatManager, Chat::ConsoleChatWriter>(*clientObject);
	// add to scene.
	SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(clientObject);
	const auto client = clientObject->m_ComponentContainer.GetComponent<NetworkClient>();

	auto chatInterface = clientObject->m_ComponentContainer.GetComponent<Chat::NetworkChatInterface>();

	client->handler.OnPacketReceived.AddEvent((unsigned)NetworkIdentifiers::EID_MESSAGE, new EclipseEvent<EclipsePacket&>);

	if (chatInterface)
		chatInterface->StartInterface();

	// get client component
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