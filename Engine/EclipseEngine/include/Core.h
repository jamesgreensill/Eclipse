/*

	Author: James Greensill.

*/
#pragma once

/*
 *
 *	TODO: Move relevant vendors to EclipseGraphics.
 *
 */
#include "glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <vcruntime_typeinfo.h>

#include "EngineMacros.h"

 // Forward Declarations for GLFW.
struct GLFWwindow;
struct GLFWmonitor;

// m_Type Definitions for GLFW

/*

	I am aware this seems overkill, however I want to explore typedef's & cleaning up confusing code from rather obscure Libraries.
	As I am only using GLFW, I believe simplifying the class names to remove GLFW is acceptable. - James.
	I will probably remove this to create a custom Window class. but ¯\_(ツ)_/¯

*/

namespace Eclipse {
	namespace Engine
	{
		class Application;
	}

	namespace Core
	{
		namespace Data
		{
			struct CoreData
			{
				struct
				{
					GLFWwindow* currentContext = nullptr;

					/*
					 *
					 *	TODO: UPDATE THESE TO SCALE WITH SCREEN SIZE.
					 *
					 */
					bool fullscreen = false;
					int screenHeight = 0;
					int screenWidth = 0;

					int screenPosX = 0;
					int screenPosY = 0;
				} Window;

				struct
				{
					int exitKey;
				} Keyboard;

				struct
				{
					double lastMouseX = 0;
					double lastMouseY = 0;

					double deltaMouseX = 0;
					double deltaMouseY = 0;
					double deltaScrollX = 0;
					double deltaScrollY = 0;

					bool cursorHidden = false;
				} Mouse;
			};
			extern CoreData CORE;

			/// <summary>
			/// Custom Color structure.
			/// </summary>
			struct ECC {
				unsigned int r;
				unsigned int g;
				unsigned int b;
				unsigned int a;
			};
		}

		// Window Functions
		// TODO: Order these in priorty future james

		namespace Window
		{
			ECAPI auto BeginDrawing() -> void;
			ECAPI auto EndDrawing() -> void;
			ECAPI auto ClearBackground(float r, float g, float b, float a) -> void;
			ECAPI auto ClearBackground(Data::ECC) -> void;

			/// <summary>
			/// Returns true if the Window should close.
			/// </summary>
			ECAPI auto WindowShouldTerminate(Engine::Application*) -> bool;
			/// <summary>
			/// Initializes and creates a new Window.
			/// </summary>
			ECAPI auto InitWindow(int width, int height, const char* title, GLFWmonitor* = nullptr,
				GLFWwindow* = nullptr)->GLFWwindow*;
			/// <summary>
			/// Closes the current Window context.
			/// </summary>
			ECAPI auto CloseWindow() -> void;
			/// <summary>
			/// returns true if the current Window is ready.
			/// </summary>
			ECAPI auto IsWindowReady() -> bool;
			/// <summary>
			/// returns true if the current Window context is in fullscreen mode.
			/// </summary>
			ECAPI auto IsWindowFullscreen() -> bool;
			/// <summary>
			/// returns true if the current Window context is hidden.
			/// </summary>
			ECAPI auto IsWindowHidden() -> bool;
			/// <summary>
			/// reutrns true if the current Window context is minimized.
			/// </summary>
			ECAPI auto IsWindowMinimized() -> bool;
			/// <summary>
			/// returns true if the current Window context is maximized.
			/// </summary>
			ECAPI auto IsWindowMaximized() -> bool;
			/// <summary>
			/// returns true if the current Window context is focused.
			/// </summary>
			ECAPI auto IsWindowFocused() -> bool;
			/// <summary>
			/// returns true if the current Window context is reized in this frame.
			/// </summary>
			ECAPI auto IsWindowResized() -> bool;
			/// <summary>
			/// returns true if the current Window state is equal to the flag parameters.
			/// </summary>
			ECAPI auto IsWindowState(unsigned int flags) -> bool;
			/// <summary>
			/// sets the current Window state to the flag parameters.
			/// </summary>
			ECAPI auto SetWindowState(unsigned int flags) -> void;
			ECAPI auto ClearWindowState(unsigned int flags) -> void;
			ECAPI auto SetFullscreen(bool flag) -> void;
			ECAPI auto MaximizeWindow(void) -> void;
			ECAPI auto MinimizeWindow(void) -> void;
			ECAPI auto RestoreWindow(void) -> void;
			ECAPI auto SetWindowTitle(const char*) -> void;
			ECAPI auto SetWindowPosition(int x, int y) -> void;
			ECAPI auto SetWindowPosition(glm::vec2 point) -> void;
			ECAPI auto SetWindowMonitor(int monitor) -> void;
			ECAPI auto SetWindowMinSize(int x, int y) -> void;
			ECAPI auto SetWindowMinSize(glm::vec2 size) -> void;
			ECAPI auto SetWindowMaxSize(int, int) -> void;
			ECAPI auto SetWindowMaxSize(glm::vec2 size) -> void;
			ECAPI auto SetWindowSize(int, int) -> void;
			ECAPI auto SetWindowSize(glm::vec2) -> void;
			ECAPI auto GetWindowHandle(void) -> void*;
			ECAPI auto GetScreenWidth(void) -> int;
			ECAPI auto GetScreenHeight(void) -> int;
			ECAPI auto GetScreenSize(void)->glm::vec2;
			ECAPI auto GetScreenSize1D(void) -> int;
			ECAPI auto GetBufferWidth(void) -> int;
			ECAPI auto GetBufferHeight(void) -> int;
			ECAPI auto GetBufferSize1D(void) -> int;
			ECAPI auto GetBufferSize(void)->glm::vec2;
			ECAPI auto GetMonitorCount(void) -> int;
			ECAPI auto GetCurrentMonitor(void) -> int;
			ECAPI auto GetMonitorRefreshRate(int monitor) -> int;
			ECAPI auto GetWindowPosition(void)->glm::vec2;
			ECAPI auto GetWindowScaleDPI(void)->glm::vec2;
			ECAPI auto GetMonitorName(int monitor) -> const char*;
			ECAPI auto SetClipboardText(const char* text) -> void;
			ECAPI auto GetClipboardText(void) -> const char*;
			ECAPI auto ShowCursor(bool) -> void;
			ECAPI auto HideCursor(void) -> void;
			ECAPI auto IsCursorHidden(void) -> bool;
			ECAPI auto EnableCursor(void) -> void;
			ECAPI auto DisableCursor(void) -> void;
			ECAPI auto IsCursorOnScreen(void) -> bool;
			ECAPI auto SetWindowOpacity(float alpha) -> void;
			ECAPI auto GetWindowOpacity(void) -> float;

