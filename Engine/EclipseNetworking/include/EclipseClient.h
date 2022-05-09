#pragma once
#include <EclipseEngine/include/Component.h>
#include <RakPeerInterface.h>

#include "ClientHandler.h"

namespace Eclipse
{
	namespace Networking
	{
		class EclipseClient :
			public Components::Component
		{
		public:

			void Send(EclipsePacket& packet, char orderingChannel, const RakNet::AddressOrGUID& systemIdentifier, bool broadcast, uint32_t forceReceiptNumber = 0);
		private:
			void InitializeClientConnection();
			void HandleNetworkMessages();

			ClientHandler m_handler_ = {};
			RakNet::RakPeerInterface* peerInterface = nullptr;
			const char* ip = "127.0.0.1";
			const unsigned short PORT = 5456;
		protected:
			void Awake() override;
			void Update() override;
			void Reset() override;
		};
	}
}
