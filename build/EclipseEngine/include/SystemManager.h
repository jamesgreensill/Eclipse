#pragma once
#include <typeindex>
#include <unordered_map>

#include "System.h"

namespace Eclipse
{
	namespace Engine
	{
		class Application;
		class System;

		// DEPRECATED
		class SystemManager
		{
			friend class Engine;
			friend class System;
		public:

			template <typename T>
			static T* CreateSystem()
			{
				/*
				 *
				 *	TODO: Assert type is of System.
				 *
				 */
				std::type_index type = typeid(T);

				System* instance;
				instance = GetSystem<T>(true);
				if (instance)
					return static_cast<T*>(instance);

				instance = new T();
				instance->Created();

				systems.emplace(type, instance);
				return static_cast<T*>(instance);
			}

			template <typename T>
			static T* GetSystem(bool checkInheritedClasses = false)
			{
				/*
				 *
				 *	TODO: Assert type is of System.
				 *
				 */
				std::type_index type = typeid(T);

				const auto& it = systems.find(type);
				if (it != systems.end())
					return static_cast<T*>(it->second);
				if (!checkInheritedClasses)
					/*
					 * TODO: Add debug to possibly do an inheritance check
					 */
					return nullptr;

				for (auto& pair : systems)
				{
					T* instance = dynamic_cast<T*>(pair.second);
					if (instance)
						return instance;
				}

				return nullptr;
			}

			template<typename T>
			static void RemoveSystem()
			{
				/*
				 *
				 *	TODO: Assert type is of System.
				 *
				 */
				const std::type_index type = typeid(T);
				const auto& it = systems.find(type);

				if (it == systems.end())
					return;

				it->second->Deleted();
				delete it->second;
				systems.erase(it);
			}

		private:
			static void Awake();
			static void Start();
			static void Update();
			static void LateUpdate();
			static void FixedUpdate();
			static void Draw();
			static void Gui();
			static void Dispose();

			static std::unordered_map<std::type_index, System*> systems;
		};
	}
}
