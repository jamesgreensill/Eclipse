#pragma once
#include <string>
#include <vector>

#include "Material.h"
#include "Vertex.h"
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

	namespace Rendering
	{
		class Model
		{
		public:
			friend class Engine::Resources;


			Model() = default;
			~Model() = default;

			std::string GetFileName() { return m_FileName; }
			std::string GetDirectoryPath() { return m_directory; }
			size_t GetMaterialCount() const { return m_Materials.size(); }
			Material& GetMaterial(size_t index) { return m_Materials.at(index); }

			std::vector<Mesh> m_Meshes{};
		private:
			void ProcessNode(aiNode* node, const aiScene* scene);
			Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);

			std::string m_directory;
			std::string m_FileName;
			std::vector<Material> m_Materials{};

			friend class Eclipse::Components::MeshRenderer;
		};
	}
}
