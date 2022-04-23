#pragma once
#include <EclipseEngine/include/System.h>

namespace Eclipse
{
	namespace Debug
	{
		/*
			Basic Frame Debugger class.
		*/
		class DebugSystem :
			public Engine::System
		{
		public:
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
			void Created() override;
			void Deleted() override;
		};
	}
}
