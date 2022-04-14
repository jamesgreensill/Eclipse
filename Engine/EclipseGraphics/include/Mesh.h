#pragma once
#include <vector>
#include "Texture.h"
#include "Vertex.h"
#include "Material.h"

namespace Eclipse
{
	namespace Components
	{
		class MeshRenderer;
	}
}

namespace Eclipse
{
	namespace Graphics
	{
		class Material;

		class Mesh
		{
		public:
			Mesh();
			Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices = {});
			~Mesh();
			
			void Draw();

			void SetData(std::vector<Vertex> vertices, std::vector<unsigned int> indices = {});

			Material* material;
			void Setup();
		private:

			unsigned int triCount;
			unsigned int vao, vbo, ibo;


			std::vector<Vertex> m_Vertices;
			std::vector<unsigned int> m_Indices;

			friend class Components::MeshRenderer;
		};
	}
}
