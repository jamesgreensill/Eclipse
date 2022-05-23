#include "EclipseTimer.h"
namespace Eclipse
{
	namespace Engine
	{
		void EclipseTimer::SetDelay(float msTime)
		{
			timeInMs = msTime;
		}

		void EclipseTimer::Step()
		{
			elapsedTime += EclipseTime::DeltaTime;
		}

		bool EclipseTimer::Ready()
		{
			if (elapsedTime >= timeInMs)
			{
				elapsedTime -= timeInMs;
				return true;
			}
			return false;
		}

		EclipseTimer::EclipseTimer(float msTime)
		{
			timeInMs = msTime;
		}
	}
}