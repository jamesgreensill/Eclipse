#include <pch.h>
#include "Camera.h"
#include <glm/ext/matrix_transform.hpp>

#include "ShaderProgram.h"

#include "Scene.h"
#include "SceneManager.h"

#include "Eclipse.h"

#include "ImGuiHelper.h"

#include "ImFloat.h"
#include "ImString.h"
#include "Transform.h"

namespace Eclipse
{
	namespace Components
	{
		Camera* Camera::current = nullptr;
		Camera* Camera::main = nullptr;

		glm::mat4 Camera::ViewMatrix() const
		{
			const auto cameraPosition = object->transform->GetGlobalPosition();
			const auto cameraForward = object->transform->GetForward();
			const auto cameraUp = object->transform->GetUp();

			return lookAt(cameraPosition, cameraPosition + cameraForward, cameraUp);
		}

		glm::mat4 Camera::ProjectionMatrix() const
		{
			return glm::perspective(glm::radians(fov), static_cast<float>(Core::Window::GetScreenWidth()) / static_cast<float>(Core::Window::GetScreenHeight()), 0.1f, viewDistance);
		}

		void Camera::Created()
		{
			Camera::Reset();

			Engine::SceneManagement::SceneManager::Instance->GetActiveScene()->AddCamera(this);
		}

		void Camera::Deleted()
		{
			Engine::SceneManagement::SceneManager::Instance->GetActiveScene()->RemoveCamera(this);
		}

		void Camera::Bind(Rendering::ShaderProgram* shader)
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

		void Camera::RetrieveGuiData(Engine::ImGuiTypes::ImGuiCall& call)
		{
			call.Push(new Engine::ImGuiTypes::ImFloat("FOV", &fov));
			call.Push(new Engine::ImGuiTypes::ImFloat("View Distance", &viewDistance));
		}

		void Camera::Reset()
		{
			name = "Camera";
			viewDistance = 1000.0f;
			fov = 45.0f;
		}

		auto Camera::FindNextCamera() -> Camera*
		{
			return Engine::SceneManagement::SceneManager::Instance->GetActiveScene()->FindNextCamera();
		}
	}
}
