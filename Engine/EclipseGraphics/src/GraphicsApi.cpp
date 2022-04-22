#include "GraphicsApi.h"

#include <EclipseEngine/include/Core.h>
#include "Core.h"

namespace Eclipse
{
	namespace Graphics
	{
		GraphicsApi::~GraphicsApi()
			= default;

		void GraphicsApi::LoadInterface()
		{
			External::Graphics::GraphicsAPI::Viewport_Pointer = Viewport;
			External::Debug::DebugAPI::Debug("Graphics API Interface Loaded.");
		}
	}
}