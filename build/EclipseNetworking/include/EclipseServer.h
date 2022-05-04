#pragma once
#include <EclipseEngine/include/Component.h>
#include <raknet/RakPeerInterface.h>

#include "ServerHandler.h"

namespace Eclipse
{
	namespace Networking
	{
		class EclipseServer :
			public Components::Component
		{
		public:
		private:
			ServerHandler m_handler_;

			unsigned short PORT = 5456;
			unsigned int MAX_CONNECTIONS = 32;

			RakNet::RakPeerInterface* peerInterface = nullptr;

			std::vector<RakNet::SystemAddress> connectedClients = {};

		protected:
			void Send(EclipsePacket* packet, char orderingChannel, const RakNet::SystemAddress& systemIdentifier,
				bool broadcast,
				uint32_t forceReceiptNumber);
			void HandleNetworkMessages();
			void InitializeServer();
			void Awake() override;
			void Update() override;
			void Reset() override;
		};
	}
}
