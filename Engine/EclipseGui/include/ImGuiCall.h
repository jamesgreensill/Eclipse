#pragma once
#include <queue>

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			class ImType;

			class ImGuiCall
			{
			public:

				void Push(ImType* element);
				void Pop();

				std::queue<ImType*> buffer{};
			private:
			};
		}
	}
}
