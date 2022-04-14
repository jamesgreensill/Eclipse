#include "DebugSystem.h"
#include "Core.h"

namespace Eclipse
{
	namespace Debug
	{
		void DebugSystem::Awake()
		{
			Debug("Pre First Frame.");
		}

		void DebugSystem::Start()
		{
			Debug("First Frame.");
		}

		void DebugSystem::LateStart()
		{
			Debug("Post First Frame.");
		}

		void DebugSystem::FrameBegin()
		{
			Debug("Frame Begin.");
		}

		void DebugSystem::FixedUpdate()
		{
			Debug("Fixed Update.");
		}

		void DebugSystem::Update()
		{
			Debug("Update Game Logic.");
		}

		void DebugSystem::LateUpdate()
		{
			Debug("End Of Game Logic Update.");
		}

		void DebugSystem::PreDraw()
		{
			Debug("Pre Frame Render.");
		}

		void DebugSystem::Draw()
		{
			Debug("Frame Render.");
		}

		void DebugSystem::PostDraw()
		{
			Debug("Post Frame Render.");
		}

		void DebugSystem::Gizmos()
		{
			Debug("Gizmos.");
		}

		void DebugSystem::PreGui()
		{
			Debug("Pre Render Gui.");
		}

		void DebugSystem::Gui()
		{
			Debug("Render Gui.");
		}

		void DebugSystem::PostGui()
		{
			Debug("Post Render Gui.");
		}

		void DebugSystem::FrameEnd()
		{
			Debug("Frame End.");
		}

		void DebugSystem::Dispose()
		{
			Debug("Debug System Disposed.");
		}

		void DebugSystem::Created()
		{
			Debug("Debug System Created.");
		}

		void DebugSystem::Deleted()
		{
			Debug("Debug System Deleted.");
		}
	}
}