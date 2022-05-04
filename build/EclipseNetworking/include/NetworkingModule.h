#pragma once
#include <EclipseEngine/include/EngineModule.h>

namespace Eclipse
{
	namespace Networking
	{
		class NetworkingModule :
			public Engine::EngineModule
		{
		public:
			void Created() override;
			void Deleted() override;
			void Boot() override;
		};
	}
}
