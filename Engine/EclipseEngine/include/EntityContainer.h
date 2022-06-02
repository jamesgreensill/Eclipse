#pragma once
#include <typeindex>
#include <unordered_map>
#include <functional>

template <class TBaseClass>
struct EntityContainer
{
    std::unordered_map<std::type_index, TBaseClass*> m_Components{};
    std::function<void(TBaseClass*)> m_CreationCallback = nullptr;
    std::function<void(TBaseClass*)> m_DeletionCallback = nullptr;

    /**
     * \brief EntityContainer constructor that takes 2 callbacks.
     * \param creationCallback This action will be called upon TBaseClass creation.
     * \param deletionCallback This action will be called upon TBaseClass deletion.
     */
    EntityContainer(std::function<void(TBaseClass*)> creationCallback, std::function<void(TBaseClass*)> deletionCallback) :
        m_CreationCallback(std::move(creationCallback)), m_DeletionCallback(std::move(deletionCallback)) {}
    /**
     * \brief Adds an instance of type T if it does not already exist.
     * \tparam T
     * \return Created Instance.
     */
    template<typename T>
    T* AddComponent()
    {
        static_assert(std::is_base_of<TBaseClass, T>::value, "T does not derive from TBaseClass.");

        std::type_index type = typeid(T);
        TBaseClass* instance = nullptr;

        if ((instance = GetComponent<T>()))
            return (T*)instance;

        instance = new T();
        m_CreationCallback((TBaseClass*)instance);

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
        static_assert(std::is_base_of<TBaseClass, T>::value, "T does not derive from TBaseClass.");

        std::type_index type = typeid(T);
        const auto& it = m_Components.find(type);

        if (it == m_Components.end())
            return;

        m_DeletionCallback(it->second);

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
    T* GetComponent()
    {
        static_assert(std::is_base_of<TBaseClass, T>::value, "T does not derive from TBaseClass.");

        std::type_index type = typeid(T);

        const auto& it = m_Components.find(type);
        if (it != m_Components.end())
            return (T*)it->second;
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
    std::vector<T*> GetComponents()
    {
        static_assert(std::is_base_of<TBaseClass, T>::value, "T does not derive from TBaseClass.");

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
    T* GetComponentInChildren()
    {
        static_assert(std::is_base_of<TBaseClass, T>::value, "T does not derive from TBaseClass.");
        static_assert(true, "NOT IMPLEMENTED");
        return nullptr;
    }

    /**
     * \brief Returns all valid instances of type T in children and this object.
     * \tparam T
     * \param checkInheritedClasses
     * \return
     */
    template<typename T>
    std::vector<T*> GetComponentsInChildren()
    {
        static_assert(std::is_base_of<TBaseClass, T>::value, "T does not derive from TBaseClass.");

        std::vector<T*> components{};
        GetComponentsInChildren(components);
        return components;
    }

    template<typename T>
    void GetComponentsInChildren(std::vector<T*>& output)
    {
        static_assert(std::is_base_of<TBaseClass, T>::value, "T does not derive from TBaseClass.");
    }

    /**
     * \brief Returns true if the Object has a component of type T
     * \tparam T
     * \param checkInheritedClasses
     * \return
     */
    template<typename T>
    bool HasComponent()
    {
        static_assert(std::is_base_of<TBaseClass, T>::value, "T does not derive from TBaseClass.");

        std::type_index type = typeid(T);

        const auto& it = m_Components.find(type);
        if (it != m_Components.end())
            return true;

        for (auto& pair : m_Components)
        {
            T* instance = dynamic_cast<T*>(pair.second);
            if (instance)
                return true;
        }

        return false;
    }

    inline void RemoveComponent(std::type_index type)
    {
        static_assert(std::is_base_of<TBaseClass, T>::value, "T does not derive from TBaseClass.");

        const auto& it = m_Components.find(type);

        if (it == m_Components.end())
            return;

        m_DeletionCallback(it->second);

        delete it->second;
        m_Components.erase(it);
    }
};
