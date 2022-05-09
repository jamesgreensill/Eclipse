#include <pch.h>
#include <EclipseDebugging/include/Core.h>

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
					Debug::Error("Element not defined - ImGuiBuffer.");
					
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