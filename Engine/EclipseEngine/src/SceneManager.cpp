#include <pch.h>
#include "SceneManager.h"

#include "Core.h"
#include "Scene.h"

namespace Eclipse
{
	namespace Engine
	{
		namespace SceneManagement
		{
			SceneManager* SceneManager::Instance = nullptr;

			void SceneManager::Load(Scene* scene)
			{
				if (scene)
				{
					activeScene = scene;
					activeScene->Awake();
					activeScene->Start();
				}
				else
				{
					External::Debug::DebugAPI::Error("Null Reference - Load - SceneManager.");
				}
			}

			void SceneManager::Load(int index)
			{
				if (!(static_cast<unsigned long long>(index) >= reserveScenes.size()))
				{
					Load(reserveScenes[index]);
				}
				else
					External::Debug::DebugAPI::Error("Index Out Of Bounds - Load - SceneManager.");
			}

			void SceneManager::Load(const char* filePath)
			{
				External::Debug::DebugAPI::Error("Not Implemented - Load - SceneManager.");
			}

			void SceneManager::UnloadScene(unsigned index)
			{
				if (!(index > reserveScenes.size()))
				{
					RemoveScene(reserveScenes[index]);
				}
				else
					External::Debug::DebugAPI::Error("Index Out Of Bounds - UnloadScene - SceneManager.");
			}

			unsigned int SceneManager::GetIndexByName(const char* name)
			{
				External::Debug::DebugAPI::Error("Not Implemented - GetIndexByName - SceneManager.");
				return 1;
			}

			void SceneManager::AddScene(Scene* scene)
			{
				if (scene)
				{
					reserveScenes.emplace_back(scene);
				}
				else
					External::Debug::DebugAPI::Error("Null Reference - AddScene - SceneManager.");
			}

			void SceneManager::AddScene(const char* filePath)
			{
				External::Debug::DebugAPI::Error("Not Implemented - AddScene - SceneManager.");
			}

			void SceneManager::RemoveScene(Scene* scene)
			{
				if (scene)
				{
					const auto& sceneIt = std::find(reserveScenes.begin(), reserveScenes.end(), scene);
					if (sceneIt != reserveScenes.end())
					{
						const Scene* sceneToDelete = *sceneIt;
						reserveScenes.erase(sceneIt);
						delete sceneToDelete;
					}
				}
				else
					External::Debug::DebugAPI::Error("Null Reference - RemoveScene - SceneManager.");
			}

			void SceneManager::RemoveScene(unsigned index)
			{
				if (!(index > reserveScenes.size()))
				{
					RemoveScene(reserveScenes[index]);
				}
				else
					External::Debug::DebugAPI::Error("Index Out Of Bounds - RemoveScene - SceneManager.");
			}

			void SceneManager::LoadNextScene()
			{
				currentSceneIndex++;

				if (!(static_cast<unsigned long long>(currentSceneIndex) >= reserveScenes.size()))
					Load(currentSceneIndex);
				else
				{
					currentSceneIndex = static_cast<int>(reserveScenes.size() - 1);
					External::Debug::DebugAPI::Error("Index Out Of Bounds - LoadNextScene - SceneManager.");
				}
			}

			void SceneManager::LoadPreviousScene()
			{
				currentSceneIndex--;

				if (!(currentSceneIndex < 0))
					Load(currentSceneIndex);
				else
				{
					currentSceneIndex = 0;
					External::Debug::DebugAPI::Error("Index Out Of Bounds - LoadPreviousScene - SceneManager.");
				}
			}

			void SceneManager::CreateBlankScene()
			{
			}

			Scene* SceneManager::GetActiveScene() const
			{
				return activeScene;
			}

			unsigned SceneManager::GetSceneCount() const
			{
				return reserveScenes.size();
			}

			SceneManager::SceneManager() : activeScene(nullptr), currentSceneIndex(0)
			{
			}

			void SceneManager::SetScene()
			{
				if (nextScene)
				{
					activeScene->Dispose();
					activeScene = nextScene;
					activeScene->Awake();
					activeScene->Start();
					nextScene = nullptr;
				}
			}

			void SceneManager::Awake()
			{
				if (activeScene)
					activeScene->Awake();
			}
			void SceneManager::Start()
			{
				if (activeScene)
					activeScene->Start();
			}
			void SceneManager::Update()
			{
				if (activeScene)
					activeScene->Update();
			}

			void SceneManager::LateUpdate()
			{
				if (activeScene)
					activeScene->LateUpdate();

				SetScene();
			}

			void SceneManager::FixedUpdate()
			{
				if (activeScene)
					activeScene->FixedUpdate();
			}
			void SceneManager::Draw()
			{
				if (activeScene)
					activeScene->Draw();
			}

			void SceneManager::Dispose()
			{
				if (activeScene)
					activeScene->Dispose();
			}

			void SceneManager::Created()
			{
				if (!Instance)
					Instance = this;
				if (!Instance->activeScene)
					Instance->activeScene = new Scene();
			}

			void SceneManager::Deleted()
			{
				delete Instance;
			}
		}
	}
}