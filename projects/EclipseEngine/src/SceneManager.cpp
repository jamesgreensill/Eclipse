#include <pch.h>
#include "SceneManager.h"

#include "Eclipse.h"
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
					if (!activeScene)
					{
						activeScene = scene;
						activeScene->Awake();
						activeScene->Start();
					}
					else
						nextScene = scene;
				}
				else NULL_REF()
			}

			void SceneManager::Load(int index)
			{
				if (!(static_cast<unsigned long long>(index) >= reserveScenes.size()))
				{
					Load(reserveScenes[index]);
				}
				else INDEX_OUT_OF_BOUNDS()
			}

			void SceneManager::Load(const char* filePath)
			{
				NOT_IMPLEMENTED(Load(const char* filePath))
			}

			void SceneManager::UnloadScene(unsigned index)
			{
				if (!(index > reserveScenes.size()))
				{
					RemoveScene(reserveScenes[index]);
				}
				else INDEX_OUT_OF_BOUNDS()
			}

			unsigned int SceneManager::GetIndexByName(const char* name)
			{
				NOT_IMPLEMENTED(GetIndexByName(const char* name))
					return 1;
			}

			void SceneManager::AddScene(Scene* scene)
			{
				if (scene)
				{
					reserveScenes.emplace_back(scene);
				}
				else NULL_REF()
			}

			void SceneManager::AddScene(const char* filePath)
			{
				NOT_IMPLEMENTED(AddScene(const char* filePath))
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
				else NULL_REF()
			}

			void SceneManager::RemoveScene(unsigned index)
			{
				if (!(index > reserveScenes.size()))
				{
					RemoveScene(reserveScenes[index]);
				}
				else INDEX_OUT_OF_BOUNDS()
			}

			void SceneManager::LoadNextScene()
			{
				currentSceneIndex++;

				if (!(static_cast<unsigned long long>(currentSceneIndex) >= reserveScenes.size()))
					Load(currentSceneIndex);
				else
				{
					currentSceneIndex = static_cast<int>(reserveScenes.size() - 1);
					INDEX_OUT_OF_BOUNDS()
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
					INDEX_OUT_OF_BOUNDS()
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

				Load(new Scene());
			}

			void SceneManager::Deleted()
			{
				delete Instance;
			}
		}
	}
}