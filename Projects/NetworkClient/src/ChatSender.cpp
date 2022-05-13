#include "ChatSender.h"

#include <EclipseEngine/include/Object.h>
#include <EclipseEngine/include/Console.h>

#include <thread>
#include <atomic>


namespace Eclipse
{
	namespace Application
	{
		void ChatSender::_fetchCaches()
		{
			netInterface = object->m_ComponentContainer.GetComponent<Chat::NetworkChatInterface>();
		}

		void ChatSender::ThreadedCin(std::atomic<bool>& run)
		{
			
		}

		void ChatSender::Update()
		{
		}

		void ChatSender::Reset()
		{
		}

		void ChatSender::Start()
		{
			_fetchCaches();
		}

		void ChatSender::Dispose()
		{
			
		}
	}
}