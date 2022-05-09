#pragma once
#include <vector>
#include <RakNetTypes.h>
#include <BitStream.h>
#include <RakPeerInterface.h>
#include <PacketPriority.h>
#include <ReliabilityLayer.h>

#include "EclipseEngine/include/EngineMacros.h"

namespace Eclipse
{
	namespace Networking
	{
		class EclipsePacket
		{
		public:
			unsigned char categoryId_ = -1;
			u_short specialId_ = -1;
			bool async = false;
			RakNet::Packet* m_packet_ = nullptr;
			RakNet::BitStream stream_ = {};

			PacketPriority priority = LOW_PRIORITY;
			PacketReliability reliability = RELIABLE;

			template<typename T>
			void Write(T data)
			{
				stream_.Write<T>(data);
			}

			template<typename T>
			void ReadNonAlloc(T& dataBuffer)
			{
				const char* buffer;
				stream_.Read(buffer, sizeof(T));
				dataBuffer = reinterpret_cast<T>(buffer);
			}

			template<typename T>
			T Read()
			{
				T data;
				stream_.Read<T>(data);
				return data;
			}
		
			
			EclipsePacket(RakNet::Packet* packet);
			EclipsePacket(unsigned char categoryId);
			EclipsePacket(unsigned char categoryId, u_short specialId);
			EclipsePacket(const EclipsePacket& other);
		};

		template<>
		inline void EclipsePacket::Write<std::string>(const std::string data)
		{
			RakNet::RakString string = data.c_str();
			Write<RakNet::RakString>(string);
		}

		template<>
		inline std::string EclipsePacket::Read<std::string>()
		{
			const RakNet::RakString string = Read<RakNet::RakString>();
			return string.C_String();
		}
	}
}
