#pragma once
#include "NetworkManager.h"

namespace Eclipse
{
	namespace Networking
	{
		class NetworkServer :
			public NetworkManager
		{
		protected:
			void Reset() override;
			void onConnectionLost(EclipsePacket& packet) override;
			void onIncomingConnection(EclipsePacket& packet) override;
			void onIncomingDisconnection(EclipsePacket& packet) override;
		public:

			unsigned short maxConnections = 32;

			void StartProcess() override;
			void StopProcess() override;
		private:
			bool _removeConnection(RakNet::SystemAddress address);
			void _addConnection(RakNet::SystemAddress address);
		protected:
			int32_t GetConnectionCount() override;
		private:
			std::vector<RakNet::SystemAddress> ConnectedClients = {};
		};
	}
}
