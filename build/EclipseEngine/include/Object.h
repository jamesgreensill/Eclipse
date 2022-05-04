#pragma once
#include <typeindex>
#include <unordered_map>

#include "BaseModel.h"
#include "EntityContainer.h"

#include "Component.h"

namespace Eclipse
{
	namespace Components
	{
		class Transform;
	}

	class Object : public Engine::BaseModel
	{
		/**
		 * \brief A mapping for every component using Type as the key.
		 */

	public:
		/// <summary>
		/// Cusotm ECS container following a modified ECS pattern.
		EntityContainer<Components::Component> m_ComponentContainer = EntityContainer<Components::Component>
			(
				[&](Components::Component* component)
				{
					component->object = this;
					component->Created();
				},
				[&](Components::Component* component)
				{
					component->Deleted();
				}
				);

		Components::Transform* transform;

		/*
			Same comments as base. Re-Commenting would be boilerplate.
		*/
		void Update() override;
		void LateUpdate() override;
		void FixedUpdate() override;
		void Draw() override;
		void RetrieveGuiData() override;
		void Dispose() override;
		void Created() override;
		void Deleted() override;
		void Awake() override;
		void Reset() const;

		Object(Object* parent);
		Object();
		~Object() override;
	};
}