#include <pch.h>
#include "Model.h"

#include <assimp/mesh.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "Eclipse.h"

namespace Eclipse
{
	/*
	 *
	 *	TODO: Follow one responsibility design pattern.
	 *	Move Load into Resources.
	 *
	 */

	namespace Rendering
	{
		//void Model::Draw(bool usePatches)
		//{
		//	for (auto& mesh : m_Meshes)
		//	{
		//		mesh.Draw();
		//	}
		//}

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

			for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
				
				Vertex vertex =
				{
					{mesh->mVertices[i].x, mesh->mVertices[i].y,mesh->mVertices[i].z},
					{mesh->mNormals[i].x, mesh->mNormals[i].y,mesh->mNormals[i].z},
					{0,0},
					{mesh->mTangents[i].x, mesh->mTangents[i].y,mesh->mTangents[i].z},
					{mesh->mBitangents[i].x, mesh->mBitangents[i].y,mesh->mBitangents[i].z},

				};

				if (mesh->mTextureCoords[0])
					vertex.textureCoordinate = { mesh->mTextureCoords[0][i].x,mesh->mTextureCoords[0][i].y };

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
			return Mesh(vertices, indices);
		}
	}
}