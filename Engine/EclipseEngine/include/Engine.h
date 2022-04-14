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
			CoreModule* m_Core = nullptr;
			EntityContainer<EngineModule> m_ModuleContainer = EntityContainer<EngineModule>
				(
					[](EngineModule* engineModule) {engineModule->Created(); },
					[](EngineModule* engineModule) {engineModule->Deleted(); }
			);

			void Created() override;
			void Run(SceneManagement::Scene* mainScene = nullptr);

			void PreEngineInit();
			void EngineInit();
			void PostEngineInit();
			void Boot();
			void PostBoot();
			void Awake() override;
			void Start() override;
			void LateStart() override;
			void FrameBegin() override;
			void FixedUpdate() override;
			void Update() override;
			void LateUpdate() override;
			void PreDraw() override;
			void Draw() override;
			void PostDraw() override;
			void Gizmos() override;
			void PreGui() override;
			void Gui() override;
			void PostGui() override;
			void FrameEnd() override;
			void Dispose() override;
			void Deleted() override;
		};
	}
}
