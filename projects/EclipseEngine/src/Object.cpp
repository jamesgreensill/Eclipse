#include <pch.h>
#include "Object.h"

#include <imgui.h>

#include "ImType.h"
#include "Scene.h"
#include "Transform.h"

#include "ObjectFactory.h"

namespace Eclipse
{
	Object* create_Object() { return new Object; } static bool Object_creator_registered = Eclipse::Engine::ObjectFactory::RegisterCreator(typeid(Object), create_Object);

	Object::Object(Object* parent) : transform(AddComponent<Components::Transform>())
	{
		Object::Created();
	}

	Object::~Object()
	{
		Object::Deleted();
	}

	Object::Object() : Object(nullptr) {}

	void Object::Update()
	{
		for (auto& pair : m_Components)
		{
			if (pair.second)
			{
				pair.second->Update();
			}
		}
	}

	void Object::LateUpdate()
	{
		for (auto& pair : m_Components)
		{
			if (pair.second)
			{
				pair.second->LateUpdate();
			}
		}
	}

	void Object::FixedUpdate()
	{
		for (auto& pair : m_Components)
		{
			if (pair.second)
			{
				pair.second->FixedUpdate();
			}
		}
	}

	void Object::Draw()
	{
		for (auto& pair : m_Components)
		{
			if (pair.second)
			{
				pair.second->Draw();
			}
		}
	}

	void Object::RetrieveGuiData(Eclipse::Engine::ImGuiTypes::ImGuiCall& call)
	{
		for (const auto& pair : m_Components)
		{
			if (pair.second)
			{
				call.Push(new Engine::ImGuiTypes::ImType([=]
					{
						ImGui::Text("%s", pair.second->name.c_str());
					}));

				pair.second->RetrieveGuiData(call);

				call.Push(new Engine::ImGuiTypes::ImType([=]
					{
						if (ImGui::Button(std::string("Remove " + pair.second->name).c_str()))
						{
							RemoveComponent(pair.first);
						}
					}));
			}
		}
	}

	void Object::Dispose()
	{
		for (auto& pair : m_Components)
		{
			if (pair.second)
			{
				pair.second->Dispose();
			}
		}
	}

	void Object::Created()
	{
		name = "GameObject";
	}

	void Object::Deleted()
	{
	}

	void Object::Awake()
	{
		for (auto& pair : m_Components)
		{
			if (pair.second)
			{
				pair.second->Awake();
			}
		}
	}

	void Object::Reset() const
	{
		for (auto& pair : m_Components)
		{
			if (pair.second)
			{
				pair.second->Reset();
			}
		}
	}

	void Object::RemoveComponent(std::type_index type)
	{
		/*
			 *
			 *	TODO: Assert type is of component.
			 *
			 */
		const auto& it = m_Components.find(type);

		if (it == m_Components.end())
			return;

		it->second->Deleted();
		delete it->second;
		m_Components.erase(it);
	}
}