#pragma once
#include <vector>

#include "System.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			class ImGuiCall;
		}
	}

	class Object;
}

namespace Eclipse
{
	namespace Engine
	{
		namespace Gui
		{
			class ImGuiHierarchy :
				public System
			{
			public:
				static ImGuiHierarchy* Instance;

			private:

				std::vector<Object*>* m_Objects = nullptr;
				std::vector<Object*> m_MaskedObjects{};


				void RetrieveHierarchyLayout(Eclipse::Engine::ImGuiTypes::ImGuiCall& call, Eclipse::Object* m_Root, int index);
				void RetrieveGuiData(Eclipse::Engine::ImGuiTypes::ImGuiCall& call) override;
				void MaskObjectHierarchy(Eclipse::Object* object);
				void HierarchyDraw(Eclipse::Object* object, int index);
				void FetchObjects();
				void Awake() override;
				void Gui() override;
				void Created() override;
				void Deleted() override;
			};
		}
	}
}
