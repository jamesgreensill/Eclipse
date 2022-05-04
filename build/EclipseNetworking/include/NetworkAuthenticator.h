#pragma once
#include <EclipseEngine/include/Component.h>

namespace Eclipse
{
	namespace Networking
	{
		class NetworkAuthenticator :
			public Components::Component
		{
		protected:
			void Reset() override;
		};
	}
}
