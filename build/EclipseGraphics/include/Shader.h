#pragma once
#include <string>

#include <EclipseEngine/include/Resource.h>

namespace Eclipse {
	namespace Graphics
	{
		// simplified render pipeline shader stages
		enum ShaderStage : unsigned int {
			UNDEFINED = 0,

			VERTEX,
			GEOMETRY,
			FRAGMENT,

			SHADER_STAGE_COUNT,
		};

		// individual sharable shader stages
		class Shader : public Engine::Resource
		{
		public:

			Shader() : shaderStage(0), shaderHandle(0), lastShaderError(nullptr) {}
			Shader(unsigned int stage, const char* filename)
				: shaderStage(0), shaderHandle(0), lastShaderError(nullptr) {
				LoadShader(stage, filename);
			}
			~Shader();

			// deprecated.
			void LoadShader(unsigned int stage, const char* path);

			unsigned int GetStage() const { return shaderStage; }
			unsigned int GetHandle() const { return shaderHandle; }

			const char* GetLastError() const { return lastShaderError; }
			std::string shaderName;

			
			/// <summary>
			///	Load shader from file.
			/// </summary>
			bool Load(const Engine::ResourceDirectories& directories) override;

			/// <summary>
			///	Link shader with openGL.
			/// </summary>
			bool Setup() override;

		protected:
			unsigned int shaderStage;
			unsigned int shaderHandle;
			char* lastShaderError;

		private:

			const char* data = nullptr;
			//std::vector<char> data = {};
		};
	}
}
