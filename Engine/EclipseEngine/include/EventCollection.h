#pragma once
#include <unordered_map>

#include "EclipseEvent.h"

namespace Eclipse
{
	namespace Engine
	{
		template <typename TKey, typename ...TArgs>
		class EventCollection
		{
			typedef EclipseEvent<TArgs...> GenericEvent;
		public:
			std::unordered_map<TKey, GenericEvent*> eventCollection = {};

			bool AddEvent(TKey key, GenericEvent* event);
			GenericEvent* GetEvent(TKey key);

			// operator overloads
			GenericEvent* operator[](TKey key);
		private:

			GenericEvent* _getEvent(TKey key);
			bool _addEvent(TKey key, GenericEvent* event);
		};

		template <typename TKey, typename ... TArgs>
		bool EventCollection<TKey, TArgs...>::AddEvent(TKey key, GenericEvent* event)
		{
			return _addEvent(key, event);
		}

		template <typename TKey, typename ... TArgs>
		typename EventCollection<TKey, TArgs...>::GenericEvent* EventCollection<TKey, TArgs...>::GetEvent(TKey key)
		{
			return _getEvent(key);
		}

		template <typename TKey, typename ... TArgs>
		typename EventCollection<TKey, TArgs...>::GenericEvent* EventCollection<TKey, TArgs...>::operator[](TKey key)
		{
			return _getEvent(key);
		}

		template <typename TKey, typename ... TArgs>
		typename EventCollection<TKey, TArgs...>::GenericEvent* EventCollection<TKey, TArgs...>::_getEvent(TKey key)
		{
			if (!eventCollection[key])
				_addEvent(key, new EclipseEvent<TArgs...>());
			return eventCollection[key];
		}

		template <typename TKey, typename ... TArgs>
		bool EventCollection<TKey, TArgs...>::_addEvent(TKey key, GenericEvent* event)
		{
			return eventCollection.try_emplace(key, event).second;
		}
	}
}