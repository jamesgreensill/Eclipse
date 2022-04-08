#include <pch.h>
#include <EclipseEngine/include/Eclipse.h>
#include <EclipseEngine/include/Object.h>

#include "MeshRenderer.h"
#include "Renderer.h"
#include "Model.h"

namespace Eclipse
{
	namespace Components
	{
		// Constructor.
		void MeshRenderer::Created()
		{
			Reset();
		}

		// Queue meshes to the global renderer.
		void MeshRenderer::Draw()
		{
			if (!m_Model)
			{
				Core::Debug::Error("Mesh is not set");
				return;
			}
			for (auto& mesh : m_Model->m_Meshes)
			{
				Rendering::Renderer::Instance->QueueCall
				(
					{ &mesh, object->transform }
				);
			}
		}

		void MeshRenderer::Reset()
		{
			name = "MeshRenderer";
		}

		// Set the rendered model.
		void MeshRenderer::SetModel(Rendering::Model* model)
		{
			if (model)
				m_Model = model;
			else
			{
				Core::Debug::Error("Failed to set mesh. Mesh was nullptr.");
			}
		}

		// Get the rendered model.
		Rendering::Model* MeshRenderer::GetModel() const
		{
			return m_Model;
		}
	}
}