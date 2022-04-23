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

			/// <summary>
			///	Reference to the current render camera.
			/// </summary>
			static Camera* current;

			/// <summary>
			///	Reference to the main camera.
			/// </summary>
			static Camera* main;

			/// <summary>
			///	Array of all cameras
			/// </summary>
			static std::vector<Camera*> cameras;
			
			/// <summary>
			///	Get the view matrix of the camera.
			/// </summary>
			glm::mat4 ViewMatrix() const;
			/// <summary>
			///	Get the projection matrix of the camera.
			/// </summary>
			glm::mat4 ProjectionMatrix() const;

			Camera() = default;
		private:
			/*
				Base class overrides.
			*/
			void Awake() override;
			void Dispose() override;
			void Created() override;
			void Deleted() override;
			void RetrieveGuiData() override;

			/// <summary>
			///	Bind the camera to the specified shader.
			/// </summary>
			void Bind(Graphics::ShaderProgram* shader);
			void Reset() override;


			/// <summary>
			///	Find the next avaliable camera.
			/// </summary>
			static auto FindNextCamera()->Camera*;

			float fov{};
			float viewDistance{};
		};
	}
}
