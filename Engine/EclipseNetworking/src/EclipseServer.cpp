#include "EclipseServer.h"

#include <raknet/BitStream.h>
#include <raknet/MessageIdentifiers.h>
#include <iostream>
#include <EclipseEngine/include/EclipseTime.h>


//#include <EclipseEngine/include/Time.h>

namespace Eclipse
{
	namespace Networking
	{
		enum class TestId
		{
			Test = ID_USER_PACKET_ENUM + 1,
		};

		void EclipseServer::Send(EclipsePacket* packet, char orderingChannel, const RakNet::SystemAddress& systemIdentifier, bool broadcast, uint32_t forceReceiptNumber)
		{
			peerInterface->Send(&packet->stream_, packet->priority, packet->reliability, orderingChannel, systemIdentifier, broadcast, forceReceiptNumber);
		}

		void EclipseServer::HandleNetworkMessages()
		{
			for (auto packet = peerInterface->Receive(); packet;
				peerInterface->DeallocatePacket(packet),
				packet = peerInterface->Receive())
			{
				m_handler_.Receive(EclipsePacket(packet));
			}
		}

		void EclipseServer::InitializeServer()
		{
			m_handler_.InitializeHandler();
			m_handler_.SetServer(this);

			*m_handler_.GetReceivedHandle(ID_NEW_INCOMING_CONNECTION) += [=](EclipsePacket packet)
			{
				std::cout << "A connection from " << packet.m_packet_->systemAddress.ToString(true) << std::endl;
				connectedClients.emplace_back(packet.m_packet_->systemAddress);
			};
			*m_handler_.GetReceivedHandle(ID_DISCONNECTION_NOTIFICATION) += [](auto packet) {std::cout << "A client has disconnected.\n"; };
			*m_handler_.GetReceivedHandle(ID_CONNECTION_LOST) += [](auto packet) {std::cout << "A client lost the connection.\n"; };

			peerInterface = RakNet::RakPeerInterface::GetInstance();
			RakNet::SocketDescriptor sd(PORT, 0);
			peerInterface->Startup(MAX_CONNECTIONS, &sd, 1);
			peerInterface->SetMaximumIncomingConnections(static_cast<unsigned short>(MAX_CONNECTIONS));
		}

		void EclipseServer::Awake()
		{
			InitializeServer();
		}

		void EclipseServer::Update()
		{
			std::cout << Engine::EclipseTime::FPS << std::endl;
			//std::cout << Eclipse::Engine::Timee::FPS << std::endl;
			EclipsePacket packet((unsigned char)TestId::Test);
			packet.Write<int>(10);

			RakNet::RakString message = "Packet from server.";

			packet.Write<RakNet::RakString>(message);

			//RakNet::BitStream bs;
			//bs.Write<RakNet::MessageID>((unsigned char)TestId::Test);
			//bs.Write<int>(10);

			//std::this_thread::sleep_for(std::chrono::seconds(1));

			for (const auto address : connectedClients)
			{


				std::cout << "packet sent" << std::endl;
				Send(&packet, 0, address, false, 0);
			}

			HandleNetworkMessages();
		}

		void EclipseServer::Reset()
		{
		}
	}
}