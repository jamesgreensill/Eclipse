#pragma once

#include <forward_list>
#include <unordered_map>
#include <functional>
#include <future>
#include <mutex>


namespace Eclipse
{
	namespace Engine
	{
		template<typename... TArgs>
		class EclipseEvent
		{
		public:
			typedef std::function<void(TArgs...)> EventAction;
			typedef EventAction* EventHandle;

			/// <summary>
			/// Adds a named listener to this event with the signature of <TArgs...>
			/// </summary>
			void AddListener(std::string&& name, EventAction callback)
			{
				std::lock_guard<std::mutex> lock(m_eventLock);
				namedEventHandles[name] = AddCallback(callback);
			}

			/// <summary>
			/// Adds a listener to this event with the signature of <TArgs...>
			/// </summary>
			EventHandle AddListener(EventAction callback)
			{
				return AddCallback(callback);
			}

			/// <summary>
			/// Removes a named listener.
			/// </summary>
			bool RemoveListener(const std::string& name)
			{
				std::lock_guard<std::mutex> lock(m_eventLock);

				auto it = namedEventHandles.find(name);
				if (it == namedEventHandles.end())
				{
					return false;
				}
				EventHandle handle = it->second;
				auto pos = std::find_if(EventListeners.begin(), EventListeners.end(), [&](EventHandle handleRef) { return handleRef == handle; });
				if (pos != EventListeners.end())
				{
					EventListeners.erase(pos);
					namedEventHandles.erase(it);
					return true;
				}
				return false;
			}


			/// <summary>
			/// Removed a listener with an EventHandle.
			/// </summary>
			bool RemoveListener(const EventHandle& handle)
			{
				std::lock_guard<std::mutex> lock(m_eventLock);

				auto pos = std::find_if(EventListeners.begin(), EventListeners.end(), [handle](EventHandle handleRef)
					{
						return handleRef == handle;
					});
				if (pos != EventListeners.end())
				{
					EventListeners.erase(pos);
					return true;
				}
				return false;
			}


			/// <summary>
			/// Invokes all Event Listeners.
			/// </summary>
			void Invoke(TArgs ... args)
			{
				for (EventHandle handle : EventListeners)
				{
					(*handle)(args...);
				}
			}


			/// <summary>
			/// invokes all Event Listeners asynchronously.
			/// </summary>
			std::future<void> InvokeAsync(TArgs... args)
			{
				return std::async(std::launch::async, [this](TArgs... asyncParams)
					{Invoke(asyncParams...); }, args...);
			}
			
			/*
			
				OPERATOR OVERLOADS.
			
			*/
			void operator()(TArgs ... args)
			{
				Invoke(args...);
			}

			EventHandle operator+=(const EventAction& callback)
			{
				return AddListener(callback);
			}

			bool operator-=(const EventHandle& handle)
			{
				return RemoveListener(handle);
			}

			bool operator-=(const std::string& named)
			{
				return RemoveListener(named);
			}
		private:
			std::vector<EventHandle> EventListeners = std::vector<EventHandle>();
			std::unordered_map<std::string, EventHandle> namedEventHandles = std::unordered_map<std::string, EventHandle>();
			mutable std::mutex m_eventLock;

			EventHandle AddCallback(EventAction& callback)
			{
				std::lock_guard<std::mutex> lock(m_eventLock);
				auto eventType = new EventAction(callback);
				EventListeners.emplace_back(eventType);
				return eventType;
			}
		};
	}
}
