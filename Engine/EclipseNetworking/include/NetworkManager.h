#pragma once
#include <EclipseEngine/include/Component.h>
#include <EclipseEngine/include/EclipseEvent.h>
#include <raknet/RakPeerInterface.h>

#include "NetworkHandler.h"

namespace Eclipse
{
	namespace Networking
	{
		enum class NetworkManagerType
		{
			Client,
			Host,
			Offline,
			Server
		};

		class NetworkManager :
			public Components::Component
		{
		public:
			// Default Types
			bool isNetworkActive;
			std::string networkAddress = "localhost";
			unsigned short networkPort = 0;

			// Eclipse Types
			NetworkManagerType networkManagerType;
			NetworkHandler handler;

			// RakNet Types
			RakNet::RakPeerInterface* networkInterfaceInstance = nullptr;

			// Eclipse Events
			Engine::EclipseEvent<EclipsePacket&> OnClientJoin = {};
			Engine::EclipseEvent<EclipsePacket&> OnClientLeave = {};
			Engine::EclipseEvent<EclipsePacket&> OnStart = {};
			Engine::EclipseEvent<EclipsePacket&> OnStop = {};

			virtual void StartProcess() = 0;
			virtual void StopProcess() = 0;

			// overrides
			void Update() final;

			// returns the amount of connected clients to the server.
		protected:
			virtual int32_t GetConnectionCount() = 0;
			virtual void onIncomingConnection(EclipsePacket& packet);
			virtual void onIncomingDisconnection(EclipsePacket& packet);
			virtual void onConnectionLost(EclipsePacket& packet);
			void InitializeDefaultHandles();

		private:
			void _onIncomingConnection(EclipsePacket& packet);
			void _onIncomingDisconnection(EclipsePacket& packet);
			void _onConnectionLost(EclipsePacket& packet);
		};
	}
}
