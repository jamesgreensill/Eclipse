#pragma once
#include <EclipseEngine/include/EngineMacros.h>
#include <string>
#include <vector>

#include "Material.h"
#include "Mesh.h"

struct aiMaterial;
struct aiMesh;
struct aiScene;
struct aiNode;

namespace Eclipse
{
	namespace Engine
	{
		class Resources;
	}

	namespace Graphics
	{
		class Model final : public Engine::Resource
		{
			friend class Components::MeshRenderer;
			friend class Engine::Resources;
		public:
			std::vector<Mesh> m_Meshes{};

			
			/// <summary>
			///	Load Model from file.
			/// </summary>
			auto Load(const Engine::ResourceDirectories& directories) -> bool override;
			/// <summary>
			///	Get Material.
			/// </summary>
			auto GetMaterial(size_t index) -> Material& { return m_Materials.at(index); }

			auto Setup() -> bool override;


			/*
			
				Getter & Setter wrappers.

			*/

			GET(MaterialCount, return m_Materials.size(););
			GET(FileName, return m_FileName;);
			SET(FileName, std::string,
				{
					m_FileName = value;
				});

			GET(Directory, return m_directory;);
			SET(Directory, std::string,
				{
					m_directory = value;
				});

		private:
			std::string m_directory;
			std::string m_FileName;
			std::vector<Material> m_Materials{};

			auto ProcessNode(aiNode* node, const aiScene* scene) -> void;
			auto ProcessMesh(aiMesh* mesh, const aiScene* scene)->Mesh;
		};
	}
}
