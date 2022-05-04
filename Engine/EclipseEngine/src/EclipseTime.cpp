#include "EclipseTime.h"

#include <chrono>

namespace Eclipse
{
	namespace Engine
	{
		long long EclipseTime::CurrentTime = 0;
		long long EclipseTime::LastTime = 0;
		int EclipseTime::FPS = 0;
		int EclipseTime::Frames = 0;
		float EclipseTime::Timer = 0;
		float EclipseTime::DeltaTime = 0.0005f;

		void EclipseTime::Init()
		{
			LastTime = std::chrono::duration_cast<std::chrono::milliseconds>(
				std::chrono::high_resolution_clock::now().time_since_epoch()).count();
		}

		void EclipseTime::Tick()
		{
			CurrentTime = std::chrono::duration_cast<std::chrono::milliseconds>(
				std::chrono::high_resolution_clock::now().time_since_epoch()).count();

			DeltaTime = static_cast<float>(CurrentTime - LastTime) / 1000.0f;

			Timer += DeltaTime;

			if (Timer >= 1)
			{
				FPS = Frames;
				Frames = 0;
				Timer -= 1;
			}
			Frames++;

			LastTime = CurrentTime;
		}
	}
}