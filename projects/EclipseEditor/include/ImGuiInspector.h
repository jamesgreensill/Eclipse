#pragma once
#include <vector>

#include "System.h"

namespace Eclipse
{
}

namespace Eclipse
{
	class Object;

	namespace Components
	{
		class MeshRenderer;
	}

	namespace Engine
	{
		namespace Gui
		{
			class ImGuiInspector :
				public System
			{
			public:
				static ImGuiInspector* Instance;
				Object* selectedObject = nullptr;
				static bool inspectorActive;
				static bool addComponentActive;
				void RetrieveGuiData(ImGuiTypes::ImGuiCall& call) override;
			private:
				void Gui() override;
				void Created() override;
				void Deleted() override;
			};
		}
	}
}
