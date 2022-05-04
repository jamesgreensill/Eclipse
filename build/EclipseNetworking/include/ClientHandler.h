#pragma once
#include <EclipseEngine/include/EngineMacros.h>

#include "NetworkHandler.h"

namespace Eclipse
{
	namespace Networking
	{
		class EclipseClient;

		class ClientHandler :
			public NetworkHandler
		{
		public:
			GET(Client, return client_;);
			SET_POINTER(Client, EclipseClient, client_ = value;);
		private:
			EclipseClient* client_ = nullptr;
		};
	}
}
