#include <pch.h>
#include "Resources.h"

#include "Core.h"
/*
 *
 *	Supported Classes.
 *
 *	Eclipse->Rendering
 *		ShaderProgram.
 *		Shader.
 *
 */

 //#include <assimp/Importer.hpp>
 //#include <assimp/postprocess.h>
 //#include <assimp/scene.h>
 //
 //#include "Model.h"
 //#include "ShaderProgram.h"
 //#include <stb/stb_image.h>

namespace Eclipse
{
	namespace Engine
	{
		Graphics::ShaderProgram* Resources::defaultShaderProgram = nullptr;
		std::map<std::string, std::string> Resources::defaultDirectories{};
		std::map<std::string, Graphics::ShaderProgram*> Resources::shaderPrograms{};
		std::map<std::string, Graphics::Shader*> Resources::shaders{};

		auto Resources::LoadShaderProgram(const char* vertex, const char* fragment, const char* shaderProgramName) -> Graphics::ShaderProgram*
		{
			//assert(vertex && fragment && shaderProgramName);
			//
			//const auto program = new Rendering::ShaderProgram();
			//if (!program)
			//{
			//	NULL_REF()
			//		return program;
			//}
			//
			//program->LoadShader(Rendering::VERTEX, (GetDirPrefix("shader") + std::string(vertex)).c_str());
			//program->LoadShader(Rendering::FRAGMENT, (GetDirPrefix("shader") + std::string(fragment)).c_str/());
			//
			//if (!program->Link())
			//{
			//	Core::Debug::Error(program->GetLastError());
			//	return nullptr;
			//}
			//
			//program->shaderProgramName = std::string(shaderProgramName);
			//
			//AddShaderProgram(program);
			//return program;
			return 0;
		}

		auto Resources::AddShaderProgram(Graphics::ShaderProgram* program) -> void
		{
			//if (!program)
			//{
			//	NULL_REF()
			//		return;
			//}
			//
			//shaderPrograms.try_emplace(program->shaderProgramName, program);
		}

		auto Resources::UnloadShaderProgram(Graphics::ShaderProgram* program) -> void
		{
			//if (!program)
			//{
			//	NULL_REF()
			//		return;
			//}
			//
			//const auto shaderPtr = GetShaderProgram(program->shaderProgramName.c_str());
			//if (shaderPtr)
			//{
			//	shaderPrograms.erase(shaderPtr->shaderProgramName);
			//}
			//else NULL_REF()
		}

		auto Resources::UnloadShaderProgram(const char* program) -> void
		{
			if (program)
			{
				UnloadShaderProgram(shaderPrograms[std::string(program)]);
			}
		}

		auto Resources::GetShaderProgram(const char* shaderProgramName) -> Graphics::ShaderProgram*
		{
			if (shaderProgramName)
			{
				return shaderPrograms.at(std::string(shaderProgramName));
			}
			External::Debug::DebugAPI::Error("Null Reference: Get Shader Program - Resources.");
			return nullptr;
		}

		auto Resources::GetDefaultShaderProgram() -> Graphics::ShaderProgram*
		{
			return defaultShaderProgram;
		}

		auto Resources::AddShader(Graphics::Shader* shader) -> void
		{
			if (!shader)
			{
				External::Debug::DebugAPI::Error("Null Reference: Add Shader - Resources.");
				return;
			}

			//if (!shaders.try_emplace(shader->shaderName, shader).second)
			//{
			//	MAP_EMPLACE_FAIL(AddShader())
			//}
		}

		auto Resources::UnloadShader(Graphics::Shader* shader) -> void
		{
			if (!shader)
			{
				External::Debug::DebugAPI::Error("Null Reference: Unload Shader - Resources.");
				return;
			}

			//const auto shaderPtr = GetShader(shader->shaderName.c_str());
			//if (shaderPtr)
			//{
			//	shaders.erase(shaderPtr->shaderName);
			//}
			//else NULL_REF()
		}

		auto Resources::GetShader(const char* shaderName) -> Graphics::Shader*
		{
			if (shaderName)
			{
				return shaders.at(std::string(shaderName));
			}
			External::Debug::DebugAPI::Error("Null Reference: Get Shader - Resources.");
			return nullptr;
		}

		auto Resources::SetDirPrefix(const std::string& key, const std::string& value) -> void
		{
			if (!value.empty())
				defaultDirectories.at(key) = value;
		}

		auto Resources::GetDirPrefix(const std::string& key) -> std::string
		{
			const auto& it = defaultDirectories.find(key);

			if (it != defaultDirectories.end())
			{
				return defaultDirectories.at(key);
			}
			return "";
		}

		auto Resources::AddDirPrefix(const std::string& key, std::string value) -> std::string
		{
			if (defaultDirectories.try_emplace(key, value).second)
			{
				return value;
			}
			External::Debug::DebugAPI::Error("Map Emplace Fail - AddDirPrefix - Resources.");
			return "";
		}

		auto Resources::RemoveDirPrefix(const std::string& key) -> void
		{
			defaultDirectories.erase(key);
		}

		auto Resources::LoadModel(const std::string& path) -> Graphics::Model*
		{
			return 0;
		}

		auto Resources::LoadDefaultDirectories() -> void
		{
			//directories.shaderDir = "shaders/";
			//directories.da
		}

		auto Resources::LoadDefaultResources() -> void
		{
		}

		auto Resources::LoadTexture(std::string path) -> Graphics::Texture*
		{
			//Rendering::Texture* texture = new Rendering::Texture();
			//if (texture->m_handle != 0)
			//{
			//	glDeleteTextures(1, &texture->m_handle);
			//	texture->m_handle = 0;
			//	texture->m_width = 0;
			//	texture->m_height = 0;
			//	texture->m_fileName = "none";
			//}
			//
			//int x = 0;
			//int y = 0;
			//int composition = 0;
			//
			//texture->m_loadedPixels = stbi_load(path.c_str(), &x, &y, &composition, STBI_default);
			//
			//// file loaded correctly if true.
			//if (texture->m_loadedPixels != nullptr)
			//{
			//	glGenTextures(1, &texture->m_handle);
			//	glBindTexture(GL_TEXTURE_2D, texture->m_handle);
			//	switch (composition) {
			//	case STBI_grey:
			//		texture->m_format = Rendering::RED;
			//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, x, y,
			//			0, GL_RED, GL_UNSIGNED_BYTE, texture->m_loadedPixels);
			//		break;
			//	case STBI_grey_alpha:
			//		texture->m_format = Rendering::RG;
			//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, x, y,
			//			0, GL_RG, GL_UNSIGNED_BYTE, texture->m_loadedPixels);
			//		break;
			//	case STBI_rgb:
			//		texture->m_format = Rendering::RGB;
			//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y,
			//			0, GL_RGB, GL_UNSIGNED_BYTE, texture->m_loadedPixels);
			//		break;
			//	case STBI_rgb_alpha:
			//		texture->m_format = Rendering::RGBA;
			//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y,
			//			0, GL_RGBA, GL_UNSIGNED_BYTE, texture->m_loadedPixels);
			//		break;
			//	default:
			//		break;
			//	}
			//
			//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			//	glGenerateMipmap(GL_TEXTURE_2D);
			//	glBindTexture(GL_TEXTURE_2D, 0);
			//	texture->m_width = (unsigned int)x;
			//	texture->m_height = (unsigned int)y;
			//	texture->m_fileName = path;
			//}
			//return texture;
			return 0;
		}
	}
}