#include <pch.h>
#include "Mesh.h"

#include <glad/glad.h>

#include "Eclipse.h"

namespace Eclipse
{
	namespace Rendering
	{
		Mesh::Mesh() : Mesh({}, {}) {}
		Mesh::~Mesh()
			= default;
		Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned> indices)
		{
			material = new Material("defaultShader");
			triCount = 0;
			vao = 0;
			vbo = 0;
			ibo = 0;
			m_Vertices = vertices;
			m_Indices = indices;
			Setup();
		}

		void Mesh::Setup()
		{
			assert(vao == 0);

			Core::Rendering::GenBuffer(1, &vbo);

			Core::Rendering::GenVertexArray(1, &vao);
			Core::Rendering::BindVertexArray(vao);

			// Fill Vertex data
			Core::Rendering::BindBuffer(GL_ARRAY_BUFFER, vbo);
			Core::Rendering::FillBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(Vertex), &m_Vertices[0], GL_STATIC_DRAW);

			if (!m_Indices.empty())
			{
				Core::Rendering::GenBuffer(1, &ibo);
				Core::Rendering::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
				Core::Rendering::FillBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(unsigned int), &m_Indices[0],
					GL_STATIC_DRAW);
			}

			// Layout of vertex Data.

			// Position
			Core::Rendering::EnableVertexAttributeArray(0);
			Core::Rendering::VertexAttributePointer(0, 3, GL_FLOAT, false, sizeof(Vertex), nullptr);

			// Normal
			Core::Rendering::EnableVertexAttributeArray(1);
			Core::Rendering::VertexAttributePointer(1, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, normal));

			// TextureCoords.
			Core::Rendering::EnableVertexAttributeArray(2);
			Core::Rendering::VertexAttributePointer(2, 2, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, textureCoordinate));

			// Tangents.
			Core::Rendering::EnableVertexAttributeArray(3);
			Core::Rendering::VertexAttributePointer(3, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, tangent));

			// biTangents
			Core::Rendering::EnableVertexAttributeArray(4);
			Core::Rendering::VertexAttributePointer(4, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, biTangent));

			/// <summary>
			/// Unbind
			/// </summary>
			/// <param name="mesh"></param>
			Core::Rendering::BindVertexArray(0);
			Core::Rendering::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			Core::Rendering::BindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void Mesh::Draw()
		{
			unsigned int diffuseNr = 1;
			unsigned int specularNr = 1;
			unsigned int normalNr = 1;
			unsigned int heightNr = 1;

			Core::Rendering::BindVertexArray(vao);
			if (ibo == 0)
			{
				Core::Rendering::DrawArrays(GL_TRIANGLES, 0, static_cast<int>(floor(m_Indices.size())));
			}
			else
				Core::Rendering::DrawElements(GL_TRIANGLES, static_cast<int>(m_Vertices.size()), GL_UNSIGNED_INT, nullptr);

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

			Core::Rendering::BindVertexArray(vao);
			Core::Rendering::BindBuffer(GL_ARRAY_BUFFER, vbo);
			Core::Rendering::FillBufferSubData(GL_ARRAY_BUFFER, 0, m_Vertices.size() * sizeof(Vertex), &m_Vertices[0]);

			if (!m_Indices.empty())
			{
				Core::Rendering::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
				Core::Rendering::FillBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, m_Indices.size() * sizeof(unsigned int), &m_Indices[0]);
			}

			Core::Rendering::BindVertexArray(0);
			Core::Rendering::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			Core::Rendering::BindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
}