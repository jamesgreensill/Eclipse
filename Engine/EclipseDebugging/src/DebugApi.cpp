#include "DebugApi.h"

#include <EclipseEngine/include/Core.h>
#include "Core.h"
namespace Eclipse
{
	namespace Debug
	{
		void DebugApi::LoadInterface()
		{
			External::Debug::DebugAPI::Debug_Pointer = Debug;
			External::Debug::DebugAPI::Error_Pointer = Error;
			External::Debug::DebugAPI::Log_Pointer = Log;
		}
	}
}