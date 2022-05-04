#include "NetworkServerApplication.h"

#include "EclipseEngine/include/Object.h"
#include "EclipseEngine/include/ObjectFactory.h"

#include "EclipseNetworking/include/EclipseServer.h"
#include "EclipseNetworking/include/NetworkServer.h"

using namespace Eclipse;
using namespace Engine;
using namespace Networking;

void NetworkServerApplication::OnEngineInit()
{
	// create object
	const auto serverObject = new Object();
	ObjectFactory::CompositeObject<NetworkServer>(*serverObject);
	// add to scene.
	SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(serverObject);

	// get client component
	const auto server = serverObject->m_ComponentContainer.GetComponent<NetworkServer>();
	if (server)
	{
		server->networkPort = 5456;
		server->networkAddress = "localhost";
		server->StartProcess();
	}
}
