#pragma once
#include <type_traits>
#include "Core.h"
#include "Engine.h"
#include "EclipseEvent.h"

namespace Eclipse {
	namespace Engine
	{
		class Engine;

		struct ApplicationSettings
		{
			// Windowing
			std::string windowTitle = "Application";
			int windowWidth = 1280;
			int windowHeight = 720;
			int minWindowWidth = 100;
			int minWindowHeight = 100;

			// Rendering
			Core::Data::ECC refreshColor = { 0,0,0,1 };
		};

		class Application
		{
		public:
		// Singleton Reference to application.
			static Application* Instance;

			Engine* m_Engine = nullptr;
			ApplicationSettings settings;
			bool m_shouldClose = false;

		// Stops the application and Engine.
			void Stop();
		// Checks if the application should close.
			bool ShouldClose() const;
		// Sets the application's refresh color.
			void SetBackgroundColor(Core::Data::ECC color);

		/*
			Run the Application and Engine.
		*/
			static void Run(SceneManagement::Scene* mainScene = nullptr);

		/*
			Use variadic templates to load Engine Modules and External API's.
		*/
			template<typename... Args>
			static Application* Create(ApplicationSettings settings)
			{
				if (Instance)
				{
					// debug instance already defined.
					return Instance;
				}
				Instance = new Application();

				if (!Instance)
				{
					// debug failed to create instance.
					return nullptr;
				}

				Instance->settings = settings;

				CompositeCall(TypeList<Args...>(), *Instance);
				return Instance;
			}
			Application();
			~Application();
		private:
			template<typename...>
			struct TypeList {};
			/*
				Composite call for module loading.
			*/
			template <typename T, typename ...TArgs>
			static void CompositeCall(TypeList<T, TArgs...>, Application& application)
			{
				Instance->m_Engine->m_ModuleContainer.AddComponent<T>();
				CompositeCall(TypeList<TArgs...>(), application);
			}
			static void CompositeCall(TypeList<>, Application& application) {}
		};
	}
}
