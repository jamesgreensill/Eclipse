#pragma once

#include <queue>
#include <vector>

#include "BaseModel.h"

namespace Eclipse
{
	class Object;
}

namespace Eclipse
{
	namespace Components
	{
		class Light;
		class Camera;
	}

	namespace Engine
	{
		namespace SceneManagement
		{

			/*
				TODO: Refactor Scene.h & Scene.cpp
			*/
			class Scene : public BaseModel
			{

			private:
				bool hasAwoken = false;
				bool hasStarted = false;
			public:

				/// <summary>
				/// Used to add an object to the scene.
				/// </summary>
				auto AddObject(Object* object)-> void;
				/// <summary>
				/// Used to remove an object from the scene.
				/// </summary>
				auto RemoveObject(Object* object) -> void;

				/// <summary>
				/// Used to remove an object from the scene with an index.
				/// </summary>
				auto RemoveObject(unsigned int index) -> void;

				/// <summary>
				/// Used to get an object from an index.
				/// </summary>
				auto GetObject(unsigned int index) const -> Object*;
				/// <summary>
				/// Used to get all objects.
				/// </summary>
				auto GetObjects()->std::vector<Object*>*;

				
				/// <summary>
				/// Deprecated
				/// </summary>
				auto AddCamera(Components::Camera* camera)-> void;
				/// <summary>
				/// Deprecated
				/// </summary>
				auto RemoveCamera(const Components::Camera* camera)-> void;
				/// <summary>
				/// Deprecated
				/// </summary>
				auto AddLight(Components::Light* light)-> void;
				/// <summary>
				/// Deprecated
				/// </summary>
				auto RemoveLight(const Components::Light* light)-> void;
				/// <summary>
				/// Deprecated
				/// </summary>
				auto GetLights() ->std::vector<Components::Light*>&;
				/// <summary>
				/// Deprecated
				/// </summary>
				auto GetCameras() ->std::vector<Components::Camera*>&;
				/// <summary>
				/// Deprecated
				/// </summary>
				auto FindNextCamera() const -> Components::Camera*;


				
				friend class SceneManager;
			private:
				/*
					Same comments as base, re-commenting would be boilerplate.
				*/
				void Awake() override;
				void Start() override;
				void Update() override;
				void LateUpdate() override;
				void FixedUpdate() override;
				void Draw() override;
				void Dispose() override;
				void Created() override;
				void Deleted() override;


				/// <summary>
				/// Deprecated?
				/// </summary>
				void ManageQueues();

				std::queue<Object*> removalObjects{};
				std::queue<Object*> additionalObjects{};
				std::vector<Object*> objects{};

				std::vector<Components::Light*> lights{};
				std::vector<Components::Camera*> cameras{};
			};
		}
	}
}
