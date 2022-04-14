#include <EclipseEngine/include/Core.h>
#include <EclipseEngine/include/Object.h>

#include "MeshRenderer.h"
#include "Renderer.h"
#include "Model.h"
#include "EclipseEngine/include/ResourceManager.h"

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
			if (modelReference)
				modelReference->Setup();
		}

		// Queue meshes to the global renderer.
		void MeshRenderer::Draw()
		{
			//if (!m_Model)
			//{
			//	External::Debug::DebugAPI::Error("Mesh is not set");
			//	return;
			//}
			//for (auto& mesh : m_Model->m_Meshes)
			//{
			//	Graphics::Renderer::Instance->QueueCall
			//	(
			//		{ &mesh, object->transform }
			//	);
			//}
		}

		void MeshRenderer::Reset()
		{
			m_Name = "MeshRenderer";
		}

		// Set the rendered model.
		void MeshRenderer::SetModel(Engine::ResourceKey& model)
		{
			m_ModelKey = model;
			modelReference = Engine::ResourceManager::Get<Graphics::Model>(m_ModelKey);
			modelReference->Setup();
		}

		// Get the rendered model.
		Graphics::Model* MeshRenderer::GetModel() const
		{
			return modelReference;
		}
	}
}