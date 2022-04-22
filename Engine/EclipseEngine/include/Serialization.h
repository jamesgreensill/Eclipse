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
			static auto LoadRawData(const std::string& name) -> const char*;
			static auto LoadData(const std::string& name) -> std::vector<char>;
			static auto SaveData(const std::string& name, const std::vector<char*>& data) -> void;
		};
	}
}
