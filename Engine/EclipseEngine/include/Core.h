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
	I will probably remove these to create a custom Window class. but ¯\_(ツ)_/¯

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
			
			/// <summary>
			/// This function is required at the begining of a window frame.
			/// </summary>
			ECAPI auto BeginDrawing() -> void;
			/// <summary>
			/// This function is required at the end of a window frame.
			/// </summary>
			ECAPI auto EndDrawing() -> void;
			/// <summary>
			/// This function clears the background with the specified colour.
			/// </summary>
			ECAPI auto ClearBackground(float r, float g, float b, float a) -> void;
			/// <summary>
			/// This function clears the background with the specified colour.
			/// </summary>
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
			/// <summary>
			/// This function is not implemented. 
			/// It will be used for state based windowing.
			/// </summary>
			ECAPI auto ClearWindowState(unsigned int flags) -> void;
			/// <summary>
			/// This function will toggle fullscreen depending on the boolean flag.
			/// </summary>
			ECAPI auto SetFullscreen(bool flag) -> void;
			/// <summary>
			/// This function will maximize the window if it is not maximized.
			/// </summary>
			ECAPI auto MaximizeWindow(void) -> void;
			/// <summary>
			/// This function will minimize the window if it is not minimized.
			/// </summary>
			ECAPI auto MinimizeWindow(void) -> void;
			/// <summary>
			/// This function will restore the window if it is minimized.
			/// </summary>
			ECAPI auto RestoreWindow(void) -> void;
			/// <summary>
			/// This function will set the window title to the input char buffer.
			/// </summary>
			ECAPI auto SetWindowTitle(const char*) -> void;
			/// <summary>
			/// This function will set the window position on the monitor screen if it is not fullscreen.
			/// </summary>
			ECAPI auto SetWindowPosition(int x, int y) -> void;
			/// <summary>
			/// This function will set the window position on the monitor screen if it is not fullscreen.
			/// </summary>
			ECAPI auto SetWindowPosition(glm::vec2 point) -> void;
			/// <summary>
			/// This function will move the window to the input monitor.
			/// </summary>
			ECAPI auto SetWindowMonitor(int monitor) -> void;
			/// <summary>
			/// This function will set the minimum size of the window.
			/// </summary>
			ECAPI auto SetWindowMinSize(int x, int y) -> void;
			/// <summary>
			/// This function will set the minimum size of the window.
			/// </summary>
			ECAPI auto SetWindowMinSize(glm::vec2 size) -> void;
			/// <summary>
			/// This function will set the maximum size of the window.
			/// </summary>
			ECAPI auto SetWindowMaxSize(int, int) -> void;
			/// <summary>
			/// This function will set the maximum size of the window.
			/// </summary>
			ECAPI auto SetWindowMaxSize(glm::vec2 size) -> void;
			/// <summary>
			/// This function will set the window size.
			/// </summary>
			ECAPI auto SetWindowSize(int, int) -> void;
			/// <summary>
			/// This function will set the window size.
			/// </summary>
			ECAPI auto SetWindowSize(glm::vec2) -> void;
			/// <summary>
			/// This function will return the window handle.
			/// </summary>
			ECAPI auto GetWindowHandle(void) -> void*;
			/// <summary>
			/// This function will return the screen width;
			/// </summary>
			ECAPI auto GetScreenWidth(void) -> int;
			/// <summary>
			/// This function will return the screen height.
			/// </summary>
			ECAPI auto GetScreenHeight(void) -> int;
			/// <summary>
			/// This function will return the screen size in a <float,float> tuple.
			/// </summary>
			ECAPI auto GetScreenSize(void)->glm::vec2;
			/// <summary>
			/// This function will return the area of the screen.
			/// </summary>
			ECAPI auto GetScreenSize1D(void) -> int;
			/// <summary>
			/// This function will return the screen buffer width.
			/// </summary>
			ECAPI auto GetBufferWidth(void) -> int;
			/// <summary>
			/// This function will return the screen buffer height.
			/// </summary>
			ECAPI auto GetBufferHeight(void) -> int;
			/// <summary>
			/// This function will return the area of the screen buffer.
			/// </summary>
			ECAPI auto GetBufferSize1D(void) -> int;
			/// <summary>
			/// This function will return the screen buffer size in a <float, float> tuple.
			/// </summary>
			ECAPI auto GetBufferSize(void)->glm::vec2;
			/// <summary>
			/// This function will return the monitor count.
			/// </summary>
			ECAPI auto GetMonitorCount(void) -> int;
			/// <summary>
			/// This function will return the current monitor.
			/// </summary>
			ECAPI auto GetCurrentMonitor(void) -> int;
			/// <summary>
			/// This function will return the refresh rate of the specified monitor.
			/// </summary>
			ECAPI auto GetMonitorRefreshRate(int monitor) -> int;
			/// <summary>
			/// This function will return the window position on the monitor.
			/// </summary>
			ECAPI auto GetWindowPosition(void)->glm::vec2;
			/// <summary>
			/// This function will return the Scale Dots Per Pixel of the current window.
			/// </summary>
			ECAPI auto GetWindowScaleDPI(void)->glm::vec2;
			/// <summary>
			/// This function will return the model name of the monitor.
			/// </summary>
			ECAPI auto GetMonitorName(int monitor) -> const char*;
			/// <summary>
			/// This function will set the clipboard text to the specifed char buffer.
			/// </summary>
			ECAPI auto SetClipboardText(const char* text) -> void;
			/// <summary>
			/// This function will return the clipboard data.
			/// </summary>
			ECAPI auto GetClipboardText(void) -> const char*;
			/// <summary>
			/// This function will Show the cursor.
			/// </summary>
			ECAPI auto ShowCursor(bool) -> void;
			/// <summary>
			/// This function will Hide the cursor.
			/// </summary>
			ECAPI auto HideCursor(void) -> void;
			/// <summary>
			/// This function will return true if the cursor is hidden.
			/// </summary>
			ECAPI auto IsCursorHidden(void) -> bool;
			/// <summary>
			/// This function will enable cursor movement.
			/// </summary>
			ECAPI auto EnableCursor(void) -> void;
			/// <summary>
			/// This function will disable cursor movement.
			/// </summary>
			ECAPI auto DisableCursor(void) -> void;
			/// <summary>
			/// This function will return true if the cursor is on the window.
			/// </summary>
			ECAPI auto IsCursorOnScreen(void) -> bool;
			/// <summary>
			/// This function will set the opacity of the window.
			/// </summary>
			ECAPI auto SetWindowOpacity(float alpha) -> void;
			/// <summary>
			/// This function will return the opacity of the window.
			/// </summary>
			ECAPI auto GetWindowOpacity(void) -> float;
			/// <summary>
			/// This function will be called when the mouse moves.
			/// </summary>
			ECAPI auto MouseCallback(GLFWwindow* window, double xPosIn, double yPosIn) -> void;
			/// <summary>
			/// This function will be called when the buffer is resized.
			/// </summary>
			ECAPI auto FrameBufferSizeCallback(GLFWwindow* window, int width, int height) -> void;
			/// <summary>
			/// This function will be called when the window is resized.
			/// </summary>
			ECAPI auto WindowSizeCallback(GLFWwindow* window, int width, int height) -> void;
			/// <summary>
			/// This function will be called when the mouse wheel is spun.
			/// </summary>
			ECAPI auto ScrollCallback(GLFWwindow* window, double xOffset, double yOffset) -> void;
			/// <summary>
			/// This function when the window is focused or unfocused.
			/// </summary>
			ECAPI auto WindowFocusCallback(GLFWwindow* window, int focused) -> void;
			/// <summary>
			/// This function will be called when the window is refreshed.
			/// </summary>
			ECAPI auto WindowRefreshCallback(GLFWwindow* window) -> void;
			/// <summary>
			/// This function loads all the callbacks into GLFW.
			/// </summary>
			ECAPI auto LoadCallbacks(GLFWwindow* window) -> void;
		}

		namespace Input
		{
			/// <summary>
			/// Input Functions: KB
			/// </summary>
			/// <summary>
			/// This function will return the exit key.
			/// </summary>
			ECAPI auto GetExitKey()->int;
			/// <summary>
			/// This function will return the current key pressed.
			/// </summary>
			ECAPI auto GetKeyPressed()->int;
			/// <summary>
			/// This function will return the current key pressed in ASCII form.
			/// </summary>
			ECAPI auto GetCharPressed()-> int;
			/// <summary>
			/// This function will return true is the specified key is up.
			/// </summary>
			ECAPI auto IsKeyUp(int keyCode)-> bool;
			/// <summary>
			/// This function will return true if the specified key is down.
			/// </summary>
			ECAPI auto IsKeyDown(int keyCode)-> bool;
			/// <summary>
			/// This function will set the exit key to the specified key.
			/// </summary>
			ECAPI auto SetExitKey(int keyCode)-> void;
			/// <summary>
			/// This function will return true if the specified key is pressed.
			/// </summary>
			ECAPI auto IsKeyPressed(int keyCode)-> bool;
			/// <summary>
			/// This function will return the mouse position in a <float, float> tuple.
			/// </summary>
			ECAPI auto GetMouse()->glm::vec2;
			/// <summary>
			/// This function will return the mouse Y position
			/// </summary>
			ECAPI auto GetMouseY(void)->int;
			/// <summary>
			/// This function will return the mouse X position.
			/// </summary>
			ECAPI auto GetMouseX(void)->int;
			/// <summary>
			/// This function will return true if the specified mouse button is up.
			/// </summary>
			ECAPI auto IsMouseUp(int mouseCode)->bool;
			/// <summary>
			/// This function will return true if the specified mouse button is down.
			/// </summary>
			ECAPI auto IsMouseDown(int mouseCode)->bool;
			/// <summary>
			/// This function will return true if the specified mouse button is released.
			/// </summary>
			ECAPI auto IsMouseReleased(int mouseCode)->bool;
			/// <summary>
			/// This function returns the mouse delta in a <float,float> tuple.
			/// </summary>
			ECAPI auto GetMouseDelta()->glm::vec2;
			/// <summary>
			/// This function returns the scroll delta in a <float,float> tuple.
			/// </summary>
			ECAPI auto GetScrollDelta()->glm::vec2;
			/// <summary>
			/// This function returns the mouse delta x.
			/// </summary>
			ECAPI auto GetMouseDeltaX()->float;
			/// <summary>
			/// This function returns the mouse delta y.
			/// </summary>
			ECAPI auto GetMouseDeltaY()->float;
			/// <summary>
			/// This function returns the scoll detla x.
			/// </summary>
			ECAPI auto GetScrollDeltaY()->float;
			/// <summary>
			/// This function returns the scroll delta x.
			/// </summary>
			ECAPI auto GetScrollDeltaX()->float;
		}

		namespace IO
		{

			/// <summary>
			/// This function returns the current working directory.
			/// </summary>
			ECAPI auto GetCurrentDirectory()->std::string;
			/// <summary>
			/// This function returns the file name from a path.
			/// </summary>
			ECAPI auto GetFileNameFromPath(const char* path)->std::string;
		}

		namespace Types
		{
			/// <summary>
			/// This function returns true if T is derrived from info.
			/// </summary>
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
		/*
			External GPU Calls from the EclipseGraphics library.
		*/
		namespace Graphics
		{
			class GraphicsAPI
			{
			public:
				static ECAPI std::function<void(int, int, unsigned int, unsigned int)> Viewport_Pointer;
				static inline ECAPI void Viewport(int x, int y, unsigned int width, unsigned int height) { if (Viewport_Pointer) { Viewport_Pointer(x,y,width,height); } }
			};
		}

		/*
			External Debug Calls from the EclipseDebugging library.
		*/
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
