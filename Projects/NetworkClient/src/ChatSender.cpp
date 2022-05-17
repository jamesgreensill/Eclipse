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

		void ChatSender::ThreadedCin()
		{
			while(true)
			{
				netInterface->Send(Engine::Console::ReadLine());
			}
		}

		void ChatSender::Awake()
		{
			_fetchCaches();
			inputThread = std::thread([this] {this->ThreadedCin(); });
		}

		void ChatSender::Update()
		{}

		void ChatSender::Reset()
		{
		}

		void ChatSender::Start()
		{
		}

		void ChatSender::Dispose()
		{
		}
	}
}