#pragma once
#include "BaseModel.h"

namespace Eclipse
{
	namespace Engine
	{
		class Engine :
			public BaseModel
		{
		public:
			Engine();
			void Created() override;
			void Awake() override;
			void Start() override;
			void Update() override;
			void LateUpdate() override;
			void FixedUpdate() override;
			void Draw() override;
			void Gui() override;
			void RetrieveGuiData(ImGuiTypes::ImGuiCall& call) override;
			void Dispose() override;
			void Deleted() override;
		};
	}
}
