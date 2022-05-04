#pragma once
#include "NetworkManager.h"

namespace Eclipse
{
	namespace Networking
	{
		class NetworkClient :
			public NetworkManager
		{
		protected:
			void Reset() override;
		public:
			void StartProcess() override;
			void StartProcess(const std::string& uri);
			void StopProcess() override;
		protected:
			int32_t GetConnectionCount() override;
		private:
			RakNet::SystemAddress hostServer = {};
		};
	}
}
