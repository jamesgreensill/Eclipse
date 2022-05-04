#include "NetworkServer.h"
#include <EclipseEngine/include/Core.h>

namespace Eclipse
{
	namespace Networking
	{
		void NetworkServer::Reset() {}

		void NetworkServer::onConnectionLost(EclipsePacket& packet)
		{
			auto addressToRemove = packet.m_packet_->systemAddress;
			if (_removeConnection(addressToRemove))
			{
				External::Debug::DebugAPI::Debug((std::string(addressToRemove.ToString()) + " successfully disconnected.").c_str());
			}
			else
			{
				// this should never be called.
				External::Debug::DebugAPI::Error((std::string(addressToRemove.ToString()) + " was never connected or failed to disconnect.").c_str());
			}
		}

		void NetworkServer::onIncomingConnection(EclipsePacket& packet)
		{
			auto addressToAdd = packet.m_packet_->systemAddress;
			_addConnection(addressToAdd);
			External::Debug::DebugAPI::Debug((std::string(addressToAdd.ToString()) + " successfully connected").c_str());
		}

		void NetworkServer::onIncomingDisconnection(EclipsePacket& packet)
		{
			auto addressToRemove = packet.m_packet_->systemAddress;
			if (_removeConnection(addressToRemove))
			{
				External::Debug::DebugAPI::Debug((std::string(addressToRemove.ToString()) + " successfully disconnected.").c_str());
			}
			else
			{
				// this should never be called.
				External::Debug::DebugAPI::Error((std::string(addressToRemove.ToString()) + " was never connected or failed to disconnect.").c_str());
			}
		}

		void NetworkServer::StartProcess()
		{
			networkManagerType = NetworkManagerType::Server;

			// create socket
			RakNet::SocketDescriptor socket(networkPort, 0);

			// initialize event based packet handler.
			handler.InitializeHandler();

			// initialize default handles.
			InitializeDefaultHandles();

			// TODO: Replace with network interface wrapper.
			// set the peer interface.
			networkInterfaceInstance = RakNet::RakPeerInterface::GetInstance();

			// begin the server.
			auto result = networkInterfaceInstance->Startup(maxConnections, &socket, 1);
			if (result != RakNet::RAKNET_STARTED)
			{
				External::Debug::DebugAPI::Error("Failed to start");
				return;
			}
			// set he maximum client connections.
			External::Debug::DebugAPI::Debug(("Successfully started server on port: " + std::to_string(networkPort)).c_str());
			networkInterfaceInstance->SetMaximumIncomingConnections(maxConnections);
		}

		void NetworkServer::StopProcess() {}

		bool NetworkServer::_removeConnection(RakNet::SystemAddress address)
		{
			const auto it = std::find(ConnectedClients.begin(), ConnectedClients.end(), address);
			if (it != ConnectedClients.end())
			{
				ConnectedClients.erase(it);
				return true;
			}
			return false;
		}

		void NetworkServer::_addConnection(RakNet::SystemAddress address)
		{
			ConnectedClients.emplace_back(address);
		}

		int32_t NetworkServer::GetConnectionCount()
		{
			return networkInterfaceInstance ? networkInterfaceInstance->NumberOfConnections() : -1;
		}
	}
}