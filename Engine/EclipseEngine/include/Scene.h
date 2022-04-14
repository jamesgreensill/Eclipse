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
			class Scene : public BaseModel
			{

			private:
				bool hasAwoken = false;
				bool hasStarted = false;
			public:
				auto AddObject(Object* object)-> void;
				auto RemoveObject(Object* object) -> void;
				auto RemoveObject(unsigned int index) -> void;
				auto GetObject(unsigned int index) const -> Object*;
				auto GetObjects()->std::vector<Object*>*;


				auto AddCamera(Components::Camera* camera)-> void;
				auto RemoveCamera(const Components::Camera* camera)-> void;
				
				auto AddLight(Components::Light* light)-> void;
				auto RemoveLight(const Components::Light* light)-> void;

				auto GetLights() ->std::vector<Components::Light*>&;

				auto GetCameras() ->std::vector<Components::Camera*>&;

				auto FindNextCamera() const -> Components::Camera*;


				
				friend class SceneManager;
			private:
				void Awake() override;
				void Start() override;
				void Update() override;
				void LateUpdate() override;
				void FixedUpdate() override;
				void Draw() override;
				void Dispose() override;
				void Created() override;
				void Deleted() override;

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
