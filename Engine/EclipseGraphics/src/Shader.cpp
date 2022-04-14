#include "Shader.h"
#include <cassert>
#include <cstdio>
#include <glad/glad.h>

#include <EclipseEngine/include/Core.h>

namespace Eclipse
{
	namespace Graphics
	{
		Shader::~Shader()
		{
			glDeleteShader(shaderHandle);
		}

		bool Shader::LoadShader(unsigned int stage, const char* path)
		{
			assert(stage > 0 && stage < ShaderStage::SHADER_STAGE_Count);
			assert(path);
			shaderStage = stage;

			shaderName = Core::IO::GetFileNameFromPath(path);

			switch (stage)
			{
			case VERTEX: shaderHandle = glCreateShader(GL_VERTEX_SHADER);
				break;
			case GEOMETRY: shaderHandle = glCreateShader(GL_GEOMETRY_SHADER);
				break;
			case FRAGMENT: shaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
				break;
			default: break;
			}

			// open file
			FILE* file = nullptr;
			fopen_s(&file, path, "rb");
			fseek(file, 0, SEEK_END);
			unsigned int size = ftell(file);
			auto source = new char[size + 1];
			fseek(file, 0, SEEK_SET);
			fread_s(source, size + 1, sizeof(char), size, file);
			fclose(file);
			source[size] = 0;

			glShaderSource(shaderHandle, 1, (const char**)&source, nullptr);
			glCompileShader(shaderHandle);

			delete[] source;

			int success = GL_TRUE;
			glGetShaderiv(shaderHandle, GL_LINK_STATUS, &success);
			if (success == GL_FALSE)
			{
				int infoLogLength = 0;
				glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &infoLogLength);

				delete[] lastShaderError;
				lastShaderError = new char[infoLogLength];
				glGetShaderInfoLog(shaderHandle, infoLogLength, nullptr, lastShaderError);
				return false;
			}

			return true;
		}

		bool Shader::CreateShader(unsigned int stage, const char* string)
		{
			assert(stage > 0 && stage < ShaderStage::SHADER_STAGE_Count);

			shaderStage = stage;

			switch (stage)
			{
			case VERTEX: shaderHandle = glCreateShader(GL_VERTEX_SHADER);
				break;
			case GEOMETRY: shaderHandle = glCreateShader(GL_GEOMETRY_SHADER);
				break;
			case FRAGMENT: shaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
				break;
			default: break;
			}

			glShaderSource(shaderHandle, 1, &string, nullptr);
			glCompileShader(shaderHandle);

			int success = GL_TRUE;
			glGetShaderiv(shaderHandle, GL_LINK_STATUS, &success);
			if (success == GL_FALSE)
			{
				int infoLogLength = 0;
				glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &infoLogLength);

				delete[] lastShaderError;
				lastShaderError = new char[infoLogLength];
				glGetShaderInfoLog(shaderHandle, infoLogLength, nullptr, lastShaderError);
				return false;
			}

			return true;
		}

		bool Shader::Load(const Engine::ResourceDirectories& directories)
		{
			return false;
		}
	}
}