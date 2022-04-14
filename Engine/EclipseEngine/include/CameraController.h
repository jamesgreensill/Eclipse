#pragma once
#include "Component.h"

namespace Eclipse
{
	namespace Components
	{
		class Camera;
		class CameraController :
			public Component
		{
			Camera* camera = nullptr;

			void Awake() override;
			void Update() override;
		};
	}
}
