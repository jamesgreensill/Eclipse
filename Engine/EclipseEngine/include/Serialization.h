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
			static auto LoadRawData(const std::string& name) -> std::vector<char>;
			static auto SaveRawData(const std::string& name, const std::vector<char*>& data) -> void;
		};
	}
}
