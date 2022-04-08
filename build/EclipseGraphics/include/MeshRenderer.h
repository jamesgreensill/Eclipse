#pragma once
#include <vector>
#include <EclipseEngine/include/Component.h>

//#include "Mesh.h"

namespace Eclipse
{
	namespace Rendering { class Model; struct Vertex; }
	namespace Components
	{
		class MeshRenderer : public Component
		{
			Rendering::Model* m_Model = nullptr;

		public:
			void Draw() override;

			void Created() override;

			void Reset() override;

			auto SetModel(Rendering::Model* model) -> void;

			Rendering::Model* GetModel() const;
		};
	}
}
