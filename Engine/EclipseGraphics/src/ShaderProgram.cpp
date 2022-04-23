#include "ShaderProgram.h"

#include <cstdio>
#include <glad/glad.h>

#include <EclipseEngine/include/Core.h>

#include "GraphicsModule.h"
#include "EclipseEngine/include/Engine.h"
#include "EclipseEngine/include/ResourceManager.h"

namespace Eclipse
{
	namespace Graphics
	{
		ShaderProgram::~ShaderProgram()
		{
			delete[] lastError;
			glDeleteProgram(program);
		}

		void ShaderProgram::LoadShader(unsigned int stage, const char* filename)
		{
			assert(stage > 0 && stage < ShaderStage::SHADER_STAGE_COUNT);

			Engine::ResourceKey key;
			if (Engine::ResourceManager::LoadNonAlloc<Shader>({ std::to_string(stage), std::string(filename) }, key))
			{
				shaderKeys[stage] = key;
			}
		}

		bool ShaderProgram::Setup()
		{
			// loop through every shader stage.
			for (int i = 1; i <= SHADER_STAGE_COUNT; i++)
			{
				// get the shader at i-1
				auto shader = Engine::ResourceManager::Get<Shader>(shaderKeys[i - 1]);
				if (shader)
					shader->Setup();
			}
			
			if (!this->Link())
			{
				External::Debug::DebugAPI::Debug(this->GetLastError());
				return false;
			}
			return true;
		}

		void ShaderProgram::AttachShader(const Engine::ResourceKey& shaderKey)
		{
			assert(shaderKey.resourceId != INVALID_RESOURCE);

			auto shader = Engine::ResourceManager::Get<Shader>(shaderKey);

			if (shader)
				shaderKeys[shader->GetStage()] = shaderKey;
		}

		bool ShaderProgram::Link()
		{
			program = glCreateProgram();
			for (auto& shaderKey : shaderKeys)
			{
				if (shaderKey.resourceId != INVALID_RESOURCE)
				{
					const auto shader = Engine::ResourceManager::Get<Shader>(shaderKey);
					if (shader != nullptr)
						glAttachShader(program, shader->GetHandle());
				}
			}

			glLinkProgram(program);

			int success = GL_TRUE;
			glGetProgramiv(program, GL_LINK_STATUS, &success);
			if (success == GL_FALSE)
			{
				int infoLogLength = 0;
				glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

				delete[] lastError;
				lastError = new char[(size_t)infoLogLength + 1];
				glGetProgramInfoLog(program, infoLogLength, nullptr, lastError);
				return false;
			}
			return true;
		}

		void ShaderProgram::Bind()
		{
			assert(program > 0 && "Invalid shader program");
			glUseProgram(program);
		}

		int ShaderProgram::GetUniform(const char* name)
		{
			return glGetUniformLocation(program, name);
		}

		bool ShaderProgram::BindUniform(std::string name, int value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniform1i(uniformLocation, value);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, float value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniform1f(uniformLocation, value);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, const glm::vec2& value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniform2f(uniformLocation, value.x, value.y);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, const glm::vec3& value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniform3f(uniformLocation, value.x, value.y, value.z);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, const glm::vec4& value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniform4f(uniformLocation, value.x, value.y, value.z, value.w);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, const glm::mat2& value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniformMatrix2fv(uniformLocation, 1, GL_FALSE, &value[0][0]);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, const glm::mat3& value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniformMatrix3fv(uniformLocation, 1, GL_FALSE, &value[0][0]);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, const glm::mat4& value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &value[0][0]);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, int* value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniform1iv(uniformLocation, count, value);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, float* value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniform1fv(uniformLocation, count, value);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, const glm::vec2* value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniform2fv(uniformLocation, count, (float*)value);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, const glm::vec3* value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniform3fv(uniformLocation, count, (float*)value);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, const glm::vec4* value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniform4fv(uniformLocation, count, (float*)value);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, const glm::mat2* value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniformMatrix2fv(uniformLocation, count, GL_FALSE, (float*)value);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, const glm::mat3* value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniformMatrix3fv(uniformLocation, count, GL_FALSE, (float*)value);
			return returnValue;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, const glm::mat4* value)
		{
			int uniformLocation;
			bool returnValue = VerifyProgram(name, uniformLocation);
			glUniformMatrix4fv(uniformLocation, count, GL_FALSE, (float*)value);
			return returnValue;
		}

