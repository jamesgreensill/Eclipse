#pragma once

#include <functional>
#include <unordered_map>
#include <raknet/MessageIdentifiers.h>
#include <EclipseEngine/include/EclipseEvent.h>
#include "EclipsePacket.h"

namespace Eclipse
{
	namespace Networking
	{
		class NetworkHandler
		{
		public:
			void InitializeHandler();
			void Receive(const EclipsePacket& packet);

			Engine::EclipseEvent<const EclipsePacket&>* GetReceivedHandle(unsigned int);
			Engine::EclipseEvent<const EclipsePacket&>* GetSentHandle(unsigned int);

			// TODO: AddNewIDHandle
			//void AddNewIdHandle(unsigned int id);
			//void AddNewIdHandle(unsigned int id, const std::string& name);

			unsigned int GenDynID();
			unsigned int GenDynID(const std::string& hashName);
			std::unordered_map<unsigned int, Engine::EclipseEvent<const EclipsePacket&>*> OnPacketReceived = {};
			std::unordered_map<unsigned int, Engine::EclipseEvent<const EclipsePacket&>*> OnPacketSent = {};
		private:
			int _dynIdCount = 0;
			unsigned int _idCount = ID_USER_PACKET_ENUM;

			std::unordered_map<std::string, unsigned int> namedDynKeys = {};

			friend class INetworkHandle;
		};
	}
}
