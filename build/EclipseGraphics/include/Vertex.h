#pragma once
#include <glm/glm.hpp>

namespace Eclipse
{
	namespace Rendering
	{
		struct Vertex
		{
			glm::vec3 position;
			glm::vec3 normal;
			glm::vec2 textureCoordinate;

			glm::vec3 tangent;
			glm::vec3 biTangent;
		};
	}
}