		bool ShaderProgram::Load(const Engine::ResourceDirectories& directories)
		{
			for (size_t i = 1; i < static_cast<int>(SHADER_STAGE_COUNT); i++)
			{
				if (i-1 < directories.size())
				{
					if (directories[i - 1].empty())
						continue;
					//Engine::ResourceManager::Load<Shader>({ std::to_string(i), directories[i - 1] });
					this->LoadShader((int)i, directories[i - 1].c_str());
				}
			}
			LinkToCallback<>(GraphicsModule::OnOpenGLLoad, Engine::Engine::GetCondition("OpenGL.Load"));
			return true;
		}

		void ShaderProgram::VerifyProgram(int ID)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
		}

		bool ShaderProgram::VerifyProgram(const std::string& name, int& uniformLocation)
		{
			assert(program > 0 && "Invalid shader program");
			uniformLocation = glGetUniformLocation(program, name.c_str());
			if (uniformLocation < 0)
			{
				//printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			return true;
		}

		void ShaderProgram::BindUniform(int ID, int value)
		{
			VerifyProgram(ID);
			glUniform1i(ID, value);
		}

		void ShaderProgram::BindUniform(int ID, float value)
		{
			VerifyProgram(ID);
			glUniform1f(ID, value);
		}

		void ShaderProgram::BindUniform(int ID, const glm::vec2& value)
		{
			VerifyProgram(ID);
			glUniform2f(ID, value.x, value.y);
		}

		void ShaderProgram::BindUniform(int ID, const glm::vec3& value)
		{
			VerifyProgram(ID);
			glUniform3f(ID, value.x, value.y, value.z);
		}

		void ShaderProgram::BindUniform(int ID, const glm::vec4& value)
		{
			VerifyProgram(ID);
			glUniform4f(ID, value.x, value.y, value.z, value.w);
		}

		void ShaderProgram::BindUniform(int ID, const glm::mat2& value)
		{
			VerifyProgram(ID);
			glUniformMatrix2fv(ID, 1, GL_FALSE, &value[0][0]);
		}

		void ShaderProgram::BindUniform(int ID, const glm::mat3& value)
		{
			VerifyProgram(ID);
			glUniformMatrix3fv(ID, 1, GL_FALSE, &value[0][0]);
		}

		void ShaderProgram::BindUniform(int ID, const glm::mat4& value)
		{
			VerifyProgram(ID);
			glUniformMatrix4fv(ID, 1, GL_FALSE, &value[0][0]);
		}

		void ShaderProgram::BindUniform(int ID, int count, int* value)
		{
			VerifyProgram(ID);
			glUniform1iv(ID, count, value);
		}

		void ShaderProgram::BindUniform(int ID, int count, float* value)
		{
			VerifyProgram(ID);
			glUniform1fv(ID, count, value);
		}

		void ShaderProgram::BindUniform(int ID, int count, const glm::vec2* value)
		{
			VerifyProgram(ID);
			glUniform2fv(ID, count, (float*)value);
		}

		void ShaderProgram::BindUniform(int ID, int count, const glm::vec3* value)
		{
			VerifyProgram(ID);
			glUniform3fv(ID, count, (float*)value);
		}

		void ShaderProgram::BindUniform(int ID, int count, const glm::vec4* value)
		{
			VerifyProgram(ID);
			glUniform4fv(ID, count, (float*)value);
		}

		void ShaderProgram::BindUniform(int ID, int count, const glm::mat2* value)
		{
			VerifyProgram(ID);
			glUniformMatrix2fv(ID, count, GL_FALSE, (float*)value);
		}

		void ShaderProgram::BindUniform(int ID, int count, const glm::mat3* value)
		{
			VerifyProgram(ID);
			glUniformMatrix3fv(ID, count, GL_FALSE, (float*)value);
		}

		void ShaderProgram::BindUniform(int ID, int count, const glm::mat4* value)
		{
			VerifyProgram(ID);
			glUniformMatrix4fv(ID, count, GL_FALSE, (float*)value);
		}
	}
}