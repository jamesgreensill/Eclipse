#pragma once

#include "BaseModel.h"
#include "System.h"
#include "EntityContainer.h"

namespace Eclipse
{
	namespace Engine
	{
		class System;

		class EngineModule :
			public BaseModel
		{
			friend class Engine;

		public:
			
			/// <summary>
			/// ECS container following the modified ECS pattern.
			/// </summary>
			EntityContainer<System> m_SystemsContainer = EntityContainer<System>
				(
					[&](System* system)
					{
						system->Created();
						system->engineModule = this;
					},
					[&](System* system)
					{
						system->Deleted();
					}
					);
			virtual void PreEngineInit();
			virtual void EngineInit();
			virtual void PostEngineInit();
			virtual void PostBoot();
			virtual void Boot() = 0;

			/*
				Event functions.
			*/
			virtual void OnAwake();
			virtual void OnStart();
			virtual void OnLateStart();
			virtual void OnFrameBegin();
			virtual void OnFixedUpdate();
			virtual void OnUpdate();
			virtual void OnLateUpdate();
			virtual void OnPreDraw();
			virtual void OnDraw();
			virtual void OnPostDraw();
			virtual void OnGizmos();
			virtual void OnPreGui();
			virtual void OnGui();
			virtual void OnPostGui();
			virtual void OnFrameEnd();
			virtual void OnDispose();

			/*
				Final overrides to prevent further derrivitations.
			*/
			void Awake() final;
			void Start() final;
			void LateStart() final;
			void FrameBegin() final;
			void FixedUpdate() final;
			void Update() final;
			void LateUpdate() final;
			void PreDraw() final;
			void Draw() final;
			void PostDraw() final;
			void Gizmos() final;
			void PreGui() final;
			void Gui() final;
			void PostGui() final;
			void FrameEnd() final;
			void Dispose() final;
		};
	}
}
