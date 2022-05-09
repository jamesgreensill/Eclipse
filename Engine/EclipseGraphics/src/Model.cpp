#include "Model.h"

#include <assimp/mesh.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <EclipseEngine/include/Core.h>

#include <EclipseEngine/include/EngineMacros.h>

namespace Eclipse
{
	/*
	 *
	 *	TODO: Follow one responsibility design pattern.
	 *	Move Load into Resources.
	 *
	 */

	namespace Graphics
	{
		bool Model::Load(const Engine::ResourceDirectories& directories)
		{
			ASSERT(directories.size() == 1, Model.Load() must only have one directory parsed.);

			const std::string filePath = directories[0];

			Assimp::Importer importer;
			const aiScene* scene = importer.ReadFile(filePath, aiProcess_Triangulate);//aiProcess_CalcTangentSpace);
			// check for errors
			if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
			{
				return false;
			}
			// retrieve the directory path of the filepath
			m_directory = filePath.substr(0, filePath.find_last_of('/'));

			for (unsigned int i = 0; i < scene->mNumMeshes; i++)
				m_Meshes.emplace_back(ProcessMesh(scene->mMeshes[i], scene));
			return true;
		}

		auto Model::Setup() -> bool
		{
			for (auto& mesh : m_Meshes)
			{
				mesh.Setup();
			}
			return true;
		}

		void Model::ProcessNode(aiNode* node, const aiScene* scene)
		{
			for (unsigned int i = 0; i < node->mNumChildren; i++)
			{
				ProcessNode(node->mChildren[i], scene);
			}
		}

		Mesh Model::ProcessMesh(aiMesh* mesh, const aiScene* scene)
		{
			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;
			std::vector<Texture> textures;

			const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);

			// loop through every vertex
			for (unsigned int i = 0; i < mesh->mNumVertices; i++) {

				// create stack allocation for vertex.
				Vertex vertex =
				{
					{mesh->mVertices[i].x, mesh->mVertices[i].y,mesh->mVertices[i].z},
					{mesh->mNormals[i].x, mesh->mNormals[i].y,mesh->mNormals[i].z},
					{0,0},
				};

				if (mesh->mTextureCoords[0])
					vertex.textureCoordinate = { mesh->mTextureCoords[0][i].x,mesh->mTextureCoords[0][i].y };

				// emplace vertex into vertices.
				vertices.emplace_back(vertex);
			}

			for (unsigned int i = 0; i < mesh->mNumFaces; i++)
			{
				for (unsigned int j = 0; j < mesh->mFaces[i].mNumIndices; j++)
				{
					indices.emplace_back(mesh->mFaces[i].mIndices[j]);
				}
			}
			aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

			// return a mesh object created from the extracted mesh data
			Mesh returnMesh = {};
			returnMesh.SetIndices(indices);
			returnMesh.SetVertices(vertices);

			return returnMesh;
		}
	}
}