#include <EclipseEngine/include/Scene.h>
#include <EclipseEngine/include/Transform.h>
#include <EclipseEngine/include/SceneManager.h>

#include "Mesh.h"
#include "Light.h"
#include "Camera.h"
#include "Renderer.h"

namespace Eclipse
{
	namespace Graphics
	{
		Renderer* Renderer::Instance = nullptr;

		using namespace Engine::SceneManagement;
		using namespace Components;

		void Renderer::Draw()
		{
			Camera* renderCamera = Camera::main;
			const std::vector<Light*> lights = SceneManager::Instance->GetActiveScene()->GetLights();
			while (!DrawCalls.empty())
			{
				const DrawCall call = DrawCalls.front();

				if (!renderCamera)
				{
					renderCamera = Camera::FindNextCamera();
				}
				if (!renderCamera)
				{
					break;
				}

				// warm the shader.
				call.mesh->material->shader->Bind();

				// Bind Camera.
				renderCamera->Bind(call.mesh->material->shader);

				// Bind Transform.
				call.transform->Bind(call.mesh->material->shader);

				// Bind Lights.
				for (int i = 0; i < lights.size(); i++)
				{
					lights[i]->Bind(i, call.mesh->material->shader);
				}

				// Bind Mesh's Material
				call.mesh->material->Bind();

				// Bind Global Ambiance Camera.
				call.mesh->material->shader->BindUniform(uniRendererAmbientColor, rendererAmbientColor);

				// Light Count.
				call.mesh->material->shader->BindUniform(uniRendererLightCount, static_cast<int>(lights.size()));

				// Draw Call.
				call.mesh->Draw();

				DrawCalls.pop();
			}
		}

		void Renderer::Created()
		{
			if (!Instance)
				Instance = this;
		}

		void Renderer::Deleted()
		{
			delete Instance;
		}

		auto Renderer::QueueCall(DrawCall call) -> void
		{
			DrawCalls.push(call);
		}
	}
}