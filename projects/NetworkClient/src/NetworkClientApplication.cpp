#include "NetworkClientApplication.h"

#include <EclipseEngine/include/Object.h>
#include <EclipseEngine/include/ObjectFactory.h>
#include <EclipseNetworking/include/NetworkClient.h>

#include "EclipseChat/include/ConsoleChatWriter.h"
#include "EclipseChat/include/NetworkChatInterface.h"

#include "ChatSender.h"

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

	// get client component
	const auto client = clientObject->m_ComponentContainer.GetComponent<NetworkClient>();
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