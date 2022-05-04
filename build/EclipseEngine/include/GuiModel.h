#pragma once

// DEPRECATED

namespace Eclipse
{
	namespace Gui
	{
		class ImGuiCall;
	}
	namespace Engine
	{
		class GuiModel
		{
		public:
			virtual ~GuiModel() = default;
		private:
			virtual void RetrieveGuiData(Eclipse::Gui::ImGuiCall* call);
		};
	}
}



