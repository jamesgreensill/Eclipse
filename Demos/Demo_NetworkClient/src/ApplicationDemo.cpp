#include "ApplicationDemo.h"

#include <EclipseEngine/include/Object.h>
#include <EclipseEngine/include/ObjectFactory.h>
#include <EclipseNetworking/include/NetworkClient.h>

#include "EclipseChat/include/NetworkChatInterface.h"

using namespace Eclipse;
using namespace Engine;
using namespace Networking;

void ApplicationDemo::OnCreated()
{
	Application::OnCreated();
}

void ApplicationDemo::OnBoot()
{
	Application::OnBoot();
}

void ApplicationDemo::OnEngineInit()
{
	// create object
	const auto clientObject = new Object();
	ObjectFactory::CompositeObject<NetworkClient>(*clientObject);
	// add to scene.
	SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(clientObject);
	const auto client = clientObject->m_ComponentContainer.GetComponent<NetworkClient>();

	// get client component
	if (client)
	{
		client->networkPort = 5456;
		client->networkAddress = "localhost";
		client->StartProcess();
	}
}

void ApplicationDemo::OnAwake()
{
	Application::OnAwake();
}

void ApplicationDemo::OnDisposed()
{
	Application::OnDisposed();
}