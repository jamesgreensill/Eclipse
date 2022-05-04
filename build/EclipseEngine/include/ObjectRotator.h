#pragma once
#include <glm/vec3.hpp>

#include "Component.h"

// DEPRECATED

namespace Eclipse
{
	namespace Components
	{
		class ObjectRotator :
			public Component
		{
		public:
			bool running = false;
			float speed = 0.2f;
			glm::vec3 angles;
		private:
			void Update() override;
			void RetrieveGuiData() override;
			void Reset() override;
		};
	}
}
