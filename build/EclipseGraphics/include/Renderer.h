#pragma once

#include <EclipseEngine/include/System.h>

#include <queue>
#include <glm/glm.hpp>

namespace Eclipse
{
	namespace Components
	{
		class Transform;
	}
	namespace Rendering
	{
#define uniRendererCameraPosition	"cameraPosition"
#define uniRendererAmbientColor 	"rendererAmbientColor"
#define uniRendererModelMatrix		"modelMatrix"
#define uniRendererLightCount		"lightCount"

		class Mesh;
		class Renderer :
			public Engine::System
		{
		public:

			struct DrawCall
			{
				Mesh* mesh;
				Components::Transform* transform;
			};

			auto QueueCall(DrawCall) -> void;
			static Renderer* Instance;

		private:
			auto Draw() -> void override;
			auto Created() -> void override;
			auto Deleted() -> void override;

			std::queue<DrawCall> DrawCalls{};

			glm::vec4 rendererAmbientColor = { 1,1,1,1 };
		};
	}
}
