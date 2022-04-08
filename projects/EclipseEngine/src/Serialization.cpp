#include <pch.h>
#include "Serialization.h"
#include "Eclipse.h"
#include <fstream>

namespace Eclipse
{
	namespace Engine
	{
		auto Serialization::LoadRawData(const std::string& name) -> std::vector<char>
		{
			std::ifstream file(name, std::ios::binary | std::ios::ate);
			std::streamsize size = file.tellg();
			file.seekg(0, std::ios::beg);

			std::vector<char> buffer(size);
			if (file.good())
			{
				if (!file.read(buffer.data(), size))
				{
					Core::Debug::Error(("Failed to read file: " + name).c_str());
				}
			}
			return buffer;
		}

		auto Serialization::SaveRawData(const std::string& name, const std::vector<char*>& data) -> void
		{
			std::ofstream file(name, std::ios::out | std::ios::binary);
			if (file)
			{
				for (char* byte : data)
				{
					if (byte)
						file << byte;
				}
			}
			file.close();
		}
	}
}