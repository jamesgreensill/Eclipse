#pragma once
#include <EclipseEngine/include/Component.h>
#include <EclipseChat/include/NetworkChatInterface.h>


namespace Eclipse
{
	namespace Application
	{
		class ChatSender : public Components::Component
		{
		private:
			Chat::NetworkChatInterface* netInterface = nullptr;
			void _fetchCaches();

			void ThreadedCin(std::atomic<bool>& run);

			std::atomic<bool> Run;

		protected:
			void Update() override;
			void Reset() override;
			void Start() override;
			void Dispose() override;
		};
	}
}
