#include <EclipseEngine/include/Core.h>

#include "NetworkingBus.h"
namespace Eclipse
{
	namespace Networking
	{
		NetworkingBus* NetworkingBus::Instance = nullptr;

		void NetworkingBus::Created()
		{
			if (!Instance)
				Instance = this;
		}
		void NetworkingBus::Deleted()
		{
			delete Instance;
		}

		void NetworkingBus::Update()
		{
			SendBufferedPackets();
		}

		void NetworkingBus::SendPacketImmediate(NetworkCall& call)
		{
			if (!call.sender)
			{
				External::Debug::DebugAPI::Debug("Could not immediately send network call.");
				return;
			}
			_sendPacket(&call.packet, call.sender, call.orderingChannel, call.address, call.broadcast, call.forceReceiptNumber);
		}

		void NetworkingBus::SendPacket(const NetworkCall& call)
		{
			if (!call.sender)
			{
				External::Debug::DebugAPI::Debug("Could not buffer network call.");
				return;
			}
			networkBuffer.push(call);
		}

		void NetworkingBus::SendBufferedPackets()
		{
			int sentPackets = 0;

			while (!networkBuffer.empty())
			{
				// get call at the front of the queue
				NetworkCall& call = networkBuffer.front();

				// check if the calls sender still exists.
				if (!call.sender)
				{
					External::Debug::DebugAPI::Debug(("Sender on iteration " + std::to_string(sentPackets) + "no longer exists.").c_str());
					networkBuffer.pop();
					continue;
				}

				// send the packet
				_sendPacket(&call.packet, call.sender, call.orderingChannel, call.address, call.broadcast, call.forceReceiptNumber);

				// remove call from network buffer.
				networkBuffer.pop();
				sentPackets++;
			}

			packetSentDelta = packetsSentLastFrame - sentPackets;
			packetsSentLastFrame = sentPackets;
		}

		void NetworkingBus::_sendPacket(EclipsePacket* packet, RakNet::RakPeerInterface* sender, char orderingChannel,
			const RakNet::SystemAddress& systemIdentifier, bool broadcast, uint32_t forceReceiptNumber)
		{
			if (sender)
			{
				sender->Send(&packet->stream_, packet->priority, packet->reliability, orderingChannel, systemIdentifier, broadcast, forceReceiptNumber);
			}
		}
	}
}