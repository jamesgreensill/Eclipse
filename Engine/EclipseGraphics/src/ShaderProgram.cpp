#include "ShaderProgram.h"

#include <cstdio>
#include <glad/glad.h>

#include <EclipseEngine/include/Core.h>

namespace Eclipse
{
	namespace Graphics
	{
		std::unordered_map<std::string, ShaderProgram*> ShaderProgram::ShaderPrograms = {};

		ShaderProgram::~ShaderProgram()
		{
			delete[] lastError;
			glDeleteProgram(program);
		}

		ShaderProgram* ShaderProgram::LoadShaderProgram(const char* vertex, const char* fragment,
			const char* shaderProgramName)
		{
			assert(vertex && fragment && shaderProgramName);

			const auto shaderProgram = new ShaderProgram();
			if (!shaderProgram)
			{
				return shaderProgram;
			}

			shaderProgram->LoadShader(VERTEX, (std::string(vertex)).c_str());
			shaderProgram->LoadShader(FRAGMENT, (std::string(fragment)).c_str());

			if (!shaderProgram->Link())
			{
				External::Debug::DebugAPI::Debug(shaderProgram->GetLastError());
				return nullptr;
			}

			shaderProgram->shaderProgramName = std::string(shaderProgramName);

			ShaderPrograms.emplace(std::string(shaderProgramName), shaderProgram);
			return shaderProgram;
		}

		ShaderProgram* ShaderProgram::GetShaderProgram(const char* shaderProgramName)
		{
			return ShaderPrograms.at(std::string(shaderProgramName));
		}

		bool ShaderProgram::LoadShader(unsigned int stage, const char* filename)
		{
			assert(stage > 0 && stage < ShaderStage::SHADER_STAGE_Count);
			shaders[stage] = std::make_shared<Shader>();
			return shaders[stage]->LoadShader(stage, filename);
		}

		bool ShaderProgram::CreateShader(unsigned int stage, const char* string)
		{
			assert(stage > 0 && stage < ShaderStage::SHADER_STAGE_Count);
			shaders[stage] = std::make_shared<Shader>();
			return shaders[stage]->CreateShader(stage, string);
		}

		void ShaderProgram::AttachShader(const std::shared_ptr<Shader>& shader)
		{
			assert(shader != nullptr);
			shaders[shader->GetStage()] = shader;
		}

		bool ShaderProgram::Link()
		{
			program = glCreateProgram();
			for (auto& s : shaders)
				if (s != nullptr)
					glAttachShader(program, s->GetHandle());
			glLinkProgram(program);

			int success = GL_TRUE;
			glGetProgramiv(program, GL_LINK_STATUS, &success);
			if (success == GL_FALSE)
			{
				int infoLogLength = 0;
				glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

				delete[] lastError;
				lastError = new char[infoLogLength + 1];
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
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniform1i(i, value);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, float value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniform1f(i, value);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, const glm::vec2& value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniform2f(i, value.x, value.y);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, const glm::vec3& value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniform3f(i, value.x, value.y, value.z);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, const glm::vec4& value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniform4f(i, value.x, value.y, value.z, value.w);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, const glm::mat2& value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniformMatrix2fv(i, 1, GL_FALSE, &value[0][0]);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, const glm::mat3& value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniformMatrix3fv(i, 1, GL_FALSE, &value[0][0]);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, const glm::mat4& value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniformMatrix4fv(i, 1, GL_FALSE, &value[0][0]);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, int* value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniform1iv(i, count, value);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, float* value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniform1fv(i, count, value);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, const glm::vec2* value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniform2fv(i, count, (float*)value);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, const glm::vec3* value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniform3fv(i, count, (float*)value);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, const glm::vec4* value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniform4fv(i, count, (float*)value);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, const glm::mat2* value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniformMatrix2fv(i, count, GL_FALSE, (float*)value);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, const glm::mat3* value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniformMatrix3fv(i, count, GL_FALSE, (float*)value);
			return true;
		}

		bool ShaderProgram::BindUniform(std::string name, int count, const glm::mat4* value)
		{
			assert(program > 0 && "Invalid shader program");
			int i = glGetUniformLocation(program, name.c_str());
			if (i < 0)
			{
				printf("Shader uniform [%s] not found! Is it being used?\n", name.c_str());
				return false;
			}
			glUniformMatrix4fv(i, count, GL_FALSE, (float*)value);
			return true;
		}

		void ShaderProgram::BindUniform(int ID, int value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniform1i(ID, value);
		}

		void ShaderProgram::BindUniform(int ID, float value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniform1f(ID, value);
		}

		void ShaderProgram::BindUniform(int ID, const glm::vec2& value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniform2f(ID, value.x, value.y);
		}

		void ShaderProgram::BindUniform(int ID, const glm::vec3& value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniform3f(ID, value.x, value.y, value.z);
		}

		void ShaderProgram::BindUniform(int ID, const glm::vec4& value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniform4f(ID, value.x, value.y, value.z, value.w);
		}

		void ShaderProgram::BindUniform(int ID, const glm::mat2& value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniformMatrix2fv(ID, 1, GL_FALSE, &value[0][0]);
		}

		void ShaderProgram::BindUniform(int ID, const glm::mat3& value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniformMatrix3fv(ID, 1, GL_FALSE, &value[0][0]);
		}

		void ShaderProgram::BindUniform(int ID, const glm::mat4& value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniformMatrix4fv(ID, 1, GL_FALSE, &value[0][0]);
		}

		void ShaderProgram::BindUniform(int ID, int count, int* value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniform1iv(ID, count, value);
		}

		void ShaderProgram::BindUniform(int ID, int count, float* value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniform1fv(ID, count, value);
		}

		void ShaderProgram::BindUniform(int ID, int count, const glm::vec2* value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniform2fv(ID, count, (float*)value);
		}

		void ShaderProgram::BindUniform(int ID, int count, const glm::vec3* value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniform3fv(ID, count, (float*)value);
		}

		void ShaderProgram::BindUniform(int ID, int count, const glm::vec4* value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniform4fv(ID, count, (float*)value);
		}

		void ShaderProgram::BindUniform(int ID, int count, const glm::mat2* value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniformMatrix2fv(ID, count, GL_FALSE, (float*)value);
		}

		void ShaderProgram::BindUniform(int ID, int count, const glm::mat3* value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniformMatrix3fv(ID, count, GL_FALSE, (float*)value);
		}

		void ShaderProgram::BindUniform(int ID, int count, const glm::mat4* value)
		{
			assert(program > 0 && "Invalid shader program");
			assert(ID >= 0 && "Invalid shader uniform");
			glUniformMatrix4fv(ID, count, GL_FALSE, (float*)value);
		}
	}
}