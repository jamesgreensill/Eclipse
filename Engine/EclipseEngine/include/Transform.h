#pragma once

#include <vector>
//#include <EclipseEngine/include/Component.h>

#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Component.h"

namespace Eclipse
{
	namespace Graphics
	{
		class ShaderProgram;
	}
	namespace Components
	{
		class Transform :
			public Component
		{
#define uniTransformModelMatrix "modelMatrix"
		public:
			glm::vec3 scale{};
			glm::quat rotation{};
			glm::vec3 position{};
			glm::vec3 skew{};
			glm::vec4 perspective{};
			std::vector<Transform*> children{};
			Transform* parent = nullptr;


			auto Rotate(glm::vec3 rotations) -> void;
			auto Translate(glm::vec3 translation) -> void;
			auto Scale(glm::vec3 scale) -> void;
			auto SetRotation(glm::vec3 rotations) -> void;
			auto SetTranslation(glm::vec3 translation) -> void;
			auto SetScale(glm::vec3 scale) -> void;
			auto AddChild(Transform* child) -> void;
			auto RemoveChild(Transform* child) -> void;
			auto RemoveChild(unsigned int index) -> void;
			auto GetGlobalRotation() const->glm::quat;
			auto GetGlobalPosition() const->glm::vec3;
			auto GetGlobalScale() const->glm::vec3;
			auto GetForward() const -> glm::vec3;
			auto GetBack() const->glm::vec3;
			auto GetRight()->glm::vec3;
			auto GetLeft()->glm::vec3;
			auto GetUp()->glm::vec3;
			auto GetDown()->glm::vec3;


			Transform() = default;

			auto RetrieveGuiData() -> void override;

			auto Created() -> void override;
			auto Reset() -> void override;

			auto Bind(Graphics::ShaderProgram* shader) -> void;

		private:
			glm::mat4 transformationMatrix = glm::mat4(1.0f);
			glm::vec3 forward = { 0,0,1 };
			glm::vec3 right = { 1,0,0 };
			glm::vec3 up = { 0,1,0 };
			glm::vec3 eulerRotation{};
		};
	}
}
