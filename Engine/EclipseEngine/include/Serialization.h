#pragma once
#include <string>
#include <vector>

namespace Eclipse
{
	namespace Engine
	{
		class Serialization
		{
		public:

			/// <summary>
			/// Loads raw data from a file into memory.
			/// </summary>
			static auto LoadRawData(const std::string& name) -> const char*;
			/// <summary>
			/// Loads data from a file into a vector of char's into memory
			/// </summary>
			static auto LoadData(const std::string& name) -> std::vector<char>;
			/// <summary>
			/// Saves an std::vector<char> to a file.
			/// </summary>
			static auto SaveData(const std::string& name, const std::vector<char*>& data) -> void;
		};
	}
}
