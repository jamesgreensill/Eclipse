#include "ApplicationDemo.h"

#include <EclipseEngine/include/Object.h>
#include <EclipseEngine/include/ObjectFactory.h>
#include <EclipseNetworking/include/NetworkServer.h>

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
	const auto serverObject = new Object();
	ObjectFactory::CompositeObject<NetworkServer>(*serverObject);
	// add to scene.
	SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(serverObject);
	const auto server = serverObject->m_ComponentContainer.GetComponent<NetworkServer>();

	// get client component
	if (server)
	{
		server->networkPort = 5456;
		server->networkAddress = "localhost";
		server->StartProcess();
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