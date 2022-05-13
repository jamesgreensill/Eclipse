#include "NetworkServerApplication.h"

#include "EclipseChat/include/ConsoleChatWriter.h"
#include "EclipseChat/include/NetworkChatInterface.h"
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

	server->handler.OnPacketReceived.emplace((unsigned)NetworkIdentifiers::EID_MESSAGE, new EclipseEvent<EclipsePacket&>);
	//server->handler.GetReceivedHandle(TEST)->AddListener([](auto packet)
	//	{
	//		External::Debug::DebugAPI::Debug("Packet Received!");
	//	});

	if (chatInterface)
		chatInterface->StartInterface();
	if (server)
	{
		server->networkPort = 5456;
		server->networkAddress = "localhost";
		server->StartProcess();
	}

	
}
