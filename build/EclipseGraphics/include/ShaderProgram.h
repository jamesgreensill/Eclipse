#pragma once
#include <memory>

#include "Shader.h"
#include "glm/glm.hpp"

namespace Eclipse
{
	namespace Rendering
	{
		class Shader;
		class ShaderProgram
		{
		public:

			ShaderProgram() : program(0), lastError(nullptr) {
				shaders[0] = shaders[1] = shaders[2] = shaders[3] = nullptr;
			}
			~ShaderProgram();

			bool LoadShader(unsigned int stage, const char* filename);
			bool CreateShader(unsigned int stage, const char* string);
			void AttachShader(const std::shared_ptr<Shader>& shader);

			bool Link();

			const char* GetLastError() const { return lastError; }

			void Bind();

			unsigned int GetHandle() const { return program; }

			int GetUniform(const char* name);

			void BindUniform(int ID, int value);
			void BindUniform(int ID, float value);
			void BindUniform(int ID, const glm::vec2& value);
			void BindUniform(int ID, const glm::vec3& value);
			void BindUniform(int ID, const glm::vec4& value);
			void BindUniform(int ID, const glm::mat2& value);
			void BindUniform(int ID, const glm::mat3& value);
			void BindUniform(int ID, const glm::mat4& value);
			void BindUniform(int ID, int count, int* value);
			void BindUniform(int ID, int count, float* value);
			void BindUniform(int ID, int count, const glm::vec2* value);
			void BindUniform(int ID, int count, const glm::vec3* value);
			void BindUniform(int ID, int count, const glm::vec4* value);
			void BindUniform(int ID, int count, const glm::mat2* value);
			void BindUniform(int ID, int count, const glm::mat3* value);
			void BindUniform(int ID, int count, const glm::mat4* value);

			// these calls should be avoided, but wraps up opengl a little
			bool BindUniform(std::string name, int value);
			bool BindUniform(std::string name, float value);
			bool BindUniform(std::string name, const glm::vec2& value);
			bool BindUniform(std::string name, const glm::vec3& value);
			bool BindUniform(std::string name, const glm::vec4& value);
			bool BindUniform(std::string name, const glm::mat2& value);
			bool BindUniform(std::string name, const glm::mat3& value);
			bool BindUniform(std::string name, const glm::mat4& value);
			bool BindUniform(std::string name, int count, int* value);
			bool BindUniform(std::string name, int count, float* value);
			bool BindUniform(std::string name, int count, const glm::vec2* value);
			bool BindUniform(std::string name, int count, const glm::vec3* value);
			bool BindUniform(std::string name, int count, const glm::vec4* value);
			bool BindUniform(std::string name, int count, const glm::mat2* value);
			bool BindUniform(std::string name, int count, const glm::mat3* value);
			bool BindUniform(std::string name, int count, const glm::mat4* value);
			std::string shaderProgramName;

			unsigned int GetProgram() { return program; };

		private:

			unsigned int program;
			std::shared_ptr<Shader> shaders[SHADER_STAGE_Count];
			char* lastError;
		};
	}
}
