#include <pch.h>
#include "DebugComponent.h"
#include "Core.h"
#include "Object.h"

namespace Eclipse
{
	namespace Components
	{

		// Deprecated.
		
		void DebugComponent::Created()
		{
			m_Name = "Debug Component";
		}

		void DebugComponent::Draw()
		{
			External::Debug::DebugAPI::Debug((std::string("This is a debug from") + object->m_Name).c_str());
		}

		void DebugComponent::Reset()
		{
		}
	}
}