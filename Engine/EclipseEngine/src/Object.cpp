#include <pch.h>
#include "Object.h"

//#include <imgui.h>
//
//#include "ImType.h"
#include "Core.h"
#include "Scene.h"
#include "Transform.h"

#include "ObjectFactory.h"

namespace Eclipse
{
	REGTYPE(Object);

	Object::Object(Object* parent) : transform(m_ComponentContainer.AddComponent<Components::Transform>())
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
		FFMCP(Update, m_ComponentContainer.m_Components)
	}

	void Object::LateUpdate()
	{
		FFMCP(LateUpdate, m_ComponentContainer.m_Components)
	}

	void Object::FixedUpdate()
	{
		FFMCP(FixedUpdate, m_ComponentContainer.m_Components)
	}

	void Object::Draw()
	{
		FFMCP(Draw, m_ComponentContainer.m_Components)
	}

	void Object::RetrieveGuiData()
	{

		// DEPRECATED

		//for (const auto& pair : m_Components)
		//{
		//	if (pair.second)
		//	{
		//		call.Push(new Engine::ImGuiTypes::ImType([=]
		//			{
		//				ImGui::Text("%s", pair.second->m_Name.c_str());
		//			}));
		//
		//		pair.second->RetrieveGuiData(call);
		//
		//		call.Push(new Engine::ImGuiTypes::ImType([=]
		//			{
		//				if (ImGui::Button(std::string("Remove " + pair.second->m_Name).c_str()))
		//				{
		//					RemoveComponent(pair.first);
		//				}
		//			}));
		//	}
		//}
	}

	void Object::Dispose()
	{
		FFMCP(Dispose, m_ComponentContainer.m_Components)
	}

	void Object::Created()
	{
		m_Name = "GameObject";
	}

	void Object::Deleted()
	{
	}

	void Object::Awake()
	{
		FFMCP(Awake, m_ComponentContainer.m_Components)
	}

	void Object::Reset() const
	{
		FFMCP(Reset, m_ComponentContainer.m_Components)
	}
}