#include "DebugApi.h"

#include <EclipseEngine/include/Core.h>
#include "Core.h"
namespace Eclipse
{
	namespace Debug
	{
		void DebugApi::LoadInterface()
		{
			// Links Debug Callback to the main engine.
			External::Debug::DebugAPI::Debug_Pointer = Debug;
			// Links Error Callback to the main engine.
			External::Debug::DebugAPI::Error_Pointer = Error;
			// Links Log Callback to the main engine.
			External::Debug::DebugAPI::Log_Pointer = Log;
		}
	}
}