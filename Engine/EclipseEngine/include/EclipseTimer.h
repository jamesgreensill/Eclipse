#pragma once

#include "EclipseTime.h"

namespace Eclipse
{
    namespace Engine
    {
        class EclipseTimer
        {
        public:

            void SetDelay(float msTime);
            void Step();
            bool Ready();
            EclipseTimer(float msTime);
        private:
            float elapsedTime = 0;
            float timeInMs = 0;
        };
    }
}
