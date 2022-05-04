#include "EngineModule.h"
#include "Core.h"

namespace Eclipse
{
	namespace Engine
	{
		/**
		 * \brief Event Functions.
		 */
		void EngineModule::PreEngineInit() {}
		void EngineModule::EngineInit() {}
		void EngineModule::PostEngineInit() {}
		void EngineModule::PostBoot() {}
		void EngineModule::OnAwake() {}
		void EngineModule::OnStart() {}
		void EngineModule::OnLateStart() {}
		void EngineModule::OnFrameBegin() {}
		void EngineModule::OnFixedUpdate() {}
		void EngineModule::OnUpdate() {}
		void EngineModule::OnLateUpdate() {}
		void EngineModule::OnPreDraw() {}
		void EngineModule::OnDraw() {}
		void EngineModule::OnPostDraw() {}
		void EngineModule::OnGizmos() {}
		void EngineModule::OnPreGui() {}
		void EngineModule::OnGui() {}
		void EngineModule::OnPostGui() {}
		void EngineModule::OnFrameEnd() {}
		void EngineModule::OnDispose() {}

		void EngineModule::Awake()
		{
			for(const auto& item : (m_SystemsContainer.m_Components))
			{
				item.second->Awake();
			}
				OnAwake();
		}

		void EngineModule::Start()
		{
			FFMCP(Start, m_SystemsContainer.m_Components)
				OnStart();
		}

		void EngineModule::LateStart()
		{
			FFMCP(LateStart, m_SystemsContainer.m_Components)
				OnLateStart();
		}

		void EngineModule::FrameBegin()
		{
			FFMCP(FrameBegin, m_SystemsContainer.m_Components)
				OnFrameBegin();
		}

		void EngineModule::FixedUpdate()
		{
			FFMCP(FixedUpdate, m_SystemsContainer.m_Components)
				OnFixedUpdate();
		}

		void EngineModule::Update()
		{
			FFMCP(Update, m_SystemsContainer.m_Components)
				OnUpdate();
		}

		void EngineModule::LateUpdate()
		{
			FFMCP(LateUpdate, m_SystemsContainer.m_Components)
				OnLateUpdate();
		}

		void EngineModule::PreDraw()
		{
			FFMCP(PreDraw, m_SystemsContainer.m_Components)
				OnPreDraw();
		}

		void EngineModule::Draw()
		{
			FFMCP(Draw, m_SystemsContainer.m_Components)
				OnDraw();
		}

		void EngineModule::PostDraw()
		{
			FFMCP(PostDraw, m_SystemsContainer.m_Components)
				OnPostDraw();
		}

		void EngineModule::Gizmos()
		{
			FFMCP(Gizmos, m_SystemsContainer.m_Components)
				OnGizmos();
		}

		void EngineModule::PreGui()
		{
			FFMCP(PreGui, m_SystemsContainer.m_Components)
				OnPreGui();
		}

		void EngineModule::Gui()
		{
			FFMCP(Gui, m_SystemsContainer.m_Components)
				OnGui();
		}

		void EngineModule::PostGui()
		{
			FFMCP(PostGui, m_SystemsContainer.m_Components)
				OnPostGui();
		}

		void EngineModule::FrameEnd()
		{
			FFMCP(FrameEnd, m_SystemsContainer.m_Components)
				OnFrameEnd();
		}

		void EngineModule::Dispose()
		{
			FFMCP(Dispose, m_SystemsContainer.m_Components)
				OnDispose();
		}
	}
}