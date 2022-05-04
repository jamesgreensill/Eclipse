#include "NetworkClient.h"

#include <EclipseEngine/include/Core.h>

namespace Eclipse
{
	namespace Networking
	{
		void NetworkClient::Reset()
		{
		}

		void NetworkClient::StartProcess()
		{
			StartProcess(networkAddress);
		}

		void NetworkClient::StopProcess()
		{
			networkInterfaceInstance->CloseConnection(hostServer, true);
		}

		int32_t NetworkClient::GetConnectionCount()
		{
			return networkInterfaceInstance ? networkInterfaceInstance->NumberOfConnections() : -1;
		}

		void NetworkClient::StartProcess(const std::string& uri)
		{
			// create socket.
			RakNet::SocketDescriptor socket;

			// initialize packet handler.
			handler.InitializeHandler();

			// initialize default handles. (optional)
			InitializeDefaultHandles();

			// get peer interface.
			networkInterfaceInstance = RakNet::RakPeerInterface::GetInstance();

			// try to start peer interface.
			auto startupResult = networkInterfaceInstance->Startup(1, &socket, 1);
			if (startupResult != RakNet::RAKNET_STARTED)
			{
				External::Debug::DebugAPI::Error(("Failed to start client. error code: " + std::to_string(startupResult)).c_str());
				return;
			}
			// connect to given address and port.
			auto connectionResult = networkInterfaceInstance->Connect(uri.c_str(), networkPort, nullptr, 0);
			if (connectionResult != RakNet::CONNECTION_ATTEMPT_STARTED)
			{
				External::Debug::DebugAPI::Error(("Failed to connect to server: " + networkAddress + ":" + std::to_string(networkPort) + ". error code: " + std::to_string(startupResult)).c_str());
				return;
			}

			hostServer = RakNet::SystemAddress(uri.c_str());
		}
	}
}