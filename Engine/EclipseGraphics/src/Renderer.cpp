#include <EclipseEngine/include/Scene.h>
#include <EclipseEngine/include/Transform.h>
#include <EclipseEngine/include/SceneManager.h>

#include "Mesh.h"
#include "Light.h"
#include "Camera.h"
#include "Renderer.h"

#include "EclipseEngine/include/ResourceManager.h"

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
			std::vector<Light*> lights = Light::Lights;
			while (!DrawCalls.empty())
			{
				const DrawCall call = DrawCalls.front();


				// if there is no camera then find an avaliable camera.
				if (!renderCamera)
				{
					renderCamera = Camera::FindNextCamera();
				}
				// if there is no camera, then break out of this loop.
				if (!renderCamera)
				{
					// remove draw call from drawCalls.
					DrawCalls.pop();
					break;
				}
				// fetch shader program resource.
				const auto shader = Engine::ResourceManager::Get<ShaderProgram>(call.mesh->material.shaderKey);

				// warm the shader.
				shader->Bind();

				// Bind Camera.
				renderCamera->Bind(shader);

				// Bind Transform.
				//call.transform->Bind(call.mesh->material->shader);

				// bind transform.
				shader->BindUniform(
					uniTransformModelMatrix, glm::translate(glm::mat4(1), call.transform->GetGlobalPosition()) * glm::mat4(call.transform->GetGlobalRotation()) * glm::scale(glm::mat4(1), call.transform->GetGlobalScale()));

				// Bind Lights.
				for (int i = 0; i < lights.size(); i++)
				{
					lights[i]->Bind(i, shader);
				}

				// Bind Mesh's Material
				call.mesh->material.Bind();

				// Bind Global Ambiance Camera.
				shader->BindUniform(uniRendererAmbientColor, rendererAmbientColor);

				// Light Count.
				shader->BindUniform(uniRendererLightCount, static_cast<int>(lights.size()));

				// Draw Call.
				call.mesh->Draw();

				// remove draw call from drawCalls.
				DrawCalls.pop();
			}
		}

		void Renderer::Created()
		{
			// Singleton reference.
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