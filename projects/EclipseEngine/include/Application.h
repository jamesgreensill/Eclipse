#pragma once
#include <type_traits>
#include "Eclipse.h"

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
			static Application* GetInstance()
			{
				return Instance;
			}

			template <typename T>
			static Application* Create(ApplicationSettings settings);

			static void Run();
			static void Stop();

			static void SetBackgroundColor(Core::Data::ECC color);

		private:

			static Application* Instance;
			ApplicationSettings settings = {};
			Engine* m_Engine = nullptr;
			bool m_shouldClose = false;

			void Created();
			void Awake() const;
			void Start() const;
			void Update() const;
			void LateUpdate() const;
			void FixedUpdate() const;
			void Draw() const;
			void Gui() const;
			void Dispose() const;
			void Deleted() const;

			bool ShouldClose() const;

		protected:
			virtual void OnCreated();
			virtual void OnAwake();
			virtual void OnStart();
			virtual void OnUpdate();
			virtual void OnLateUpdate();
			virtual void OnFixedUpdate();
			virtual void OnDraw();
			virtual void OnGui();
			virtual void OnDispose();
			virtual void OnDeleted();

			~Application();
		};

		template <typename T>
		Application* Application::Create(ApplicationSettings settings)
		{
			static_assert(std::is_base_of<Application, T>::value, "T must be derived from base class Application.");

			if (Instance)
			{
				Core::Debug::Log("Instance is already defined.");
				return Instance;
			}

			Instance = new T();

			if (!Instance)
			{
				Core::Debug::Log("Instance failed to create.");
				return nullptr;
			}

			Instance->settings = settings;

			return Instance;
		}
	}
}