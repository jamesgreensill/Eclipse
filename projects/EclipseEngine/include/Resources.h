#pragma once

/*
 *
 *	Used for resource collections.
 *
 */
#include <map>
#include <string>

namespace Eclipse
{
	namespace Rendering
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
			static auto LoadShaderProgram(const char* vertex, const char* fragment, const char* shaderProgramName)->Rendering::ShaderProgram*;
			static auto AddShaderProgram(Rendering::ShaderProgram* program) -> void;
			static auto UnloadShaderProgram(Rendering::ShaderProgram* program) ->void;
			static auto UnloadShaderProgram(const char* program) ->void;
			static auto GetShaderProgram(const char* shaderProgramName)->Rendering::ShaderProgram*;
			static auto GetDefaultShaderProgram()->Rendering::ShaderProgram*;

			static auto AddShader(Rendering::Shader* shader) -> void;
			static auto UnloadShader(Rendering::Shader* shader) -> void;
			static auto GetShader(const char* shaderName)->Rendering::Shader*;

			static auto SetDirPrefix(const std::string& key, const  std::string& value) -> void;
			static auto GetDirPrefix(const std::string& key)->std::string;
			static auto AddDirPrefix(const std::string& key, std::string value)->std::string;
			static auto RemoveDirPrefix(const std::string& key)->void;

			static auto LoadModel(const std::string& path)->Rendering::Model*;

			static auto LoadDefaultDirectories() -> void;
			static auto LoadDefaultResources() -> void;

			static auto LoadTexture(std::string path)->Rendering::Texture*;

		private:

			static Rendering::ShaderProgram* defaultShaderProgram;
			static std::map<std::string, std::string> defaultDirectories;
			static std::map<std::string, Rendering::ShaderProgram*> shaderPrograms;
			static std::map<std::string, Rendering::Shader*> shaders;
		};
	}
}
