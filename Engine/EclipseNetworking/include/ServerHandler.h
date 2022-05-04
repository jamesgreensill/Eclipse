#pragma once
#include <EclipseEngine/include/EngineMacros.h>
#include "NetworkHandler.h"

namespace Eclipse
{
	namespace Networking
	{
		class EclipseServer;

		class ServerHandler :
			public NetworkHandler
		{
		public:
			GET(Server, return server_;);
			SET_POINTER(Server, EclipseServer, server_ = value;);
		private:
			EclipseServer* server_ = nullptr;
		};
	}
}
