#include "Mesh.h"

#include <glad/glad.h>

#include "Core.h"
#include "EclipseEngine/include/ResourceManager.h"

namespace Eclipse
{
	namespace Graphics
	{
		Mesh::~Mesh()
			= default;

		void Mesh::Setup()
		{
			if (vao > 0)
				return;
			assert(vao == 0);

			Graphics::GenBuffer(1, &vbo);

			Graphics::GenVertexArray(1, &vao);
			Graphics::BindVertexArray(vao);

			// Fill Vertex data
			Graphics::BindBuffer(GL_ARRAY_BUFFER, vbo);
			Graphics::FillBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(Vertex), &m_Vertices[0], GL_STATIC_DRAW);

			if (!m_Indices.empty())
			{
				Graphics::GenBuffer(1, &ibo);
				Graphics::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
				Graphics::FillBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(unsigned int), &m_Indices[0],
					GL_STATIC_DRAW);
			}

			// Layout of vertex Data.

			// Position
			Graphics::EnableVertexAttributeArray(0);
			Graphics::VertexAttributePointer(0, 3, GL_FLOAT, false, sizeof(Vertex), nullptr);

			// Normal
			Graphics::EnableVertexAttributeArray(1);
			Graphics::VertexAttributePointer(1, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, normal));

			// TextureCoords.
			Graphics::EnableVertexAttributeArray(2);
			Graphics::VertexAttributePointer(2, 2, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, textureCoordinate));

			// Deprecated, but needed for reference.

			//// Tangents.
			//Graphics::EnableVertexAttributeArray(3);
			//Graphics::VertexAttributePointer(3, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
			//
			//// biTangents
			//Graphics::EnableVertexAttributeArray(4);
			//Graphics::VertexAttributePointer(4, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, biTangent));

			/// <summary>
			/// Unbind
			/// </summary>
			/// <param name="mesh"></param>
			Graphics::BindVertexArray(0);
			Graphics::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			Graphics::BindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void Mesh::Draw()
		{
			unsigned int diffuseNr = 1;
			unsigned int specularNr = 1;
			unsigned int normalNr = 1;
			unsigned int heightNr = 1;

			Graphics::BindVertexArray(vao);
			// If this mesh has indices, use indices, otherwise use raw vertices to draw.
			if (ibo == 0)
			{
				Graphics::DrawArrays(GL_TRIANGLES, 0, static_cast<int>(floor(m_Indices.size())));
			}
			else
				Graphics::DrawElements(GL_TRIANGLES, static_cast<int>(m_Vertices.size()), GL_UNSIGNED_INT, nullptr);

			glBindVertexArray(0);
			glActiveTexture(GL_TEXTURE0);
		}

		void Mesh::SetData(std::vector<Vertex> vertices, std::vector<unsigned> indices)
		{
			m_Vertices = vertices;
			m_Indices = indices;

			if (vao == GL_INVALID_VALUE)
			{
				Setup();
				return;
			}

			Graphics::BindVertexArray(vao);
			Graphics::BindBuffer(GL_ARRAY_BUFFER, vbo);
			Graphics::FillBufferSubData(GL_ARRAY_BUFFER, 0, m_Vertices.size() * sizeof(Vertex), &m_Vertices[0]);

			if (!m_Indices.empty())
			{
				Graphics::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
				Graphics::FillBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, m_Indices.size() * sizeof(unsigned int), &m_Indices[0]);
			}

			Graphics::BindVertexArray(0);
			Graphics::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			Graphics::BindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
}