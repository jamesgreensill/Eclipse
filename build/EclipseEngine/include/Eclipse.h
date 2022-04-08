/*

	Author: James Greensill.

*/
#pragma once

#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vcruntime_typeinfo.h>

#if defined(_WIN32)
#if defined(BUILD_LIBTYPE_SHARED)
#define ECAPI __declspec(dllexport)
#elif defined(USE_LIBTYPE_SHARED)
#define ECAPI __declspec(dllimport)
#endif
#endif
#ifndef ECAPI
#define ECAPI       // Functions defined as 'extern' by default (implicit specifiers)
#endif

// Forward Declarations for GLFW.
struct GLFWwindow;
struct GLFWmonitor;

// Type Definitions for GLFW

/*

	I am aware this seems overkill, however I want to explore typedef's & cleaning up confusing code from rather obscure Libraries.
	As I am only using GLFW, I believe simplifying the class names to remove GLFW is acceptable. - James.
	I will probably remove this to create a custom Window class. but ¯\_(ツ)_/¯

*/

namespace Eclipse {
	namespace Core
	{
		namespace Data
		{
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
			/// Returns true if the Window should close.
			/// </summary>
			ECAPI auto WindowShouldTerminate(void) -> bool;
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

		namespace Rendering
		{
			/// <summary>
			/// Drawing Functions
			/// </summary>

			ECAPI auto BeginDrawing() -> void;
			ECAPI auto EndDrawing() -> void;
			ECAPI auto ClearBackground(float r, float g, float b, float a) -> void;
			ECAPI auto ClearBackground(Data::ECC) -> void;
			ECAPI auto GenBuffer(int, unsigned int*) -> void;
			ECAPI auto GenVertexArray(int, unsigned int*) -> void;
			ECAPI auto BindVertexArray(unsigned int) -> void;
			ECAPI auto BindBuffer(unsigned int, unsigned int) -> void;
			ECAPI auto FillBufferData(unsigned int, unsigned long long int, const void*, unsigned int) -> void;
			ECAPI auto EnableVertexAttributeArray(unsigned int) -> void;
			ECAPI auto VertexAttributePointer(unsigned int, int, unsigned int, char, int, const void*) -> void;
			ECAPI auto DrawElements(unsigned int, int, unsigned int, const void*) -> void;
			ECAPI auto DrawArrays(unsigned int, int, int) -> void;
			ECAPI auto GenTextures(int, unsigned int*) -> void;
			ECAPI auto BindTexture(unsigned int, unsigned int) -> void;
			ECAPI auto TexImage2D(unsigned int, int, int, int, int, int, unsigned int, unsigned int, const void*) -> void;
			ECAPI auto GenerateMipMap(unsigned int) -> void;
			ECAPI auto TexParameteri(unsigned int, unsigned int, int) -> void;
			ECAPI auto Viewport(int, int, unsigned, unsigned) -> void;
			ECAPI auto FillBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) -> void;
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

		namespace Debug
		{
			ECAPI auto Log(const char* str) -> void;
			ECAPI auto Debug(const char* str) -> void;
			ECAPI auto Error(const char* str) -> void;

			/*
			 *
			 *	Chosen convention
			 *	"FUNCTION NAME has not been implemented."
			 *
			 */
			ECAPI auto NotImplemented(const char* functionName) -> void;

#pragma region MACROS

#define NOT_IMPLEMENTED(x) Core::Debug::NotImplemented(#x);

#define E_ERROR(x) Core::Debug::Error(#x);
#define LOG(x) Core::Debug::Log(#x);
#define DEBUG(x) Core::Debug::Debug(#x);

#define INDEX_OUT_OF_BOUNDS() E_ERROR(Index is out of bounds.)
#define NULL_REF() E_ERROR(Instance is nullptr.)
#define MAP_EMPLACE_FAIL(x) E_ERROR(#x Instance is nullptr.)
#define NO_ACTIVE_CAMERAS() E_ERROR(There are no active cameras in this scene.);

#pragma endregion
		}

		namespace Utilities
		{
			ECAPI auto GetTime()->std::string;
		}
	}
}
