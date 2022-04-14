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
			Core::Data::ECC refreshColor = { 1,1,1,1 };
		};

		class Application
		{
		public:
			static Application* Instance;

			Engine* m_Engine = nullptr;
			ApplicationSettings settings;
			bool m_shouldClose = false;

			void Stop();
			bool ShouldClose() const;
			void SetBackgroundColor(Core::Data::ECC color);

			static void Run(SceneManagement::Scene* mainScene = nullptr);
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
