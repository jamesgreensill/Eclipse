#pragma once
#include <typeindex>
#include <unordered_map>

#include "BaseModel.h"
#include "Component.h"


namespace Eclipse
{
	namespace Components
	{
		class Transform;
	}


	class Object : public BaseModel
	{
		/**
		 * \brief A mapping for every component using Type as the key.
		 */
		std::unordered_map<std::type_index, Components::Component*> m_Components;

	public:

		Components::Transform* transform;

		void Update() override;
		void LateUpdate() override;
		void FixedUpdate() override;
		void Draw() override;
		void RetrieveGuiData(Eclipse::Engine::ImGuiTypes::ImGuiCall& call) override;
		void Dispose() override;
		void Created() override;
		void Deleted() override;
		void Awake() override;
		void Reset() const;

		void RemoveComponent(std::type_index type);

		Object(Object* parent);
		Object();
		~Object() override;

		/**
		 * \brief Adds an instance of type T if it does not already exist.
		 * \tparam T
		 * \return
		 */
		template<typename T>
		T* AddComponent()
		{
			/*
			 *
			 *	TODO: Assert type is of component.
			 *
			 */
			std::type_index type = typeid(T);
			Components::Component* instance = nullptr;

			if (instance = GetComponent<T>(true))
				return (T*)instance;

			instance = new T();
			instance->object = this;
			instance->Created();

			m_Components.emplace(type, instance);
			return (T*)instance;
		}

		/**
		 * \brief Removes a valid instance of type T.
		 * \tparam T
		 */
		template<typename T>
		void RemoveComponent()
		{
			/*
			 *
			 *	TODO: Assert type is of component.
			 *
			 */
			std::type_index type = typeid(T);
			const auto& it = m_Components.find(type);

			if (it == m_Components.end())
				return;

			it->second->Deleted();
			delete it->second;
			m_Components.erase(it);
		}

		/**
		 * \brief Returns a valid instance of type T.
		 * \tparam T
		 * \param checkInheritedClasses
		 * \return
		 */
		template<typename T>
		T* GetComponent(bool checkInheritedClasses = false)
		{
			/*
			*
			*	TODO: Assert type is of component.
			*
			*/
			std::type_index type = typeid(T);

			const auto& it = m_Components.find(type);
			if (it != m_Components.end())
				return (T*)it->second;
			if (!checkInheritedClasses)
				/*
				 * TODO: Add debug to possibly do an inheritance check.
				 */
				return nullptr;

			for (auto& pair : m_Components)
			{
				T* instance = dynamic_cast<T*>(pair.second);
				if (instance)
					return instance;
			}

			return nullptr;
		}

		/**
		 * \brief Returns all valid instances of type T
		 * \tparam T
		 * \param checkInheritedClasses
		 * \return
		 */
		template<typename T>
		std::vector<T*> GetComponents(bool checkInheritedClasses = false)
		{
			/*
			*
			*	TODO: Assert type is of component.
			*
			*/
			std::vector<T*> components{};

			for (auto& pair : m_Components)
			{
				T* instance = dynamic_cast<T*>(pair.second);
				if (instance)
					components.emplace_back(instance);
			}
			return components;
		}

		/**
		 * \brief Returns the first valid instance of type T
		 * \tparam T
		 * \param checkInheritedClasses
		 * \return
		 */
		template<typename T>
		T* GetComponentInChildren(bool checkInheritedClasses = false)
		{
			/*
			*
			*	TODO: Assert type is of component.
			*
			*/
			return nullptr;
		}

		/**
		 * \brief Returns all valid instances of type T in children and this object.
		 * \tparam T
		 * \param checkInheritedClasses
		 * \return
		 */
		template<typename T>
		std::vector<T*> GetComponentsInChildren(bool checkInheritedClasses = false)
		{
			/*
			 *
			 *	TODO: Assert type is of component.
			 *
			 */
			std::vector<T*> components{};
			GetComponentsInChildren(components, checkInheritedClasses);
			return components;
		}

		template<typename T>
		void GetComponentsInChildren(std::vector<T*>& output, bool checkInheritedClasses = false)
		{
			/*
			*
			*	TODO: Assert type is of component.
			*
			*/
		}

		/**
		 * \brief Returns true if the Object has a component of type T
		 * \tparam T
		 * \param checkInheritedClasses
		 * \return
		 */
		template<typename T>
		bool HasComponent(bool checkInheritedClasses)
		{
			/*
			*
			*	TODO: Assert type is of component.
			*
			*/
			std::type_index type = typeid(T);

			const auto& it = m_Components.find(type);
			if (it != m_Components.end())
				return true;
			if (!checkInheritedClasses)
				/*
				 * TODO: Add debug to possibly do an inheritance check.
				 */
				return false;

			for (auto& pair : m_Components)
			{
				T* instance = dynamic_cast<T*>(pair.second);
				if (instance)
					return true;
			}

			return false;
		}
	};


	
}