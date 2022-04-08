#pragma once
#include <string>

namespace Eclipse {
	namespace Rendering
	{
		// simplified render pipeline shader stages
		enum ShaderStage : unsigned int {
			UNDEFINED = 0,

			VERTEX,
			GEOMETRY,
			FRAGMENT,

			SHADER_STAGE_Count,
		};

		// individual sharable shader stages
		class Shader {
		public:

			Shader() : shaderStage(0), shaderHandle(0), lastShaderError(nullptr) {}
			Shader(unsigned int stage, const char* filename)
				: shaderStage(0), shaderHandle(0), lastShaderError(nullptr) {
				LoadShader(stage, filename);
			}
			~Shader();

			bool LoadShader(unsigned int stage, const char* path);
			bool CreateShader(unsigned int stage, const char* string);

			unsigned int GetStage() const { return shaderStage; }
			unsigned int GetHandle() const { return shaderHandle; }

			const char* GetLastError() const { return lastShaderError; }

			std::string shaderName;

		protected:
			unsigned int shaderStage;
			unsigned int shaderHandle;
			char* lastShaderError;
		};
	}
}
