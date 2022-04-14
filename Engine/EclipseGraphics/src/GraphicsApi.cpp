#include "GraphicsApi.h"

#include <EclipseEngine/include/Core.h>

namespace Eclipse
{
	namespace Graphics
	{
		GraphicsApi::~GraphicsApi()
			= default;

		void GraphicsApi::LoadInterface()
		{
			External::Debug::DebugAPI::Debug("Graphics API Interface Loaded.");
		}
	}
}