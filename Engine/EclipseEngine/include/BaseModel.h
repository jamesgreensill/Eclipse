#pragma once
#include <string>

namespace Eclipse
{
	namespace Engine
	{
		class BaseModel
		{
		public:
			virtual ~BaseModel() = default;

			virtual void Awake();
			virtual void Start();
			virtual void LateStart();
			virtual void FrameBegin();
			virtual void FixedUpdate();
			virtual void Update();
			virtual void LateUpdate();
			virtual void PreDraw();
			virtual void Draw();
			virtual void PostDraw();
			virtual void Gizmos();
			virtual void PreGui();
			virtual void Gui();
			virtual void PostGui();
			virtual void FrameEnd();
			virtual void Dispose();

			/**
			 * \brief Replacement for constructor.
			 */
			virtual void Created() = 0;

			/**
			 * \brief Replacement for destructor.
			 */
			virtual void Deleted() = 0;

			/**
			 * \brief DEPRECATED.
			 */
			virtual void RetrieveGuiData();

			std::string m_Name = "BaseModel.";
		};
	}
}
