#pragma once
namespace Eclipse
{
	namespace Networking
	{
		class NetworkHandler;
		class EclipsePacket;

		class INetworkHandle
		{
		public:
			virtual ~INetworkHandle() = default;
			void InitializeHandle(unsigned int id, NetworkHandler* handler);
		protected:
			virtual void HandlePacket(const Eclipse::Networking::EclipsePacket& packet) = 0;
		};
	}
}
