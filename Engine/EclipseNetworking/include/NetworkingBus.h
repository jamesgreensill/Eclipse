#pragma once
#include <queue>
#include <EclipseEngine/include/System.h>
#include <raknet/RakPeerInterface.h>
#include "EclipsePacket.h"

namespace Eclipse
{
	namespace Networking
	{

		struct NetworkCall
		{
			// data to be sent
			EclipsePacket& packet;
			// network sender.
			RakNet::RakPeerInterface* sender = nullptr;
			// recipient address
			RakNet::SystemAddress& address;
			uint32_t forceReceiptNumber = 0;
			char orderingChannel{};
			bool broadcast{};
		};

		class NetworkingBus :
			public Engine::System
		{
		public:
			void Created() override;
			void Deleted() override;
			void Update() override;

			/**
			 * \brief This will immediately send the network call to the recipient.
			 * \param call network call to be sent.
			 */
			void SendPacketImmediate(NetworkCall& call);
			/**
			 * \brief This will buffer the call to be sent at a later point in the frame.
			 * \param call network call to be sent
			 */
			void SendPacket(const NetworkCall& call);

			static NetworkingBus* Instance;
		private:
			/**
			 * \brief This will send all buffered packets.
			 */
			void SendBufferedPackets();
			void _sendPacket(EclipsePacket* packet, RakNet::RakPeerInterface* sender, char orderingChannel,
				const RakNet::SystemAddress& systemIdentifier, bool broadcast, uint32_t forceReceiptNumber);
			std::queue<NetworkCall> networkBuffer = {};
			int packetsSentLastFrame = 0;
			int packetSentDelta = 0;
		};
	}
}
