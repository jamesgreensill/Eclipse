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

			
			/// <summary>
			///	Send the mesh data to the renderer.
			/// </summary>
			void Draw();
			/// <summary>
			///	Set the data of this mesh.
			/// </summary>
			void SetData(std::vector<Vertex> vertices, std::vector<unsigned int> indices = {});
			/// <summary>
			///	Set this mesh up with OpenGL.
			/// </summary>
			void Setup();


			/*
			
				Getter & Setter wrappers.

			*/

			GET(Indices, return m_Indices; );
			GET(Vertices, return m_Vertices; );
			SET(Indices, std::vector<unsigned int>, m_Indices = value; );
			SET(Vertices, std::vector<Vertex>, m_Vertices = value; );

			//Material material =
			//{
			//	Eclipse::Engine::ResourceManager::GetDefault<ShaderProgram>(),
			//};

			Material material = 
			{
				Eclipse::Engine::ResourceManager::GetDefault<ShaderProgram>(),
				Eclipse::Engine::ResourceManager::GetDefault<Texture>(),
				Eclipse::Engine::ResourceManager::GetDefault<Texture>(),
				Eclipse::Engine::ResourceManager::GetDefault<Texture>()
			};
		private:

			std::vector<Vertex> m_Vertices = {};
			std::vector<unsigned int> m_Indices = {};
			// triangle count
			unsigned int triCount = 0;
			// vertex array object
			unsigned int vao = 0;
			// vertex buffer object
			unsigned int vbo = 0;
			// index buffer object
			unsigned int ibo = 0;

			friend class Components::MeshRenderer;
		};
	}
}
