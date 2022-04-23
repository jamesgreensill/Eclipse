#pragma once

namespace Eclipse
{
	namespace Engine
	{
		class API
		{
		public:
			virtual ~API() = default;
			// Abstract function for API's to implement functionality.
			virtual void LoadInterface() = 0;
		};
	}
}
