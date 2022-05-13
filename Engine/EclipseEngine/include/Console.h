#pragma once
#include <string>
#include <sstream>

namespace Eclipse
{
	namespace Engine
	{
		//enum class ConsoleColor
		//{
		//	GREY,
		//	BRIGHT_GREY,
		//	RED,
		//	BRIGHT_RED,
		//	GREEN,
		//	BRIGHT_GREEN,
		//	BLUE,
		//	BRIGHT_BLUE,
		//	MAGENTA,
		//	BRIGHT_MAGENTA,
		//	CYAN,
		//	BRIGHT_CYAN,
		//	WHITE,
		//	BRIGHT_WHITE
		//};

		class Console
		{
		public:
			// not implemented yet
			// static ConsoleColor ForegroundColor;
			// static ConsoleColor BackgroundColor;

			static void WriteLine(const std::stringstream& message);
			static void Write(const std::string& message);

			static int Read();
			static char ReadKey();
			static std::string ReadLine();

			static void ConsoleBeep();
			static void ConsoleBeep(int32_t, int32_t);

			static void ResetColor();
		private:
			//static ConsoleColor _defaultColor;
		};
	}
}