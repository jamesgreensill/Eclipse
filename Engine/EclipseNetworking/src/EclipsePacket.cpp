#include "EclipsePacket.h"

namespace Eclipse
{
	namespace Networking
	{
		EclipsePacket::EclipsePacket(RakNet::Packet* packet)
		{
			m_packet_ = packet;
			categoryId_ = packet->data[0];
			//const RakNet::BitStream bs(packet->data, packet->length, true);

			for (int i = 0; i < packet->length; i++)
			{
				stream_ << packet->data[i];
			}
		}

		EclipsePacket::EclipsePacket(unsigned char categoryId)
		{
			categoryId_ = categoryId;
			Write<unsigned char>(categoryId_);
			//Write<bool>(false);
		}

		EclipsePacket::EclipsePacket(unsigned char categoryId, u_short specialId)
		{
			categoryId_ = categoryId;
			specialId_ = specialId;
			Write<unsigned char>(categoryId_);
			//Write<bool>(true);
			//Write<u_short>(specialId_);
		}

		EclipsePacket::EclipsePacket(const EclipsePacket& other)
		{
			categoryId_ = other.categoryId_;
			specialId_ = other.specialId_;
			m_packet_ = other.m_packet_;
			stream_.SetData(other.stream_.GetData());
		}
	}
}