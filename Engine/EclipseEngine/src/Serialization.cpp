#include <pch.h>
#include "Serialization.h"
#include "Core.h"
#include <fstream>

namespace Eclipse
{
	namespace Engine
	{
		auto Serialization::LoadRawData(const std::string& name) -> const char*
		{
			// file pointer
			FILE* fp;
			// file content.
			char* content = nullptr;

			int count = 0;

			if (name.c_str() != nullptr) {
				// open file
				fopen_s(&fp, name.c_str(), "rt");

				if (fp != nullptr) {
					// seek to the end.
					fseek(fp, 0, SEEK_END);
					count = ftell(fp);
					rewind(fp);

					if (count > 0) {
						// create the correct buffer size
						content = (char*)malloc(sizeof(char) * (count + 1));
						count = fread(content, sizeof(char), count, fp);
						content[count] = '\0';
					}
					// close the file
					fclose(fp);
				}
			}
			return content;
		}

		auto Serialization::LoadData(const std::string& name) -> std::vector<char>
		{
			std::ifstream file(name, std::ios::binary | std::ios::ate);
			std::streamsize size = file.tellg();
			file.seekg(0, std::ios::beg);

			std::vector<char> buffer(size);
			if (file.good())
			{
				if (!file.read(buffer.data(), size))
				{
					External::Debug::DebugAPI::Error(("Failed to read file: " + name).c_str());
				}
			}
			return buffer;
		}

		auto Serialization::SaveData(const std::string& name, const std::vector<char*>& data) -> void
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