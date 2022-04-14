#pragma once

#include <EclipseEngine/include/EngineModule.h>

namespace Eclipse
{
	namespace Graphics
	{
		class GraphicsModule :
			public Engine::EngineModule
		{
		public:
			void EngineInit() override;
			void Created() override;
			void Deleted() override;
			void Boot() override;
		};
	}
}
