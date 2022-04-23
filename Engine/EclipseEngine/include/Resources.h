#pragma once

/*
 *
 *	Used for resource collections.
 *
 */
#include <map>
#include <string>


// DEPRECATED

namespace Eclipse
{
	namespace Graphics
	{
		struct Texture;
		class Model;
		class Shader;
		class ShaderProgram;
	}

	namespace Engine
	{
		struct Directories
		{
			std::string shaderDir;
			std::string dataDir;
		};

		class Resources
		{
		public:
			static auto LoadShaderProgram(const char* vertex, const char* fragment, const char* shaderProgramName)->Graphics::ShaderProgram*;
			static auto AddShaderProgram(Graphics::ShaderProgram* program) -> void;
			static auto UnloadShaderProgram(Graphics::ShaderProgram* program) ->void;
			static auto UnloadShaderProgram(const char* program) ->void;
			static auto GetShaderProgram(const char* shaderProgramName)->Graphics::ShaderProgram*;
			static auto GetDefaultShaderProgram()->Graphics::ShaderProgram*;

			static auto AddShader(Graphics::Shader* shader) -> void;
			static auto UnloadShader(Graphics::Shader* shader) -> void;
			static auto GetShader(const char* shaderName)->Graphics::Shader*;

			static auto SetDirPrefix(const std::string& key, const  std::string& value) -> void;
			static auto GetDirPrefix(const std::string& key)->std::string;
			static auto AddDirPrefix(const std::string& key, std::string value)->std::string;
			static auto RemoveDirPrefix(const std::string& key)->void;

			static auto LoadModel(const std::string& path)->Graphics::Model*;

			static auto LoadDefaultDirectories() -> void;
			static auto LoadDefaultResources() -> void;

			static auto LoadTexture(std::string path)->Graphics::Texture*;

		private:

			static Graphics::ShaderProgram* defaultShaderProgram;
			static std::map<std::string, std::string> defaultDirectories;
			static std::map<std::string, Graphics::ShaderProgram*> shaderPrograms;
			static std::map<std::string, Graphics::Shader*> shaders;
		};
	}
}
