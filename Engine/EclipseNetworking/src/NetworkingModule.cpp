#include "NetworkingModule.h"
#include "NetworkingApi.h"
#include "NetworkingBus.h"

#include "EclipseEngine/include/ApiLoader.h"

namespace Eclipse
{
	namespace Networking
	{
		void NetworkingModule::Created()
		{
		}

		void NetworkingModule::Boot()
		{
			Engine::ApiLoader::Load<NetworkingApi>();
			m_SystemsContainer.AddComponent<NetworkingBus>();
		}

		void NetworkingModule::Deleted()
		{
		}
	}
}