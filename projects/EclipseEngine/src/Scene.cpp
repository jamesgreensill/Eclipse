#include <pch.h>
#include <EclipseGraphics/include/Camera.h>

#include "Scene.h"
#include "Eclipse.h"
#include "Object.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace SceneManagement
		{
			void Scene::Awake()
			{
				for (const auto& object : objects)
				{
					object->Awake();
				}
			}

			void Scene::Start()
			{
				for (const auto& object : objects)
				{
					object->Start();
				}
			}

			void Scene::AddObject(Object* object)
			{
				if (object)
				{
					additionalObjects.push(object);
				}
				else NULL_REF()
			}

			void Scene::RemoveObject(Object* object)
			{
				if (object)
				{
					const auto& it = std::find(objects.begin(), objects.end(), object);

					Object* obj = *it;
					if (obj)
					{
						removalObjects.push(obj);
					}
				}
				else NULL_REF()
			}

			void Scene::RemoveObject(unsigned int index)
			{
				if (static_cast<unsigned long long>(index) >= objects.size())
				{
					INDEX_OUT_OF_BOUNDS()
						return;
				}

				Object* objectToDelete = objects.at(index);
				if (objectToDelete)
				{
					removalObjects.push(objectToDelete);
				}
				else NULL_REF()
			}

			Object* Scene::GetObject(unsigned int index) const
			{
				if (static_cast<unsigned long long>(index) >= objects.size())
				{
					INDEX_OUT_OF_BOUNDS()
						return nullptr;
				}

				return objects.at(index);
			}

			auto Scene::GetObjects() -> std::vector<Object*>*
			{
				return &objects;
			}

			void Scene::AddCamera(Components::Camera* camera)
			{
				if (camera)
				{
					cameras.emplace_back(camera);
				}
				else NULL_REF()
			}

			void Scene::RemoveCamera(const Components::Camera* camera)
			{
				const auto& it = std::find(cameras.begin(), cameras.end(), camera);
				if (it != cameras.end())
				{
					cameras.erase(it);
				}
				else NULL_REF()
			}

			auto Scene::AddLight(Components::Light* light) -> void
			{
				if (light)
				{
					lights.emplace_back(light);
				}
				else NULL_REF()
			}

			auto Scene::RemoveLight(const Components::Light* light) -> void
			{
				const auto& it = std::find(lights.begin(), lights.end(), light);
				if (it != lights.end())
				{
					lights.erase(it);
				}
				else NULL_REF()
			}

			auto Scene::GetLights() -> std::vector<Components::Light*>&
			{
				return lights;
			}

			std::vector<Components::Camera*>& Scene::GetCameras()
			{
				return cameras;
			}

			auto Scene::FindNextCamera() const -> Components::Camera*
			{
				for (const auto camera : cameras)
				{
					if (camera->enabled)
					{
						Components::Camera::current = camera;
						return Components::Camera::current;
					}
				}
				return nullptr;
			}

			void Scene::ManageQueues()
			{
				while (!removalObjects.empty())
				{
					const auto& it = std::find(objects.begin(), objects.end(), removalObjects.front());

					if (it == objects.end())
					{
						removalObjects.pop();
						return;
					}

					auto obj = *it;
					objects.erase(it);
					removalObjects.pop();
					delete obj;
					obj = nullptr;
					//	const auto& it = std::find(objects.begin(), objects.end(), removalObjects.front());
					//	if (it != objects.end())
					//	{
					//		const Object* object = *it;
					//		objects.erase(it);
					//		delete object;
					//	}
						//else NULL_REF()
				}

				while (!additionalObjects.empty())
				{
					Object* sceneToAdd = additionalObjects.front();
					if (sceneToAdd)
					{
						objects.emplace_back(sceneToAdd);

						additionalObjects.pop();
					}
					else NULL_REF()
				}
			}

			void Scene::Update()
			{
				for (const auto& object : objects)
				{
					object->Update();
				}

				ManageQueues();
			}

			void Scene::LateUpdate()
			{
				for (const auto& object : objects)
				{
					object->LateUpdate();
				}
			}

			void Scene::FixedUpdate()
			{
				for (const auto& object : objects)
				{
					object->FixedUpdate();
				}
			}

			void Scene::Draw()
			{
				for (const auto& object : objects)
				{
					object->Draw();
				}
			}

			void Scene::Dispose()
			{
				for (const auto& object : objects)
				{
					object->Dispose();
				}
			}

			void Scene::Created()
			{
			}

			void Scene::Deleted()
			{
			}
		}
	}
}