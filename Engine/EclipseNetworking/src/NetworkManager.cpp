#include "NetworkManager.h"
namespace Eclipse
{
	namespace Networking
	{
		void NetworkManager::onIncomingConnection(EclipsePacket& packet){}

		void NetworkManager::onIncomingDisconnection(EclipsePacket& packet){}

		void NetworkManager::onConnectionLost(EclipsePacket& packet){}

		void NetworkManager::Update()
		{
			/*
			 *	Loop through all incoming packets and correctly handle them.
			 */
			for (auto packet = networkInterfaceInstance->Receive(); packet;
				networkInterfaceInstance->DeallocatePacket(packet),
				packet = networkInterfaceInstance->Receive())
			{
				handler.Receive(EclipsePacket(packet));
			}
		}

		void NetworkManager::InitializeDefaultHandles()
		{
			// initialize override handles.
			*handler.GetReceivedHandle(ID_NEW_INCOMING_CONNECTION) += [this](auto packet) {this->_onIncomingConnection(packet); };
			*handler.GetReceivedHandle(ID_DISCONNECTION_NOTIFICATION) += [this](auto packet) {this->_onIncomingDisconnection(packet); };
			*handler.GetReceivedHandle(ID_CONNECTION_LOST) += [this](auto packet) {this->_onConnectionLost(packet); };
		}

		void NetworkManager::_onIncomingConnection(EclipsePacket& packet)
		{
			onIncomingConnection(packet);
			OnClientJoin.Invoke(packet);
		}

		void NetworkManager::_onIncomingDisconnection(EclipsePacket& packet)
		{
			onIncomingDisconnection(packet);
			OnClientLeave.Invoke(packet);
		}

		void NetworkManager::_onConnectionLost(EclipsePacket& packet)
		{
			onConnectionLost(packet);
			OnClientLeave.Invoke(packet);
		}
	}
}