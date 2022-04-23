#include "Shader.h"
#include <cassert>
#include <cstdio>
#include <glad/glad.h>

#include <EclipseEngine/include/Core.h>

#include "GraphicsModule.h"
#include "EclipseEngine/include/Engine.h"
#include "EclipseEngine/include/Serialization.h"

namespace Eclipse
{
	namespace Graphics
	{
		Shader::~Shader()
		{
			glDeleteShader(shaderHandle);
		}

		void Shader::LoadShader(unsigned int stage, const char* path)
		{
			// deprecated but used for reference.

			//// open file
			//FILE* file = nullptr;
			//fopen_s(&file, path, "rb");
			//fseek(file, 0, SEEK_END);
			//unsigned int size = ftell(file);
			//data = new char[size + 1];
			//fseek(file, 0, SEEK_SET);
			//fread_s(data, size + 1, sizeof(char), size, file);
			//fclose(file);
			//data[size] = 0;
		}

		bool Shader::Setup()
		{
			// create shader based on stage.
			switch (shaderStage)
			{
			case VERTEX: shaderHandle = glCreateShader(GL_VERTEX_SHADER);
				break;
			case GEOMETRY: shaderHandle = glCreateShader(GL_GEOMETRY_SHADER);
				break;
			case FRAGMENT: shaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
				break;
			default: break;
			}

			// set shader data.
			glShaderSource(shaderHandle, 1, (const char**)&data, nullptr);
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
			try
			{
				const int stage = std::stoi(directories[0]);
				std::string path = directories[1];
				assert(stage > 0 && stage < ShaderStage::SHADER_STAGE_COUNT);
				shaderStage = stage;
				shaderName = Core::IO::GetFileNameFromPath(path.c_str());

				// open file
				//FILE* file = nullptr;
				//fopen_s(&file, directories[1].c_str(), "rb");
				//fseek(file, 0, SEEK_END);
				//unsigned int size = ftell(file);
				//auto source = new char[size + 1];
				//fseek(file, 0, SEEK_SET);
				//fread_s(source, size + 1, sizeof(char), size, file);
				//fclose(file);
				//source[size] = 0;

				data = Engine::Serialization::LoadRawData(path);

				//data = std::vector<char>(source, source + size);

				//data.emplace_back('\0');

				if (data)
				{
					//LinkToCallback<>(GraphicsModule::OnOpenGLLoad, Engine::Engine::GetCondition("OpenGL.Load"));
					return true;
				}
				return false;
			}
			catch (...)
			{
				return false;
			}
		}
	}
}