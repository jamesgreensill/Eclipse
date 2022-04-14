#include <iostream>

// Core Engine
#include <EclipseEngine/include/Core.h>
#include <EclipseEngine/include/Application.h>
#include <EclipseEngine/include/ObjectFactory.h>
#include <EclipseEngine/include/WindowModule.h>

// Debug
#include <EclipseDebugging/include/DebugModule.h>

// Graphics
#include <EclipseGraphics/include/GraphicsModule.h>

#include "EclipseEngine/include/Resources.h"
#include "EclipseGraphics/include/MeshRenderer.h"

#include <EclipseGraphics/include/Camera.h>

#include "EclipseGraphics/include/Model.h"

#include <EclipseEngine/include/AssetLoader.h>

int main()
{
	auto mainScene = new Eclipse::Engine::SceneManagement::Scene();

	//auto dragon = new Eclipse::Object();
	//Eclipse::Engine::ObjectFactory::CompositeObject<Eclipse::Components::MeshRenderer>(*dragon);
	//
	//auto meshRenderer = dragon->m_ComponentContainer.GetComponent<Eclipse::Components::MeshRenderer>();
	//
	///*
	// *
	// *	Create event based callbacks.
	// *
	// */
	//Eclipse::Engine::ResourceKey modelKey;
	//Eclipse::Engine::AssetLoader::Load<Eclipse::Graphics::Model>({ "models/cube.obj" }, modelKey);
	//meshRenderer->SetModel(modelKey);
	//
	//auto camera = new Eclipse::Object();
	//Eclipse::Engine::ObjectFactory::CompositeObject<Eclipse::Components::Camera>(*camera);
	//
	//mainScene->AddObject(dragon);
	//mainScene->AddObject(camera);

	//Eclipse::Engine::Application::Create<Eclipse::Debug::DebugModule, Eclipse::Engine::WindowModule, Eclipse::Graphics::GraphicsModule >({});
	

	Eclipse::Engine::Application::Create<Eclipse::Debug::DebugModule>({});
	Eclipse::Engine::Application::Run(mainScene);

	// Run that instance of DemoApplication.

	//SystemManager::CreateSystem<Gui::ImGuiInspector>();
	//SystemManager::CreateSystem<Gui::ImGuiHierarchy>();

	// TODO: Clean This UP!.
	// TODO: Make it so you can run an application with this being empty.
	// TODO: THAT MEANS DEFAULT SCENES.

	/*
	 *
	 *	Create a scene.
	 *
	 */

	 //auto meshRenderer = dragon->GetComponent<MeshRenderer>(true);
	 //meshRenderer->SetModel(
		 //Resources::LoadModel("C:\\Users\\conno\\OneDrive\\Desktop\\models\\dragon.fbx"));

	 //auto t = ObjectFactory::CreateObject<Eclipse::Object>("Test t");
	 //
	 //dragon->transform->AddChild(t->transform);
	 //
	 //auto a = ObjectFactory::CreateObject<Eclipse::Object>("Test a");
	 //t->transform->AddChild(a->transform);
	 //
	 //
	 //
	 //Eclipse::Rendering::Texture* texture = Resources::LoadTexture("C:\\Users\\conno\\OneDrive\\Desktop\\models\\fur.jpg");
	 //
	 //for (auto& mesh : meshRenderer->GetModel()->m_Meshes)
	 //{
	 //	mesh.material->albedoTexture = texture;
	 //}

	Eclipse::External::Test::TestAPI::TestCall_Pointer = []()
	{
		std::cout << "This is a test" << std::endl;
	};

	Eclipse::External::Test::TestAPI::TestCall();
}