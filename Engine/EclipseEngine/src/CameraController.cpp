#include <pch.h>
//#include <EclipseGraphics/include/Camera.h>

#include "CameraController.h"
#include "Object.h"
#include "Core.h"
#include "Transform.h"

namespace Eclipse
{
	namespace Components
	{
		// https://stackoverflow.com/questions/19738805/opengl-camera-control-with-arrow-keys
		// https://gamedev.net/forums/topic/674804-get-forward-vector-of-transformcomponent/5272185/
		// https://learnopengl.com/Getting-started/Camera
		// http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix/

		void CameraController::Awake()
		{
			//camera = object->GetComponent<Camera>();
		}

		void CameraController::Update()
		{
			if (Core::Input::IsKeyDown(GLFW_KEY_A))
			{
				object->transform->Translate(object->transform->GetLeft());
			}
			if (Core::Input::IsKeyDown(GLFW_KEY_D))
			{
				object->transform->Translate(object->transform->GetRight());
			}
			if (Core::Input::IsKeyDown(GLFW_KEY_S))
			{
				object->transform->Translate(object->transform->GetBack());
			}
			if (Core::Input::IsKeyDown(GLFW_KEY_W))
			{
				object->transform->Translate(object->transform->GetForward());
			}

			glm::vec2 moveDelta = Core::Input::GetMouseDelta() * 0.1f;

			Eclipse::Core::Window::ShowCursor(!Eclipse::Core::Input::IsMouseDown(0));
			if (Core::Input::IsMouseDown(0))
			{
				//camera->object->transform->Rotate(glm::vec3(glm::radians(-moveDelta.y), 0, 0));
				//camera->object->transform->Rotate(glm::vec3(0, glm::radians(moveDelta.x), 0));
			}
		}
	}
}