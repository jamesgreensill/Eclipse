#include "NetworkClientApplication.h"

#include <EclipseEngine/include/Object.h>
#include <EclipseEngine/include/ObjectFactory.h>
#include <EclipseNetworking/include/NetworkClient.h>

#include "EclipseChat/include/ConsoleChatWriter.h"
#include "EclipseChat/include/NetworkChatInterface.h"

#include "ChatSender.h"
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
		client->networkPort = 5456;
		client->networkAddress = "localhost";
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