#pragma once

#include <EclipseEngine/include/EngineModule.h>
#include <EclipseEngine/include/EclipseEvent.h>


namespace Eclipse
{
	namespace Graphics
	{
		class GraphicsModule :
			public Engine::EngineModule
		{
		public:

			/// <summary>
			///	This event will be called when OpenGL has successfully been initialized.
			/// </summary>
			static Engine::EclipseEvent<> OnOpenGLLoad;

			/*

				Base class overrides.
			
			*/
			void EngineInit() override;
			void PostEngineInit() override;
			void Created() override;
			void Deleted() override;
			void Boot() override;
			void OnAwake() override;
			void OnFrameBegin() override;
			void OnPreDraw() override;
			void OnPostDraw() override;
		};
	}
}
