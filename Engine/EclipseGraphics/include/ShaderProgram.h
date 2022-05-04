#pragma once
#include <glm/glm.hpp>
#include "Shader.h"


namespace Eclipse
{
	namespace Graphics
	{
		class Shader;
		class ShaderProgram : public Engine::Resource
		{
		public:
			/// <summary>
			/// Load entire shader program from file
			/// </summary>
			bool Load(const Engine::ResourceDirectories& directories) override;
			/// <summary>
			///	Link shader program to OpenGL.
			/// </summary>
			bool Setup() override;
			/// <summary>
			///	Load Shader into Resource Manager.
			/// </summary>
			void LoadShader(unsigned int stage, const char* filename);
			/// <summary>
			///	Attach an external shader to this shader program.
			/// </summary>
			void AttachShader(const Engine::ResourceKey& shaderKey);
			/// <summary>
			///	Link this shader to OpenGL.
			/// </summary>
			bool Link();
			/// <summary>
			///	Get the last error of this shader program.
			/// </summary>
			const char* GetLastError() const { return lastError; }
			/// <summary>
			///	Bind this shader to use in the render pipeline.
			/// </summary>
			void Bind();
			/// <summary>
			///	Get the handle of this shader program.
			/// </summary>
			unsigned int GetHandle() const { return program; }
			/// <summary>
			///	Get the specified uniform value.
			/// </summary>
			int GetUniform(const char* name);
			/// <summary>
			///	Bind Int Uniform
			/// </summary>
			void BindUniform(int ID, int value);
			/// <summary>
			///	Bind float Uniform
			/// </summary>
			void BindUniform(int ID, float value);
			/// <summary>
			///	Bind vec2 Uniform
			/// </summary>
			void BindUniform(int ID, const glm::vec2& value);
			/// <summary>
			///	Bind vec3 Uniform
			/// </summary>
			void BindUniform(int ID, const glm::vec3& value);
			/// <summary>
			///	Bind vec4 Uniform
			/// </summary>
			void BindUniform(int ID, const glm::vec4& value);
			/// <summary>
			///	Bind mat2x2 Uniform
			/// </summary>
			void BindUniform(int ID, const glm::mat2& value);
			/// <summary>
			///	Bind mat3x3 Uniform
			/// </summary>
			void BindUniform(int ID, const glm::mat3& value);
			/// <summary>
			///	Bind mat4x4 Uniform
			/// </summary>
			void BindUniform(int ID, const glm::mat4& value);
			/// <summary>
			///	Bind int* Uniform
			/// </summary>
			void BindUniform(int ID, int count, int* value);
			/// <summary>
			///	Bind float* Uniform
			/// </summary>
			void BindUniform(int ID, int count, float* value);
			/// <summary>
			///	Bind vec2* Uniform
			/// </summary>
			void BindUniform(int ID, int count, const glm::vec2* value);
			/// <summary>
			///	Bind vec3* Uniform
			/// </summary>
			void BindUniform(int ID, int count, const glm::vec3* value);
			/// <summary>
			///	Bind vec4* Uniform
			/// </summary>
			void BindUniform(int ID, int count, const glm::vec4* value);
			/// <summary>
			///	Bind mat2x2* Uniform
			/// </summary>
			void BindUniform(int ID, int count, const glm::mat2* value);
			/// <summary>
			///	Bind mat3x3* Uniform
			/// </summary>
			void BindUniform(int ID, int count, const glm::mat3* value);
			/// <summary>
			///	Bind mat4x4* Uniform
			/// </summary>
			void BindUniform(int ID, int count, const glm::mat4* value);
			// these calls should be avoided, but wraps up opengl a little
			/// <summary>
			///	Bind Int Uniform
			/// </summary>
			bool BindUniform(std::string name, int value);
			/// <summary>
			///	Bind float Uniform
			/// </summary>
			bool BindUniform(std::string name, float value);
			/// <summary>
			///	Bind vec2 Uniform
			/// </summary>
			bool BindUniform(std::string name, const glm::vec2& value);
			/// <summary>
			///	Bind vec3 Uniform
			/// </summary>
			bool BindUniform(std::string name, const glm::vec3& value);
			/// <summary>
			///	Bind vec4 Uniform
			/// </summary>
			bool BindUniform(std::string name,const glm::vec4& value);
			/// <summary>
			///	Bind mat2x2 Uniform
			/// </summary>
			bool BindUniform(std::string name,const glm::mat2& value);
			/// <summary>
			///	Bind mat3x3 Uniform
			/// </summary>
			bool BindUniform(std::string name, const glm::mat3& value);
			/// <summary>
			///	Bind mat4x4 Uniform
			/// </summary>
			bool BindUniform(std::string name, const glm::mat4& value);
			/// <summary>
			///	Bind int* Uniform
			/// </summary>
			bool BindUniform(std::string name, int count, int* value);
			/// <summary>
			///	Bind float* Uniform
			/// </summary>
			bool BindUniform(std::string name, int count, float* value);
			/// <summary>
			///	Bind vec2* Uniform
			/// </summary>
			bool BindUniform(std::string name, int count, const glm::vec2* value);
			/// <summary>
			///	Bind vec3* Uniform
			/// </summary>
			bool BindUniform(std::string name, int count, const glm::vec3* value);
			/// <summary>
			///	Bind vec4* Uniform
			/// </summary>
			bool BindUniform(std::string name, int count, const glm::vec4* value);
			/// <summary>
			///	Bind mat2x2* Uniform
			/// </summary>
			bool BindUniform(std::string name, int count, const glm::mat2* value);
			/// <summary>
			///	Bind mat3x3* Uniform
			/// </summary>
			bool BindUniform(std::string name, int count, const glm::mat3* value);
			/// <summary>
			///	Bind mat4x4* Uniform
			/// </summary>
			bool BindUniform(std::string name, int count, const glm::mat4* value);


			/// <summary>
			///	Get shader program.
			/// </summary>
			unsigned int GetProgram() const { return program; }

			ShaderProgram() : program(0), lastError(nullptr) {}
			~ShaderProgram();

		private:

			/// <summary>
			///	Verify shader program
			/// </summary>
			void VerifyProgram(int ID);
			/// <summary>
			///	Verify shader program
			/// </summary>
			auto VerifyProgram(const std::string&, int& uniformLocation) -> bool;

			Engine::ResourceKey shaderKeys[SHADER_STAGE_COUNT];

			//std::shared_ptr<Shader> shaders[SHADER_STAGE_COUNT];
			unsigned int program;
			char* lastError;
		};
	}
}
