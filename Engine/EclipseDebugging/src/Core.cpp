#include "Core.h"

#include <EclipseEngine/include/Core.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <termcolor/termcolor.hpp>

namespace Eclipse
{
	namespace Debug
	{

		// Returns the current time in a Y-M-D-H-M-S format.
		std::string GetTime()
		{
			// I C U
			// why did i comment ICU - 3/7/2022 - james.
			// I still have no clue why i wrote I C U - 3/17/2022 - james.
			// Still have 0 recollection of why i commented I C U - 3/23/2022 - james.
			// ¯\_(ツ)_/¯
			time_t now = time(nullptr);
			tm timeStruct{};
			char buffer[80];
			localtime_s(&timeStruct, &now);

			strftime(buffer, sizeof(buffer), "%Y-%m-%d.%X", &timeStruct);

			return buffer;
		}

		void Log(const char* str)
		{
			// TODO: Add a safety check to check if there is a console process.

			std::cout << termcolor::green << "[LOG] " << GetTime() << termcolor::green << " " << str << termcolor::reset << std::endl;
		}

		void Debug(const char* str)
		{
			std::cout << termcolor::yellow << "[DEBUG] " << GetTime() << termcolor::green << " " << str << termcolor::reset << std::endl;
		}

		void Error(const char* str)
		{
			std::cout << termcolor::red << "[ERROR] " << GetTime() << str << termcolor::reset << std::endl;
		}

		void NotImplemented(const char* functionName)
		{
			Error((std::string(functionName) + " has not been implemented.").c_str());
			throw std::invalid_argument(std::string(functionName) + " has not been implemented.");
		}
	}
}