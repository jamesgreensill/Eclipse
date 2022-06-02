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

            enum class ConsoleColor : WORD
            {
                BLACK = 0,
                DARKBLUE = FOREGROUND_BLUE,
                DARKGREEN = FOREGROUND_GREEN,
                DARKCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
                DARKRED = FOREGROUND_RED,
                DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
                DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
                DARKGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
                GRAY = FOREGROUND_INTENSITY,
                BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
                GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
                CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
                RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
                MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
                YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
                WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
            };

            static void WriteLine(const std::string& message, ConsoleColor color = ConsoleColor::WHITE);
            static void Write(const std::string& message, ConsoleColor color = ConsoleColor::WHITE);

            static int Read();
            static char ReadKey();
            static std::string ReadLine();

            static void ConsoleBeep();
            static void ConsoleBeep(int32_t, int32_t);

            static void ChangeColor(ConsoleColor color);

            static void ResetColor();
        private:
            static HANDLE GetHandle();
        };
    }
}