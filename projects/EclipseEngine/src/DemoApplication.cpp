#include <pch.h>
#include "DemoApplication.h"

#include "MeshRenderer.h"
#include "Resources.h"
#include "SystemManager.h"
#include "ImGuiInspector.h"
#include "ObjectFactory.h"
#include "ImGuiHierarchy.h"
#include "Model.h"
#include "Texture.h"
#include "Transform.h"

using namespace Eclipse::Components;
using namespace Eclipse::Engine;

void DemoApplication::OnAwake()
{
	SystemManager::CreateSystem<Gui::ImGuiInspector>();
	SystemManager::CreateSystem<Gui::ImGuiHierarchy>();

	// TODO: Clean This UP!.
	// TODO: Make it so you can run an application with this being empty.
	// TODO: THAT MEANS DEFAULT SCENES.

	/*
	 *
	 *	Create a scene.
	 *
	 */
	auto dragon = ObjectFactory::CreateObject<Eclipse::Object>("Dragon");
	ObjectFactory::CompositeObject<MeshRenderer>(*dragon);

	auto meshRenderer = dragon->GetComponent<MeshRenderer>(true);
	meshRenderer->SetModel(
		Resources::LoadModel("C:\\Users\\conno\\OneDrive\\Desktop\\models\\dragon.fbx"));

	auto t = ObjectFactory::CreateObject<Eclipse::Object>("Test t");

	dragon->transform->AddChild(t->transform);

	auto a = ObjectFactory::CreateObject<Eclipse::Object>("Test a");
	t->transform->AddChild(a->transform);

	

	Eclipse::Rendering::Texture* texture = Resources::LoadTexture("C:\\Users\\conno\\OneDrive\\Desktop\\models\\fur.jpg");

	for (auto& mesh : meshRenderer->GetModel()->m_Meshes)
	{
		mesh.material->albedoTexture = texture;
	}

}

void DemoApplication::OnStart()
{

}

void DemoApplication::OnUpdate()
{

}

void DemoApplication::OnLateUpdate()
{
}

void DemoApplication::OnDraw()
{

}

void DemoApplication::OnGui()
{

}

void DemoApplication::OnDispose()
{
}