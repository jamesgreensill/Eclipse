#pragma once
#include "Component.h"

namespace Eclipse
{
	namespace Components
	{
		class Camera;

		
		/// <summary>
		/// Camera Controller Component for Demo Application.
		/// </summary>
		class CameraController :
			public Component
		{
			Camera* camera = nullptr;

			void Awake() override;
			void Update() override;
		};
	}
}
