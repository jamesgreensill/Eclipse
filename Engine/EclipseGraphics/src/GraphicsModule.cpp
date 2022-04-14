#include "GraphicsModule.h"
#include "GraphicsApi.h"

#include "Renderer.h"

#include <EclipseEngine/include/ApiLoader.h>
#include <EclipseEngine/include/Resources.h>

#include "ShaderProgram.h"

namespace Eclipse
{
	namespace Graphics
	{
		void GraphicsModule::EngineInit()
		{
			ShaderProgram::LoadShaderProgram("./Data/Shaders/default.vs", "./Data/Shaders/default.vs", "defaultShader");
		}

		void GraphicsModule::Created()
		{
		}

		void GraphicsModule::Deleted()
		{
		}

		void GraphicsModule::Boot()
		{
			Engine::ApiLoader::Load<GraphicsApi>();
			m_SystemsContainer.AddComponent<Renderer>();
		}
	}
}