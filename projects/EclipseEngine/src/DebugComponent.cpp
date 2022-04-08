#include <pch.h>
#include "DebugComponent.h"
#include "Eclipse.h"
#include "Object.h"

namespace Eclipse
{
	namespace Components
	{
		void DebugComponent::Created()
		{
			name = "Debug Component";
		}

		void DebugComponent::Draw()
		{
			Eclipse::Core::Debug::Debug((std::string("This is a debug from") + object->name).c_str());
		}

		void DebugComponent::Reset()
		{
		}
	}
}