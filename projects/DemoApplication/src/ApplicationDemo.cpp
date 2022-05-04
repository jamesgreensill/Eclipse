#include "ApplicationDemo.h"

// Core Engine
#include <EclipseEngine/include/Core.h>
#include <EclipseEngine/include/ObjectFactory.h>

// Debug

// Graphics

#include <EclipseGraphics/include/MeshRenderer.h>

#include <EclipseGraphics/include/Camera.h>
#include <EclipseGraphics/include/Light.h>
#include <EclipseGraphics/include/Model.h>

#include "EclipseEngine/include/AssetLoader.h"

#include <EclipseEngine/include/Transform.h>

#include <random>

#include "ObjectRotator.h"

float GetRandom(float min, float max)
{
	static std::default_random_engine e;
	static std::uniform_real_distribution<> dis(0, 1); // range 0 - 1
	return dis(e);
}

void ApplicationDemo::OnEngineInit()
{
	// Load Default Resources.
	Eclipse::Engine::ResourceManager::SetDefault(Eclipse::Engine::ResourceManager::Load<Eclipse::Graphics::ShaderProgram>({
		R"(.\data\shaders\default.vs)","",
		R"(.\data\shaders\default.fs)"
		}));
	Eclipse::Engine::ResourceManager::SetDefault(Eclipse::Engine::ResourceManager::Load<Eclipse::Graphics::Texture>({
		R"(.\data\textures\default.jpg)"
		}));
	Eclipse::Engine::ResourceManager::SetDefault(Eclipse::Engine::ResourceManager::Load<Eclipse::Graphics::Model>({
		R"(.\data\models\cat.fbx)"
		}));

	// Create objects
	auto camera = new Eclipse::Object();

	// Composite Objects
	Eclipse::Engine::ObjectFactory::CompositeObject<Eclipse::Components::Camera>(*camera);


	for (int i = 0; i < 2500; i++)
	{
		auto dragon = new Eclipse::Object();
		Eclipse::Engine::ObjectFactory::CompositeObject<Eclipse::Components::MeshRenderer, ObjectRotator>(*dragon);
		auto meshRenderer = dragon->m_ComponentContainer.GetComponent<Eclipse::Components::MeshRenderer>();
		meshRenderer->SetModel(Eclipse::Engine::ResourceManager::GetDefault<Eclipse::Graphics::Model>());
		dragon->transform->SetTranslation({ (rand() % 2000) - 1000, (rand() % 2000) - 1000, (rand() % 1000) + 1500 });

		auto rotator = dragon->m_ComponentContainer.GetComponent<ObjectRotator>();
		rotator->SetSpeed(0.001);
		rotator->SetRotation(glm::vec3(GetRandom(0, 1)));

		Eclipse::Engine::SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(dragon);
	}

	auto light1 = new Eclipse::Object();
	Eclipse::Engine::ObjectFactory::CompositeObject<Eclipse::Components::Light, ObjectRotator>(*light1);

	auto lightRotator1 = light1->m_ComponentContainer.GetComponent<ObjectRotator>();
	lightRotator1->SetSpeed(0.005);
	lightRotator1->SetRotation({ 0,0,1 });

	auto lightRef1 = light1->m_ComponentContainer.GetComponent<Eclipse::Components::Light>();
	lightRef1->SetAmbientColor({ 0.1,0,0, 0.1 });
	lightRef1->SetSpecularColor({ 1,0,0,0.1 });
	lightRef1->SetDiffuseColor({ 1,0,0,0.1 });
	lightRef1->SetIntensity(32);
	Eclipse::Engine::SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(light1);

	auto light2 = new Eclipse::Object();
	Eclipse::Engine::ObjectFactory::CompositeObject<Eclipse::Components::Light, ObjectRotator>(*light2);

	auto lightRotator2 = light2->m_ComponentContainer.GetComponent<ObjectRotator>();
	lightRotator2->SetSpeed(0.05);
	lightRotator2->SetRotation({ 0,1,0 });

	auto lightRef2 = light2->m_ComponentContainer.GetComponent<Eclipse::Components::Light>();
	lightRef2->SetAmbientColor({ 0,0,1,10 });
	lightRef2->SetSpecularColor({ 0,0,1,1 });
	lightRef2->SetDiffuseColor({ 0,0,0,1 });
	lightRef2->SetIntensity(32);
	Eclipse::Engine::SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(light2);

	auto light3 = new Eclipse::Object();
	Eclipse::Engine::ObjectFactory::CompositeObject<Eclipse::Components::Light, ObjectRotator>(*light3);

	auto lightRotator3 = light3->m_ComponentContainer.GetComponent<ObjectRotator>();
	lightRotator3->SetSpeed(0.1f);
	lightRotator3->SetRotation({ 1,0,0 });

	auto lightRef3 = light3->m_ComponentContainer.GetComponent<Eclipse::Components::Light>();
	lightRef3->SetAmbientColor({ 0,1,0,10 });
	lightRef3->SetSpecularColor({ 0,1,0,1 });
	lightRef3->SetDiffuseColor({ 0,0,1,1 });
	lightRef3->SetIntensity(32);
	Eclipse::Engine::SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(light3);

	// Set Model

	camera->transform->Translate({ 0,0,-10 });

	Eclipse::Engine::SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(camera);
}
