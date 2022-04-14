#pragma once
#include <vector>
#include <glm/mat4x4.hpp>

#include <EclipseEngine/include/Component.h>

namespace Eclipse
{
	namespace Graphics
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

			friend class Graphics::Renderer;
		public:

			static Camera* current;
			static Camera* main;

			static std::vector<Camera*> cameras;

			glm::mat4 ViewMatrix() const;
			glm::mat4 ProjectionMatrix() const;

			Camera() = default;
		private:
			void Awake() override;
			void Dispose() override;
			void Created() override;
			void Deleted() override;
			void RetrieveGuiData() override;

			void Bind(Graphics::ShaderProgram* shader);
			void Reset() override;

			static auto FindNextCamera()->Camera*;

			float fov{};
			float viewDistance{};
		};
	}
}
