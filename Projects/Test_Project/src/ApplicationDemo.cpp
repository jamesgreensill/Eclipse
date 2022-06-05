#include "ApplicationDemo.h"

// EclipseEngine
#include <EclipseEngine/include/ResourceManager.h>
#include <EclipseEngine/include/SceneManager.h>

// EclipseGraphics
#include <EclipseGraphics/include/ShaderProgram.h>
#include <EclipseGraphics/include/Texture.h>
#include <EclipseGraphics/include/Model.h>
#include <EclipseGraphics/include/Camera.h>
#include <EclipseGraphics/include/MeshRenderer.h>
#include <EclipseGraphics/include/Light.h>

#include "EclipseEngine/include/Object.h"
#include "EclipseEngine/include/Transform.h"

void ApplicationDemo::OnEngineInit()
{
    // Load and Set default shader.
    Eclipse::Engine::ResourceManager::SetDefault(Eclipse::Engine::ResourceManager::Load<Eclipse::Graphics::ShaderProgram>({ R"(./data/shaders/default.vs)", "", R"(./data/shaders/default.fs)"}));
    // Load and Set default texture.
    Eclipse::Engine::ResourceManager::SetDefault(Eclipse::Engine::ResourceManager::Load<Eclipse::Graphics::Texture>({ R"(./data/textures/default.jpg)" }));
    auto cat_model_key = Eclipse::Engine::ResourceManager::Load<Eclipse::Graphics::Model>({ R"(./data/models/cat.fbx)" });

    // create camera object
    Eclipse::Object* camera_object = new Eclipse::Object();
    camera_object->m_ComponentContainer.AddComponent<Eclipse::Components::Camera>();

    Eclipse::Object* cat_object = new Eclipse::Object();
    Eclipse::Components::MeshRenderer* cat_mesh_renderer = cat_object->m_ComponentContainer.AddComponent<Eclipse::Components::MeshRenderer>();
    // set model
    cat_mesh_renderer->SetModel(cat_model_key);
    cat_object->transform->SetTranslation({ 0,0,1500 });

    // create light object
    Eclipse::Object* light_object = new Eclipse::Object();
    // add light component
    Eclipse::Components::Light* light_object_light = light_object->m_ComponentContainer.AddComponent<Eclipse::Components::Light>();
    light_object_light->SetAmbientColor({ 0.1,0,0, 0.1 });
    light_object_light->SetSpecularColor({ 1,0,0,0.1 });
    light_object_light->SetDiffuseColor({ 1,0,0,0.1 });
    light_object_light->SetIntensity(32);

    Eclipse::Engine::SceneManagement::Scene* scene = Eclipse::Engine::SceneManagement::SceneManager::Instance->GetActiveScene();
    scene->AddObject(camera_object);
    scene->AddObject(cat_object);
    scene->AddObject(light_object);
}