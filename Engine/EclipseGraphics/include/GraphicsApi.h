#pragma once
#include <EclipseEngine/include/API.h>

namespace Eclipse
{
	namespace Graphics
	{
		class GraphicsApi final :
			public Engine::API
		{
		public:
			~GraphicsApi() override;
			void LoadInterface() override;
		};
	}
}



