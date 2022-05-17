#pragma once
#include <string>
#include <sstream>

#include <Windows.h>

namespace Eclipse
{
	namespace Engine
	{
		class Console
		{
		public:
			static void WriteLine(const std::stringstream& message);
			static void WriteLine(const std::string& message);
			static void Write(const std::string& message);

			static int Read();
			static char ReadKey();
			static std::string ReadLine();

			static void ConsoleBeep();
			static void ConsoleBeep(int32_t, int32_t);

			static void ResetColor();
		private:
			static HWND Handle;
			static HWND GetHandle();
		};
	}
}