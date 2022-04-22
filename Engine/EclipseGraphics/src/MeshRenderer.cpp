#include <EclipseEngine/include/Core.h>
#include <EclipseEngine/include/Object.h>

#include "MeshRenderer.h"

#include "GraphicsModule.h"
#include "Renderer.h"
#include "Model.h"
#include "EclipseEngine/include/Engine.h"
#include "EclipseEngine/include/ResourceManager.h"
#include "EclipseEngine/include/Transform.h"

namespace Eclipse
{
	namespace Components
	{
		// Constructor.
		void MeshRenderer::Created()
		{
			Reset();
		}

		void MeshRenderer::Awake()
		{
			
		}

		// Queue meshes to the global renderer.
		void MeshRenderer::Draw()
		{
			if (!modelReference)
			{
				External::Debug::DebugAPI::Error("Mesh is not set");
				return;
			}
			for (auto& mesh : modelReference->m_Meshes)
			{
				if(Graphics::Renderer::Instance)
				{
					Graphics::Renderer::Instance->QueueCall
					(
						{ &mesh, object->transform }
					);
				}
			}
		}

		void MeshRenderer::Update()
		{
		}


		void MeshRenderer::Reset()
		{
			m_Name = "MeshRenderer";
		}

		// Set the rendered model.
		void MeshRenderer::SetModel(Engine::ResourceKey model)
		{
			m_ModelKey = model;
			modelReference = Engine::ResourceManager::Get<Graphics::Model>(m_ModelKey);

			if(!Engine::Engine::GetCondition("OpenGL.Load"))
			{
				Graphics::GraphicsModule::OnOpenGLLoad += [=]()
				{
					modelReference->Setup();
				};
			}
			else
				modelReference->Setup();
		}

		// Get the rendered model.
		Graphics::Model* MeshRenderer::GetModel() const
		{
			return modelReference;
		}
	}
}
