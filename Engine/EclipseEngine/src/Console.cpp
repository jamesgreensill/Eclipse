#include "Console.h"

#include <iostream>

#ifdef _WIN64
#include <windows.h>
#else

#endif

namespace Eclipse
{
	namespace Engine
	{
		void Console::WriteLine(const std::stringstream& message)
		{
			std::cout << message.str() << std::endl;
		}

		void Console::Write(const std::string& message)
		{
			std::cout << message;
		}

		void Console::ResetColor()
		{
			// deprecated.
		}

		int Console::Read()
		{
			return std::cin.get();
		}

		char Console::ReadKey()
		{
			return (char)std::cin.get();
		}

		std::string Console::ReadLine()
		{
			std::string line = {};
			std::getline(std::cin, line);
			return line;
		}

		void Console::ConsoleBeep()
		{
			Console::ConsoleBeep(420, 1000);
		}

		/**
		 * \brief Beeps the console at a specific frequency for a specific duration.
		 * \param frequency Not supported on Unix & Linux based OS.
		 * \param duration Not supported on Unix & Linux based OS.
		 */
		void Console::ConsoleBeep(int32_t frequency, int32_t duration)
		{
#ifdef _WIN64
			Beep(frequency, duration);
#elif __linux__
			system("echo -e "\007" >/dev/tty19");
#endif
		}
	}
}