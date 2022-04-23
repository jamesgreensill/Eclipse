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

			/// <summary>
			///	Called prior to the first frame.
			/// </summary>
			virtual void Awake();

			/// <summary>
			///	Called on the first frame.
			/// </summary>
			virtual void Start();

			/// <summary>
			///	Called after the first frame.
			/// </summary>
			virtual void LateStart();

			/// <summary>
			///	Called when the frame begins.
			/// </summary>
			virtual void FrameBegin();
			
			/// <summary>
			///	Called on a serpate physics thread at a fixed timestep. <-- Thread not implemented yet.
			/// </summary>
			virtual void FixedUpdate();

			/// <summary>
			///	Called every frame prior to the render pipeline.
			/// </summary>
			virtual void Update();

			/// <summary>
			///	Called every frame prior to the render pipeline.
			/// </summary>
			virtual void LateUpdate();

			/// <summary>
			///	Called before rendering.
			/// </summary>
			virtual void PreDraw();

			/// <summary>
			///	Called for rendering.
			/// </summary>
			virtual void Draw();

			/// <summary>
			///	Called post rendering.
			/// </summary>
			virtual void PostDraw();
			
			/// <summary>
			///	Gizmo call for debugging.
			/// </summary>
			virtual void Gizmos();

			/// <summary>
			///	Called prior to Interface Rendering.
			/// </summary>
			virtual void PreGui();

			/// <summary>
			///	Called on Interface Rendering.
			/// </summary>
			virtual void Gui();

			/// <summary>
			///	Called post Interface Rendering.
			/// </summary>
			virtual void PostGui();

			/// <summary>
			///	Called at the end of the frame.
			/// </summary>
			virtual void FrameEnd();

			/// <summary>
			///	Called at the end of the objects lifecycle.
			/// </summary>
			virtual void Dispose();

			/// <summary>
			/// Constructor Wrapper.
			/// </summary>
			virtual void Created() = 0;

			/// <summary>
			/// Destructor Wrapper.
			/// </summary>
			virtual void Deleted() = 0;

			/**
			 * \brief DEPRECATED.
			 */
			virtual void RetrieveGuiData();

			std::string m_Name = "BaseModel.";
		};
	}
}
