#include "TimeSystem.h"

#include <iostream>

#include "EclipseTime.h"

namespace Eclipse
{
	namespace Engine
	{
		// Not Used.
		void TimeSystem::Created() {}

		// Not Used.
		void TimeSystem::Deleted() {}

		// Initializes Time.
		void TimeSystem::Start()
		{
			EclipseTime::Init();
		}

		// Updates Time at the end of the frame.
		void TimeSystem::FrameEnd()
		{
			EclipseTime::Tick();
			std::cout << Eclipse::Engine::EclipseTime::FPS << std::endl;
		}
	}
}