			ECAPI auto MouseCallback(GLFWwindow* window, double xPosIn, double yPosIn) -> void;
			ECAPI auto FrameBufferSizeCallback(GLFWwindow* window, int width, int height) -> void;
			ECAPI auto WindowSizeCallback(GLFWwindow* window, int width, int height) -> void;
			ECAPI auto ScrollCallback(GLFWwindow* window, double xOffset, double yOffset) -> void;
			ECAPI auto WindowFocusCallback(GLFWwindow* window, int focused) -> void;
			ECAPI auto WindowRefreshCallback(GLFWwindow* window) -> void;

			ECAPI auto LoadCallbacks(GLFWwindow* window) -> void;
		}

		namespace Input
		{
			/// <summary>
			/// Input Functions: KB
			/// </summary>
			ECAPI auto GetExitKey()->int;
			ECAPI auto GetKeyPressed()->int;
			ECAPI auto GetCharPressed()-> int;
			ECAPI auto IsKeyUp(int keyCode)-> bool;
			ECAPI auto IsKeyDown(int keyCode)-> bool;
			ECAPI auto SetExitKey(int keyCode)-> void;
			ECAPI auto IsKeyPressed(int keyCode)-> bool;

			ECAPI auto GetMouse()->glm::vec2;
			ECAPI auto GetMouseY(void)->int;
			ECAPI auto GetMouseX(void)->int;
			ECAPI auto IsMouseUp(int mouseCode)->bool;
			ECAPI auto IsMouseDown(int mouseCode)->bool;
			ECAPI auto IsMouseReleased(int mouseCode)->bool;

			ECAPI auto GetMouseDelta()->glm::vec2;
			ECAPI auto GetScrollDelta()->glm::vec2;
			ECAPI auto GetMouseDeltaX()->float;
			ECAPI auto GetMouseDeltaY()->float;
			ECAPI auto GetScrollDeltaY()->float;
			ECAPI auto GetScrollDeltaX()->float;
		}

		namespace IO
		{
			ECAPI auto GetCurrentDirectory()->std::string;
			ECAPI auto GetFileNameFromPath(const char* path)->std::string;
		}

		namespace Types
		{
			template<typename T>
			ECAPI auto IsTypeOf(const std::type_info& info) -> bool
			{
				if (typeid(T) == info)
					return true;
				return false;
			}
		}

#pragma endregion
	}

	namespace Utilities
	{
		ECAPI auto GetTime()->std::string;
	}

	namespace External
	{
		namespace Graphics
		{
			class GraphicsAPI
			{
			public:
				static ECAPI std::function<void(int, int, unsigned int, unsigned int)> Viewport_Pointer;
				static inline ECAPI void Viewport(int x, int y, unsigned int width, unsigned int height) { if (Viewport_Pointer) { Viewport_Pointer(x,y,width,height); } }
			};
		}

		namespace Debug
		{
			class DebugAPI
			{
			public:
				static ECAPI std::function<void(const char*)> Debug_Pointer;
				static ECAPI void Debug(const char* message)
				{
					if (Debug_Pointer) { Debug_Pointer(message); }
					else std::cout << message << std::endl;
				}
				static ECAPI std::function<void(const char*)> Error_Pointer;
				static ECAPI void Error(const char* message)
				{
					if (Error_Pointer) { Error_Pointer(message); }
					else std::cout << message << std::endl;
				}
				static ECAPI std::function<void(const char*)> Log_Pointer;
				static ECAPI void Log(const char* message)
				{
					if (Log_Pointer) { Log_Pointer(message); }
					else std::cout << message << std::endl;
				}
			};
		}
		namespace Test
		{
			class TestAPI
			{
			public:
				EX_FUNCTION_DEC_nV(TestCall, void, void, void);
			};
		}
	}
}
