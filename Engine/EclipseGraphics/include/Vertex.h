#pragma once
#include <glm/glm.hpp>

namespace Eclipse
{
	namespace Graphics
	{
		struct Vertex
		{
			/// <summary>
			///	Position of the Vertex.
			/// </summary>
			glm::vec3 position = glm::vec3(0);
			/// <summary>
			///	Normal of the vertex.
			/// </summary>
			glm::vec3 normal = glm::vec3(0);
			/// <summary>
			///	Texture coordinate of the vertex.
			/// </summary>
			glm::vec2 textureCoordinate = glm::vec2(0);
			/// <summary>
			///	Tangent of the vertex.
			/// </summary>
			glm::vec3 tangent = glm::vec3(0);
			/// <summary>
			///	Bitangent of the vertex.
			/// </summary>
			glm::vec3 biTangent = glm::vec3(0);
		};
	}
}
