#include "TimeModule.h"
#include "TimeSystem.h"

namespace Eclipse
{
	namespace Engine
	{
		class TimeSystem;

		void TimeModule::Created()
		{
		}

		void TimeModule::Deleted()
		{
		}

		void TimeModule::Boot()
		{
			m_SystemsContainer.AddComponent<TimeSystem>();
		}
	}
}