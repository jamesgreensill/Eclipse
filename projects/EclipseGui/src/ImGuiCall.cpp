#include <pch.h>
#include <EclipseEngine/include/Eclipse.h>

#include "ImGuiCall.h"
#include "ImType.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace ImGuiTypes
		{
			void ImGuiCall::Push(ImType* element)
			{
				if (!element)
				{
					Core::Debug::Error("Element not defined - ImGuiBuffer.");
					return;
				}

				buffer.push(element);
			}

			void ImGuiCall::Pop()
			{
				buffer.pop();
			}
		}
	}
}