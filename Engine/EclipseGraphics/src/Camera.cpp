#include "Camera.h"
#include <glm/ext/matrix_transform.hpp>

#include "ShaderProgram.h"

#include <EclipseEngine/include/Scene.h>
#include <EclipseEngine/include/SceneManager.h>
#include <EclipseEngine/include/Core.h>
#include <EclipseEngine/include/Transform.h>
#include <EclipseEngine/include/Object.h>

//#include "Scene.h"
//#include "SceneManager.h"
//
//#include "Eclipse.h"
//
//#include "ImGuiHelper.h"
//
//#include "ImFloat.h"
//#include "ImString.h"
//#include "Transform.h"

namespace Eclipse
{
	namespace Components
	{
		Camera* Camera::current = nullptr;
		Camera* Camera::main = nullptr;
		std::vector<Camera*> Camera::cameras = {};

		glm::mat4 Camera::ViewMatrix() const
		{
			const auto cameraPosition = object->transform->GetGlobalPosition();
			const auto cameraForward = object->transform->GetForward();
			const auto cameraUp = object->transform->GetUp();

			return glm::lookAt(cameraPosition, cameraPosition + cameraForward, cameraUp);
		}

		glm::mat4 Camera::ProjectionMatrix() const
		{
			return glm::perspective(glm::radians(fov), static_cast<float>(Core::Window::GetScreenWidth()) / static_cast<float>(Core::Window::GetScreenHeight()), 0.1f, viewDistance);
		}

		void Camera::Awake()
		{
			cameras.emplace_back(this);
		}

		void Camera::Dispose()
		{
			const auto& it = std::find(cameras.begin(), cameras.end(), this);
			if (it != cameras.end())
			{
				cameras.erase(it);
			}
		}

		void Camera::Created()
		{
			Camera::Reset();
		}

		void Camera::Deleted()
		{
		}

		void Camera::Bind(Graphics::ShaderProgram* shader)
		{
			// View Matrix.
			shader->BindUniform(
				uniCameraViewMatrix, ViewMatrix());

			// Projection Matrix.
			shader->BindUniform(
				uniCameraProjectionMatrix, ProjectionMatrix());

			// Camera Position
			shader->BindUniform(
				uniCameraPosition, object->transform->GetGlobalPosition());
		}

		void Camera::RetrieveGuiData()
		{
			//call.Push(new Engine::ImGuiTypes::ImFloat("FOV", &fov));
			//call.Push(new Engine::ImGuiTypes::ImFloat("View Distance", &viewDistance));
		}

		void Camera::Reset()
		{
			m_Name = "Camera";
			viewDistance = 10000.0f;
			fov = 45.0f;
		}

		auto Camera::FindNextCamera() -> Camera*
		{
			// loop through all cameras to find an enabled one.
			for (const auto camera : cameras)
			{
				if (camera->enabled)
				{
					current = camera;
					return current;
				}
			}
			return nullptr;
		}
	}
}