#include <pch.h>
#include <EclipseEngine/include/Core.h>

#include "ImType.h"
#include "ImGuiRenderer.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace Gui
		{
			ImGuiRenderer* ImGuiRenderer::Instance = nullptr;

			void ImGuiRenderer::Draw()
			{
				while (!renderQueue.empty())
				{
					auto renderCall = renderQueue.front();

					while (!renderCall.buffer.empty())
					{
						try
						{
							const auto guiCall = renderCall.buffer.front();
							guiCall->Draw();
							renderCall.buffer.pop();
							delete guiCall;
						}
						catch (...)
						{
						//	DEBUG(ImGuiFail)
						}
					}

					renderQueue.pop();
				}
			}

			auto ImGuiRenderer::Created() -> void
			{
				if (!Instance)
					Instance = this;
			}

			auto ImGuiRenderer::Deleted() -> void
			{
				delete Instance;
			}

			void ImGuiRenderer::QueueCall(const ImGuiTypes::ImGuiCall& call)
			{
				renderQueue.push(call);
			}
		}
	}
}