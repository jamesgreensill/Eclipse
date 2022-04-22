#pragma once
#include <EclipseEngine/include/ResourceManager.h>
#include <vector>
#include "Material.h"
#include "Texture.h"
#include "Vertex.h"

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
		struct Material;

		struct Mesh
		{
			~Mesh();

			void Draw();
			void SetData(std::vector<Vertex> vertices, std::vector<unsigned int> indices = {});
			void Setup();

			GET(Indices, return m_Indices; );
			GET(Vertices, return m_Vertices; );
			SET(Indices, std::vector<unsigned int>, m_Indices = value; );
			SET(Vertices, std::vector<Vertex>, m_Vertices = value; );

			Material material
			{
				// ShaderKey
				Eclipse::Engine::ResourceManager::GetDefault<ShaderProgram>(),
				Eclipse::Engine::ResourceManager::GetDefault<Texture>(),
				Eclipse::Engine::ResourceManager::GetDefault<Texture>(),
				Eclipse::Engine::ResourceManager::GetDefault<Texture>()
			};
		private:

			std::vector<Vertex> m_Vertices = {};
			std::vector<unsigned int> m_Indices = {};
			unsigned int triCount = 0;
			unsigned int vao = 0;
			unsigned int vbo = 0;
			unsigned int ibo = 0;

			friend class Components::MeshRenderer;
		};
	}
}
