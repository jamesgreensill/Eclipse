#include "INetworkHandle.h"

#include "NetworkHandler.h"

namespace Eclipse
{
	namespace Networking
	{
		void INetworkHandle::InitializeHandle(unsigned id, NetworkHandler* handler)
		{
			*handler->OnPacketReceived[id] += [=](auto packet) {this->HandlePacket(packet); };
		}
	}
}