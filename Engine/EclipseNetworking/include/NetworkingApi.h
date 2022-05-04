#pragma once
#include <EclipseEngine/include/API.h>

namespace Eclipse
{
	namespace Networking
	{
		class NetworkingApi :
			public Engine::API
		{
		public:
			void LoadInterface() override;
		};
	}
}
