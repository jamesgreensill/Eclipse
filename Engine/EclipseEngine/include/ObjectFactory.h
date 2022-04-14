#pragma once

#include <typeindex>
#include <unordered_map>

#include "Object.h"
#include "Scene.h"
#include "SceneManager.h"

namespace Eclipse
{
	class Object;

	namespace Engine
	{
#define REGTYPE(_name) \
	_name *create_ ## _name() { return new _name; } \
	static bool _name ## _creator_registered = \
						Eclipse::Engine::ObjectFactory::RegisterCreator(typeid(## _name), create_ ## _name)

		struct CreatorEntry
		{
			CreatorEntry* Next;
			std::type_index index;
			Object* (*constructor)();
		};

		class ObjectFactory
		{
		public:
			static int RegisterCreator(std::type_index type, Object* (*constructor)());

			template <typename TObject>
			static auto CreateObject(const std::string& name) -> TObject*
			{
				CreatorEntry* tmp(creatorList);
				const std::type_index index = typeid(TObject);
				while (tmp)
				{
					if (index == tmp->index)
					{
						auto object = tmp->constructor();
						if (object)
						{
							SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(object);
							object->m_Name = name;
							return object;
						}
					}
					tmp = tmp->Next;
				}
				return nullptr;
			}

			template <typename TObject>
			static auto CreateObject() -> TObject* {
				return CreateObject<TObject>("GameObject");
			}

			template<typename...>
			struct TypeList {};

			template<typename T, typename ... TArgs>
			static void CompositeCall(TypeList<T, TArgs...>, Object& object)
			{
				object.m_ComponentContainer.AddComponent<T>();
				CompositeCall(TypeList<TArgs...>(), object);
			}

			static void CompositeCall(TypeList<>, Object& object) { }

			template<typename...Args>
			static void CompositeObject(Object& object) {
				CompositeCall(TypeList<Args...>(), object);
			}

		private:
			static CreatorEntry* creatorList;

			static auto Delete() -> void
			{
				while (creatorList)
				{
					const CreatorEntry* tmp(creatorList);
					creatorList = creatorList->Next;
					delete tmp;
				}
			}
		};
	}
}
