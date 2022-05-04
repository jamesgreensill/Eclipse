#pragma once
#include "BaseModel.h"
#include "CoreModule.h"
#include "Scene.h"

namespace Eclipse
{
	namespace Engine
	{
		class Engine :
			public BaseModel
		{
		public:
			// Reference to the core module of the engine.
			CoreModule* m_Core = nullptr;

			/// <summary>
			/// Entity Container following a modified ECS pattern.
			/// </summary>
			EntityContainer<EngineModule> m_ModuleContainer = EntityContainer<EngineModule>
				(
					[](EngineModule* engineModule) {engineModule->Created(); },
					[](EngineModule* engineModule) {engineModule->Deleted(); }
			);

			void Run();
			
			/// <summary>
			/// This function is called when the engine is created.
			/// </summary>
			void Created() override;
			/// <summary>
			/// This function is called when the engine is about to be initialized.
			/// </summary>
			void PreEngineInit();
			/// <summary>
			/// This function is called when the engine is being initialized.
			/// </summary>
			void EngineInit();
			/// <summary>
			/// This function is called after the engine has been initialized.
			/// </summary>
			void PostEngineInit();
			/// <summary>
			/// This function is called when the engine is about to be booted.
			/// </summary>
			void Boot();
			/// <summary>
			/// This function is called after the engine boot.
			/// </summary>
			void PostBoot();
			/// <summary>
			/// This function is called prior to the first engine frame.
			/// </summary>
			void Awake() override;
			/// <summary>
			/// This function is called on the first engine frame.
			/// </summary>
			void Start() override;
			/// <summary>
			/// This function is called after the engine first frame.
			/// </summary>
			void LateStart() override;
			/// <summary>
			/// This function is called when a frame begins.
			/// </summary>
			void FrameBegin() override;
			/// <summary>
			/// This function is called on a seperate phyisics thread --> Thread Not Implemented.
			/// </summary>
			void FixedUpdate() override;
			/// <summary>
			/// This function is called every frame prior to rendereing.
			/// </summary>
			void Update() override;
			/// <summary>
			/// This function is called right after update, usually used for flow control.
			/// </summary>
			void LateUpdate() override;
			/// <summary>
			/// This function is called when rendering is about to begin.
			/// </summary>
			void PreDraw() override;
			/// <summary>
			/// This function is called when the engine is rendering.
			/// </summary>
			void Draw() override;
			/// <summary>
			/// This function is called when the engine has finished rendering.
			/// </summary>
			void PostDraw() override;
			/// <summary>
			/// This function will send Gizmo data to the renderer.
			/// </summary>
			void Gizmos() override;
			/// <summary>
			/// This function will be called prior to Interface rendering.
			/// </summary>
			void PreGui() override;
			/// <summary>
			/// This function will be called on Interface rendering.
			/// </summary>
			void Gui() override;
			/// <summary>
			/// This function will be called after Interface rendering.
			/// </summary>
			void PostGui() override;
			/// <summary>
			/// This function will be called to end the frame.
			/// </summary>
			void FrameEnd() override;
			/// <summary>
			/// This function will be called when the engine is disposed.
			/// </summary>
			void Dispose() override;
			/// <summary>
			/// This function will be called when the engine is deleted.
			/// </summary>
			void Deleted() override;

			// TODO:
			// convert to solid principles after submission
			// Temporarily used to for dynamic global booleans.
			static bool GetCondition(const std::string& name);
			static void SetCondition(const std::string& name, const bool& value);
			static void AddCondition(const std::string& name, const bool& value);
		private:
			static std::unordered_map<std::string, bool> EngineConditions;
		};
	}
}
