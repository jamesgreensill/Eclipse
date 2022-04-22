#include <pch.h>
#include "Transform.h"

#include "Application.h"
#include "glm/gtx/matrix_decompose.hpp"
//#include "imgui/imgui.h"
#include "Object.h"
#include "glm/gtc/type_ptr.hpp"

//#include "ImGuiHelper.h"
//#include "ImString.h"
//
//#include "ImVec3.h"
//#include "ShaderProgram.h"

namespace Eclipse
{
	namespace Components
	{
		void Transform::Rotate(glm::vec3 rotations)
		{
			eulerRotation += rotations;
			rotation *= glm::quat(rotations);
		}

		void Transform::Translate(glm::vec3 translation)
		{
			position += translation;
		}

		void Transform::Scale(glm::vec3 scale)
		{
			this->scale += scale;
		}

		void Transform::SetRotation(glm::vec3 rotations)
		{
			rotation = glm::quat(rotations);
		}

		void Transform::SetTranslation(glm::vec3 translation)
		{
			position = translation;
		}

		void Transform::SetScale(glm::vec3 scale)
		{
			this->scale = scale;
		}

		void Transform::AddChild(Transform* child)
		{
			if (child)
			{
				children.emplace_back(child);
				child->parent = this;
			}
		}

		void Transform::RemoveChild(Transform* child)
		{
			if (child)
			{
				const auto& it = std::find(children.begin(), children.end(), child);

				if (it != children.end())
				{
					children.erase(it);
					child->parent = nullptr;
				}
			}
		}

		void Transform::RemoveChild(unsigned index)
		{
			if (!(index >= children.size()))
			{
				auto child = children[index];
				children.erase(children.begin() + index);
				child->parent = nullptr;
			}
		}

		glm::quat Transform::GetGlobalRotation() const
		{
			glm::quat result = glm::identity<glm::quat>();

			std::vector<glm::quat> hierarchy{};
			hierarchy.push_back(rotation);

			Transform* parentPtr = parent;

			while (parentPtr != nullptr)
			{
				hierarchy.push_back(parentPtr->rotation);
				parentPtr = parentPtr->parent;
			}

			for (int i = static_cast<int>(hierarchy.size() - 1); i >= 0; i--)
			{
				result *= hierarchy[i];
			}

			return result;
		}

		glm::vec3 Transform::GetGlobalPosition() const
		{
			glm::vec3 globalPosition = position;

			Transform* parentPtr = parent;
			while (parentPtr != nullptr)
			{
				globalPosition += parentPtr->position;
				parentPtr = parentPtr->parent;
			}

			return globalPosition;
		}

		glm::vec3 Transform::GetGlobalScale() const
		{
			glm::vec3 globalScale = scale;

			Transform* parentPtr = parent;
			while (parentPtr != nullptr)
			{
				globalScale += parentPtr->scale;
				parentPtr = parentPtr->parent;
			}

			return globalScale;
		}

		glm::vec3 Transform::GetForward() const
		{
			return GetGlobalRotation() * glm::vec3(0, 0, 1);
		}

		glm::vec3 Transform::GetBack() const
		{
			return -GetForward();
		}

		glm::vec3 Transform::GetRight()
		{
			return right = normalize(cross(GetForward(), glm::vec3(0, 1, 0)));
		}

		glm::vec3 Transform::GetLeft()
		{
			return -GetRight();
		}

		glm::vec3 Transform::GetUp()
		{
			return up = normalize(cross(GetRight(), GetForward()));
		}

		glm::vec3 Transform::GetDown()
		{
			return -GetUp();
		}

		void Transform::RetrieveGuiData()
		{


			//call.Push(new Engine::ImGuiTypes::ImString(&m_Name));
			//call.Push(new Engine::ImGuiTypes::ImVec3("Position", { &position.x,&position.y,&position.z }));
			//call.Push(new Engine::ImGuiTypes::ImVec3("Rotation", //{ &eulerRotation.x,&eulerRotation.y,&eulerRotation.z }));
			//call.Push(new Engine::ImGuiTypes::ImVec3("Scale", { &scale.x,&scale.y,&scale.z }));
			//rotation = glm::quat(glm::radians(eulerRotation));
		}

		void Transform::Created()
		{
			object->transform = this;
			Reset();
		}

		void Transform::Reset()
		{
			/*
			* 0 0 0 <- Position
			* 0 0 0 <- Rotation
			* 1 1 1 <- Scale
			*/

			m_Name = "Transform";
			SetTranslation(glm::vec3(0, 0, 0));
			SetRotation(glm::vec3(0));
			SetScale(glm::vec3(1));
			eulerRotation = {};
		}

		void Transform::Bind(Graphics::ShaderProgram* shader)
		{
			//Model Matrix
			
		}
	}
}
