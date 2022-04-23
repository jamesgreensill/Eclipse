#pragma once

#include <vector>
#include <queue>

#include "System.h"

namespace Eclipse
{
	/**
	 * \brief THIS SYSTEM FOLLOWS THE SINGLETON PATTERN.
	 */
	 // https://en.wikipedia.org/wiki/Singleton_pattern

	namespace Engine
	{
		namespace SceneManagement
		{
			class Application;
			class Scene;

			// TODO: Refactor SceneManager.h & SceneManager.cpp
			class SceneManager : public System
			{
			public:
				/**
				 * \brief Load scene into active scenes.
				 * \param scene to be loaded.
				 */
				void Load(Scene* scene);
				/**
				 * \brief Load scene into active scenes.
				 * \param index of scene in reserve scenes.
				 */
				void Load(int index);
				/**
				 * \brief load external scene from a file.
				 * \param filePath - location of the file.
				 */
				void Load(const char* filePath);

				/**
				 * \brief scene Unloads a scene from activeScenes collection.
				 * \param scene to unload.
				 */
				void UnloadScene(Scene* scene);
				/**
				 * \brief scene Unloads a scene from activeScenes collection.
				 * \param index of scene in activeScenes to unload.
				 */
				void UnloadScene(unsigned int index);

				/**
				 * \brief Add scene into reserved scenes.
				 * \param scene to be added to the reserved scenes.
				 */
				void AddScene(Scene* scene);
				/**
				 * \brief Add scene into reserved scenes.
				 * \param filePath of scene to be added to reserved scenes.
				 */
				void AddScene(const char* filePath);
				/**
				 * \brief Remove scene from reserved scenes.
				 * \param scene to be removed from reserved scenes.
				 */
				void RemoveScene(Scene* scene);
				/**
				 * \brief Remove scene from reserved scenes.
				 * \param index of scene to be removed.
				 */
				void RemoveScene(unsigned int index);

				unsigned int GetIndexByName(const char* name);
				void LoadNextScene();
				void LoadPreviousScene();

				void CreateBlankScene();

				Scene* GetActiveScene() const;
				unsigned int GetSceneCount() const;

				static SceneManager* Instance;

				SceneManager();

				friend class Application;
			private:

				/*
				 *
				 *	Convert this to a caching system. (id, fileDirectory).
				 *
				 */
				 // all scenes loaded in memory.
				std::vector<Scene*> reserveScenes;
				Scene* activeScene;
				Scene* nextScene = nullptr;
				int currentSceneIndex;

				void SetScene();
				/*
					Same comments as base class, re-commenting would be boilerplate.
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
			};
		}
	}
}
