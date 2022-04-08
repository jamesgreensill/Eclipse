#pragma once
#include <glm/mat4x4.hpp>

#include "Component.h"

namespace Eclipse
{
	namespace Rendering
	{
		class ShaderProgram;
		class Renderer;
	}
	namespace Components
	{
		class Camera :
			public Component
		{
#define uniCameraViewMatrix "viewMatrix"
#define uniCameraProjectionMatrix "projectionMatrix"
#define uniCameraPosition "cameraPosition"

			friend class Rendering::Renderer;
		public:

			static Camera* current;
			static Camera* main;

			glm::mat4 ViewMatrix() const;
			glm::mat4 ProjectionMatrix() const;

			Camera() = default;
		private:
			void Created() override;
			void Deleted() override;
			void RetrieveGuiData(Eclipse::Engine::ImGuiTypes::ImGuiCall& call) override;

			void Bind(Rendering::ShaderProgram* shader);
			void Reset() override;

			static auto FindNextCamera()->Camera*;

			float fov{};
			float viewDistance{};
		};
	}
}
