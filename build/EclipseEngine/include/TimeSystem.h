#pragma once
#include "System.h"

namespace Eclipse
{
	namespace Engine
	{
		class TimeSystem :
			public System
		{
		public:
			void Created() override;
			void Deleted() override;
			void Start() override;
			void FrameEnd() override;
		};
	}
}
