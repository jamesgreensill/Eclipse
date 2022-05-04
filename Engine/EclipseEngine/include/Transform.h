#pragma once

#include <vector>
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

			/// <summary>
			/// Rotates this transform by vec3 rotations.
			/// </summary>
			auto Rotate(glm::vec3 rotations) -> void;
			/// <summary>
			/// Translates this transform by vec3 translation.
			/// </summary>
			auto Translate(glm::vec3 translation) -> void;
			/// <summary>
			/// Scales this transfrom by vec3 scale.
			/// </summary>
			auto Scale(glm::vec3 scale) -> void;
			/// <summary>
			/// Sets the rotation of this transform to vec3 rotations.
			/// </summary>
			auto SetRotation(glm::vec3 rotations) -> void;
			/// <summary>
			/// Sets the translation of this transform to vec3 translation.
			/// </summary>
			auto SetTranslation(glm::vec3 translation) -> void;
			/// <summary>
			/// Sets the scale of this transform to vec3 scale.
			/// </summary>
			auto SetScale(glm::vec3 scale) -> void;
			/// <summary>
			/// Adds a transform as a child to this transform.
			/// </summary>
			auto AddChild(Transform* child) -> void;
			/// <summary>
			/// Removes a child transform from this transform.
			/// </summary>
			auto RemoveChild(Transform* child) -> void;
			/// <summary>
			/// Removes a child transfrom from this transform at index.
			/// </summary>
			auto RemoveChild(unsigned int index) -> void;
			/// <summary>
			/// Gets the global transform hierarchy rotation.
			/// </summary>
			auto GetGlobalRotation() const->glm::quat;
			/// <summary>
			/// Gets the global transform hierarchy position.
			/// </summary>
			auto GetGlobalPosition() const->glm::vec3;
			/// <summary>
			/// Gets the global transform hierarchy scale.
			/// </summary>
			auto GetGlobalScale() const->glm::vec3;
			/// <summary>
			/// Gets the transforms forward direction.
			/// </summary>
			auto GetForward() const -> glm::vec3;
			/// <summary>
			/// Gets the transforms back direction.
			/// </summary>
			auto GetBack() const->glm::vec3;
			/// <summary>
			/// Gets the transforms right direction.
			/// </summary>
			auto GetRight()->glm::vec3;
			/// <summary>
			/// Gets the transforms left direction.
			/// </summary>
			auto GetLeft()->glm::vec3;
			/// <summary>
			/// Gets the transforms up direction.
			/// </summary>
			auto GetUp()->glm::vec3;
			/// <summary>
			/// Gets the transforms down direction.
			/// </summary>
			auto GetDown()->glm::vec3;
			/// <summary>
			/// Binds the transform to the specified shader.
			/// </summary>
			auto Bind(Graphics::ShaderProgram* shader) -> void;
			/// <summary>
			/// Deprecated.
			/// </summary>
			auto RetrieveGuiData() -> void override;
			// Constructor
			auto Created() -> void override;
			auto Reset() -> void override;
			Transform() = default;
		private:
			glm::mat4 transformationMatrix = glm::mat4(1.0f);
			glm::vec3 forward = { 0,0,1 };
			glm::vec3 right = { 1,0,0 };
			glm::vec3 up = { 0,1,0 };
			glm::vec3 eulerRotation{};
		};
	}
}
