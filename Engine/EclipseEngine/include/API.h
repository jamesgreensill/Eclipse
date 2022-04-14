#pragma once

namespace Eclipse
{
	namespace Engine
	{
		class API
		{
		public:
			virtual ~API() = default;
			virtual void LoadInterface() = 0;
		};
	}
}
