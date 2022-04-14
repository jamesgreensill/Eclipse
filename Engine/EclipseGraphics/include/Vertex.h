#pragma once
#include <glm/glm.hpp>

namespace Eclipse
{
	namespace Graphics
	{
		struct Vertex
		{
			glm::vec3 position = glm::vec3(0);
			glm::vec3 normal = glm::vec3(0);
			glm::vec2 textureCoordinate = glm::vec2(0);

			glm::vec3 tangent = glm::vec3(0);
			glm::vec3 biTangent = glm::vec3(0);
		};
	}
}
