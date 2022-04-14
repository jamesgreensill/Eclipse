#pragma once
#include "EngineModule.h"

namespace Eclipse
{
	namespace Engine
	{
		class WindowModule :
			public EngineModule
		{
		public:
			void Created() override;
			void Deleted() override;
			void RetrieveGuiData() override;
			void PreEngineInit() override;
			void EngineInit() override;
			void PostEngineInit() override;
			void PostBoot() override;
			void Boot() override;
			void OnAwake() override;
			void OnStart() override;
			void OnLateStart() override;
			void OnFrameBegin() override;
			void OnFixedUpdate() override;
			void OnUpdate() override;
			void OnLateUpdate() override;
			void OnPreDraw() override;
			void OnDraw() override;
			void OnPostDraw() override;
			void OnGizmos() override;
			void OnPreGui() override;
			void OnGui() override;
			void OnPostGui() override;
			void OnFrameEnd() override;
			void OnDispose() override;
		};
	}
}
