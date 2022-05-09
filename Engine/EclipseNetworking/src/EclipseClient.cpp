#include "EclipseClient.h"

#include <iostream>
#include <MessageIdentifiers.h>
#include <RakString.h>

namespace Eclipse
{
	namespace Networking
	{
		enum class TestId
		{
			Test = ID_USER_PACKET_ENUM + 1,
		};

		void EclipseClient::Send(EclipsePacket& packet, char orderingChannel, const RakNet::AddressOrGUID& systemIdentifier, bool broadcast, uint32_t forceReceiptNumber)
		{
			// send packet to server.
			peerInterface->Send(&packet.stream_, packet.priority, packet.reliability, orderingChannel, systemIdentifier, broadcast, forceReceiptNumber);
		}

		void EclipseClient::InitializeClientConnection()
		{
			m_handler_.InitializeHandler();
			m_handler_.SetClient(this);

			m_handler_.OnPacketReceived.emplace((unsigned)TestId::Test, new Engine::EclipseEvent<const EclipsePacket&>);

			*m_handler_.GetReceivedHandle((unsigned)TestId::Test) += [](const EclipsePacket& packet)
			{
				std::cout << &packet.m_packet_->data << std::endl;
			};

			peerInterface = RakNet::RakPeerInterface::GetInstance();
			RakNet::SocketDescriptor sd;

			peerInterface->Startup(1, &sd, 1);

			auto res = peerInterface->Connect(ip, PORT, nullptr, 0);
			
			if (res != RakNet::CONNECTION_ATTEMPT_STARTED)
			{
				std::cout << "failed to connect: error number " << res << std::endl;
			}
		}

		void EclipseClient::HandleNetworkMessages()
		{
			RakNet::Packet* packet = nullptr;
			for (packet = peerInterface->Receive(); packet;
				peerInterface->DeallocatePacket(packet),
				packet = peerInterface->Receive())
			{
				EclipsePacket ecpacket(packet);
				RakNet::MessageID id = ecpacket.Read<unsigned char>();
				if (id == (RakNet::MessageID)TestId::Test)
				{
					int number = ecpacket.Read<int>();

					RakNet::RakString message = ecpacket.Read<RakNet::RakString>();

					std::cout << id << " " << number << " " << message << std::endl;
				}
			}
		}

		void EclipseClient::Reset()
		{
		}

		void EclipseClient::Awake()
		{
			InitializeClientConnection();
		}

		void EclipseClient::Update()
		{
			
			HandleNetworkMessages();
		}
	}
}