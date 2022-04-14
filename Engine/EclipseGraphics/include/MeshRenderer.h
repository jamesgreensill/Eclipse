#pragma once
#include <vector>
#include <EclipseEngine/include/Component.h>
#include <EclipseEngine/include/typedefs.h>

//#include "Mesh.h"

namespace Eclipse
{
	namespace Graphics { class Model; struct Vertex; }
	namespace Components
	{
		class MeshRenderer : public Component
		{
			Engine::ResourceKey m_ModelKey;
			Graphics::Model* modelReference = nullptr;

		public:
			void Awake() override;

			void Draw() override;

			void Created() override;

			void Reset() override;

			auto SetModel(Engine::ResourceKey& key) -> void;

			Graphics::Model* GetModel() const;
		};
	}
}
