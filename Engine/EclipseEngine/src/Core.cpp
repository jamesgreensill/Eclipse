//#include <imgui.h>
//#include <imgui_impl_glfw.h>
//#include <imgui_impl_opengl3.h>

#include "Core.h"

/*
 *
 *	Used for GetCurrentDir();
 *
 */
#include <direct.h>
#include <ostream>
#include <time.h>

#include "Application.h"

/*
 *
 *	Used for debugging purposes.
 *
 *
 */
 //#include <termcolor/termcolor.hpp>

namespace Eclipse
{
	namespace Core
	{
		namespace Data
		{
			CoreData CORE = { {},{},{} };
		}

		namespace Window
		{
			void BeginDrawing()
			{
				/*
					TODO: Merge GUI calls to EclipseGUI.
				*/

				glfwPollEvents();
				//ImGui_ImplOpenGL3_NewFrame();
				//ImGui_ImplGlfw_NewFrame();
				//ImGui::NewFrame();
			}

			void  EndDrawing()
			{

				/*
					TODO: Merge GUI calls to EclipseGUI.
				*/
				
				//ImGui::Render();
				//ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
				glfwSwapBuffers(Data::CORE.Window.currentContext);
			}

			void ClearBackground(float r, float g, float b, float a)
			{
				glClearColor(r, g, b, a);
			}

			void  ClearBackground(Core::Data::ECC color)
			{
				ClearBackground(static_cast<float>(color.r), static_cast<float>(color.g), static_cast<float>(color.b),
					static_cast<float>(color.a));
			}

			GLFWwindow* InitWindow(int width, int height, const char* title, GLFWmonitor* monitor,
				GLFWwindow* window)
			{
				// Initialize GLFW.
				if (!glfwInit())
				{
					//Debug::Log("GLFW failed to initialize.");
					return nullptr;
				}
				//Debug::Log("GLFW initialized successfully.");

				// Initialize window transparency
				glfwInitHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

				// create window context.
				Data::CORE.Window.currentContext = glfwCreateWindow(width, height, title, nullptr, nullptr);

				if (Data::CORE.Window.currentContext == nullptr)
				{
					//Debug::Log("Window failed to create.");
					return nullptr;
				}

				// load window callbacks
				LoadCallbacks(Data::CORE.Window.currentContext);

				//Debug::Log("Setting to the current context.");
				glfwMakeContextCurrent(Data::CORE.Window.currentContext);

				glfwSwapInterval(0);


				/*
					TODO: Merge GUI calls to EclipseGUI.
				*/
				//Debug::Log("Loading GLAD OpenGL loader.");

				/*
				 *
				 *	IMGUI
				 *
				 */
				 //IMGUI_CHECKVERSION();
				 //ImGui::CreateContext();
				 //ImGuiIO& io = ImGui::GetIO(); (void)io;
				 //ImGui_ImplGlfw_InitForOpenGL(CORE.Window.currentContext, true);
				 //ImGui_ImplOpenGL3_Init("#version 330");
				 //ImGui::StyleColorsDark();

				// Set window data.
				Data::CORE.Window.screenWidth = width;
				Data::CORE.Window.screenHeight = height;

				return Data::CORE.Window.currentContext;
			}

			void CloseWindow()
			{
				/*
					TODO: Merge GUI calls to EclipseGUI.
				*/
				//ImGui_ImplOpenGL3_Shutdown();
				//ImGui_ImplGlfw_Shutdown();
				//ImGui::DestroyContext();

				// destroy window context
				glfwDestroyWindow(Data::CORE.Window.currentContext);
				glfwTerminate();
			}

			bool IsWindowReady()
			{
				NOT_IMPLEMENTED(IsWindowReady())
					return false;
			}

			bool IsWindowFullscreen()
			{
				return Data::CORE.Window.fullscreen == true;
			}

			bool IsWindowHidden()
			{
				NOT_IMPLEMENTED(IsWindowHidden())
					return false;
			}

			bool IsWindowMinimized()
			{
				NOT_IMPLEMENTED(IsWindowMinimized())
					return false;
			}

			bool IsWindowMaximized()
			{
				NOT_IMPLEMENTED(IsWindowMaximized())
					return false;
			}

			bool IsWindowFocused()
			{
				NOT_IMPLEMENTED(IsWindowFocused())
					return false;
			}

			bool IsWindowResized()
			{
				NOT_IMPLEMENTED(IsWindowResized())
					return false;
			}

			bool IsWindowState(unsigned flags)
			{
				NOT_IMPLEMENTED(IsWindowState(unsigned long flags))
					return false;
			}

			void SetWindowState(unsigned flags)
			{
				NOT_IMPLEMENTED(SetWIndowState(unsigned long flags))
			}

			void ClearWindowState(unsigned flags)
			{
				NOT_IMPLEMENTED(ClearWindowState(unsigned long flags))
			}

			/*
			 *	BUG: When alt-tabbing the application crashes most likely due to width & height becoming 0.
			 */
			void SetFullscreen(bool flag)
			{
				if (flag)
				{
					// check if the current window not fullscreened.
					if (!Data::CORE.Window.fullscreen)
					{
						// get the window position
						glfwGetWindowPos(Data::CORE.Window.currentContext, &Data::CORE.Window.screenPosX, &Data::CORE.Window.screenPosY);

						// get the monitor count & monitors
						int monitorCount = 0;
						GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);

						// get the current monitor index.
						const int monitorIndex = GetCurrentMonitor();

						// get the current monitor pointer.
						GLFWmonitor* monitor = monitorIndex < monitorCount ? monitors[monitorIndex] : nullptr;

						// if there is no monitor, recall the function with the false parameter to set window to windowed.
						if (!monitor)
						{
							SetFullscreen(false);
							return;
						}

						// set full screen.
						Data::CORE.Window.fullscreen = flag;
						glfwSetWindowMonitor(Data::CORE.Window.currentContext, monitor, 0, 0, Data::CORE.Window.screenWidth, Data::CORE.Window.screenHeight, GLFW_DONT_CARE);
					}
				}
				else
				{
					if (Data::CORE.Window.fullscreen)
					{
						// set windowed.
						glfwSetWindowMonitor(Data::CORE.Window.currentContext, nullptr, 0, 0, Data::CORE.Window.screenWidth, Data::CORE.Window.screenHeight, GLFW_DONT_CARE);

						Data::CORE.Window.fullscreen = flag;
					}
				}
			}

			void MaximizeWindow()
			{
				NOT_IMPLEMENTED(MaximizeWindow())
			}

			void MinimizeWindow()
			{
				NOT_IMPLEMENTED(MinimizeWindow())
			}

			void RestoreWindow()
			{
				NOT_IMPLEMENTED(RestoreWindow())
			}

			void SetWindowTitle(const char* title)
			{
				NOT_IMPLEMENTED(SetWindowTitle(const char* title))
			}

			void SetWindowPosition(int x, int y)
			{
				NOT_IMPLEMENTED(SetWindowPos(int x, int y))
			}

			void SetWindowPosition(glm::vec2 point)
			{
				NOT_IMPLEMENTED(SetWindowPosition(glm::vec2 point))
			}

			void SetWindowMonitor(int monitor)
			{
				NOT_IMPLEMENTED(SetWindowMonitor(int monitor))
			}

			void SetWindowMinSize(int x, int y)
			{
				NOT_IMPLEMENTED(SetWindowMinSize(int x, int y))
			}

			void SetWindowMinSize(glm::vec2 size)
			{
				NOT_IMPLEMENTED(SetWindowMinSize(glm::vec2 size))
			}

			void SetWindowMaxSize(int x, int y)
			{
				NOT_IMPLEMENTED(SetWindowMaxSize(int x, int y))
			}

			void SetWindowMaxSize(glm::vec2 size)
			{
				NOT_IMPLEMENTED(SetWindowMaxSize(glm::vec2 size))
			}

			void SetWindowSize(int x, int y)
			{
				NOT_IMPLEMENTED(SetWindowSize(int x, int y))
			}

			void SetWindowSize(glm::vec2 size)
			{
				NOT_IMPLEMENTED(SetWindowSize(glm::vec2 size))
			}

			void* GetWindowHandle()
			{
				NOT_IMPLEMENTED(GetWindowHandle())
					return nullptr;
			}

			int GetScreenWidth()
			{
				return Data::CORE.Window.screenWidth;
			}

			int GetScreenHeight()
			{
				return Data::CORE.Window.screenHeight;
			}

			glm::vec2 GetScreenSize()
			{
				NOT_IMPLEMENTED(GetScreenSize())
					return { 0, 0 };
			}

			int GetScreenSize1D()
			{
				NOT_IMPLEMENTED(GetScreenSize1D())
					return 0;
			}

			int GetBufferWidth()
			{
				NOT_IMPLEMENTED(GetBufferWidth())
					return 0;
			}

			int GetBufferHeight()
			{
				NOT_IMPLEMENTED(GetBufferHeight())
					return 0;
			}

			int GetBufferSize1D()
			{
				NOT_IMPLEMENTED(GetBufferSize1D())
					return 0;
			}

			glm::vec2 GetBufferSize()
			{
				NOT_IMPLEMENTED(GetBufferSize())
					return { 0, 0 };
			}

			int GetMonitorCount()
			{
				NOT_IMPLEMENTED(GetMonitorCount())
					return 0;
			}

			int GetCurrentMonitor()
			{
				// create stack allocation
				int monitorCount;

				// get pointers to monitors
				GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);
				GLFWmonitor* monitor = nullptr;

				// only one monitor.
				if (monitorCount == 1)
					return 0;

				// if the window is fullscreen then check which monitor the window is on.
				if (IsWindowFullscreen())
				{
					monitor = glfwGetWindowMonitor(Data::CORE.Window.currentContext);
					for (int i = 0; i < monitorCount; i++)
					{
						if (monitors[i] == monitor)
							return i;
					}
					return 0;
				}

				int x = 0, y = 0;

				// get the window position
				glfwGetWindowPos(Data::CORE.Window.currentContext, &x, &y);

				// do AABB to determine if the window is on a monitor.
				for (int i = 0; i < monitorCount; i++)
				{
					int mx = 0, my = 0, width = 0, height = 0;
					monitor = monitors[i];
					glfwGetMonitorWorkarea(monitor, &mx, &my, &width, &height);
					if (x >= mx && x <= (mx + width) && y >= my && y <= (my + height))
						return i;
				}

				return 0;
			}

			int GetMonitorRefreshRate(int monitor)
			{
				NOT_IMPLEMENTED(GetMonitorRefreshRate(int monitor))
					return 0;
			}

			glm::vec2 GetWindowPosition()
			{
				NOT_IMPLEMENTED(GetWindowPosition())
					return { 0, 0 };
			}

			glm::vec2 GetWindowScaleDPI()
			{
				NOT_IMPLEMENTED(GetWindowScaleDPI())
					return { 0, 0 };
			}

			const char* GetMonitorName(int monitor)
			{
				NOT_IMPLEMENTED(GetMonitorName(int monitor))
					return nullptr;
			}

			void SetClipboardText(const char* text)
			{
				NOT_IMPLEMENTED(SetClipboardText(const char* text))
			}

			const char* GetClipboardText()
			{
				NOT_IMPLEMENTED(GetClipboardText())
					return nullptr;
			}

			void ShowCursor(bool show)
			{
				// show or hide cursor based on show boolean.
				glfwSetInputMode(Data::CORE.Window.currentContext, GLFW_CURSOR, show ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);

				Data::CORE.Mouse.cursorHidden = !show;
			}

			bool IsCursorHidden()
			{
				return Data::CORE.Mouse.cursorHidden == true;
			}

			bool IsCursorOnScreen()
			{
				NOT_IMPLEMENTED(IsCursorOnScreen())
					return false;
			}

			void SetWindowOpacity(float alpha)
			{
				if (Data::CORE.Window.currentContext)
				{
					glfwSetWindowOpacity(Data::CORE.Window.currentContext, alpha);
				}
			}

			float GetWindowOpacity()
			{
				if (Data::CORE.Window.currentContext)
				{
					return glfwGetWindowOpacity(Data::CORE.Window.currentContext);
				}
				return -1.0f;
			}

			auto MouseCallback(GLFWwindow* window, double xPosIn, double yPosIn) -> void
			{
				//Core::Debug::Debug((std::string("Mouse position to: X: ") + std::to_string(xPosIn) + std::string(" Y: ") + std::to_string(yPosIn)).c_str());

				Data::CORE.Mouse.deltaMouseX = xPosIn - Data::CORE.Mouse.lastMouseX;
				Data::CORE.Mouse.deltaMouseY = Data::CORE.Mouse.lastMouseY - yPosIn;

				Data::CORE.Mouse.lastMouseX = xPosIn;
				Data::CORE.Mouse.lastMouseY = yPosIn;
			}

			auto FrameBufferSizeCallback(GLFWwindow* window, int width, int height) -> void
			{
				//Core::Debug::Debug((std::string("Frame buffer resize to: WIDTH: ") + std::to_string(width) + std::string(" HEIGHT: ") + std::to_string(height)).c_str());

				Data::CORE.Window.screenWidth = width;
				Data::CORE.Window.screenHeight = height;

				External::Graphics::GraphicsAPI::Viewport(0, 0, width, height);
			}

			auto WindowSizeCallback(GLFWwindow* window, int width, int height) -> void
			{
				//Core::Debug::Debug((std::string("Window resize to: WIDTH: ") + std::to_string(width) + std::string(" HEIGHT: ") + std::to_string(height)).c_str());
			}

			auto ScrollCallback(GLFWwindow* window, double xOffset, double yOffset) -> void
			{
				//Core::Debug::Debug("Scroll callback");

				Data::CORE.Mouse.deltaScrollX = xOffset;
				Data::CORE.Mouse.deltaScrollY = yOffset;
			}

			auto WindowFocusCallback(GLFWwindow* window, int focused) -> void
			{
				if (focused)
				{
					External::Debug::DebugAPI::Log("Window is focused.");
				}
				else
				{
					External::Debug::DebugAPI::Log("Window is not focused.");
				}
			}

			auto WindowRefreshCallback(GLFWwindow* window) -> void
			{
				//E_ERROR(Frame Error)
			}

			auto LoadCallbacks(GLFWwindow* window) -> void
			{
				// window
				glfwSetWindowSizeCallback(window, WindowSizeCallback);
				glfwSetWindowFocusCallback(window, WindowFocusCallback);
				glfwSetWindowRefreshCallback(window, WindowRefreshCallback);

				// frame buffer
				glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);

				// input
				glfwSetCursorPosCallback(window, MouseCallback);
				glfwSetScrollCallback(window, ScrollCallback);
			}

			/// <summary>
			/// Checks if the Window should close via KeyPress & Or Error.
			/// </summary>
			/// <returns></returns>
			bool WindowShouldTerminate(Engine::Application* application)
			{
				// is there a window context?
				if (Data::CORE.Window.currentContext)
				{
					return (glfwWindowShouldClose(Data::CORE.Window.currentContext) && Data::CORE.Keyboard.exitKey != GLFW_PRESS);
				}
				// return the application state.
				return application->m_shouldClose;
			}
		}

		namespace Input
		{
			int GetExitKey()
			{
				return Data::CORE.Keyboard.exitKey;
			}

			int GetKeyPressed()
			{
				NOT_IMPLEMENTED(GetKeyPressed())
					return 0;
			}

			int GetCharPressed()
			{
				return GetKeyPressed();
			}

			void SetExitKey(int keyCode)
			{
				Data::CORE.Keyboard.exitKey = keyCode;
			}

			glm::vec2 GetMouse()
			{
				return { Data::CORE.Mouse.lastMouseX, Data::CORE.Mouse.lastMouseY };
			}

			int GetMouseY()
			{
				return static_cast<int>(Data::CORE.Mouse.lastMouseY);
			}

			int GetMouseX()
			{
				return static_cast<int>(Data::CORE.Mouse.lastMouseX);
			}

			bool IsMouseUp(int mouseCode)
			{
				return !IsMouseDown(mouseCode);
			}

			bool IsMouseDown(int mouseCode)
			{
				return glfwGetMouseButton(Data::CORE.Window.currentContext, mouseCode) == GLFW_PRESS;
			}

			bool IsMouseReleased(int mouseCode)
			{
				External::Debug::DebugAPI::Error("Null Reference");
				return false;
			}

			glm::vec2 GetMouseDelta()
			{
				return { Data::CORE.Mouse.deltaMouseX, Data::CORE.Mouse.deltaMouseY };
			}

			glm::vec2 GetScrollDelta()
			{
				return { Data::CORE.Mouse.deltaScrollX, Data::CORE.Mouse.deltaScrollY };
			}

			float GetMouseDeltaX()
			{
				return static_cast<float>(Data::CORE.Mouse.deltaMouseX);
			}

			float GetMouseDeltaY()
			{
				return static_cast<float>(Data::CORE.Mouse.deltaMouseY);
			}

			float GetScrollDeltaY()
			{
				return static_cast<float>(Data::CORE.Mouse.deltaScrollY);
			}

			float GetScrollDeltaX()
			{
				return static_cast<float>(Data::CORE.Mouse.deltaScrollX);
			}

			/// <summary>
			/// Check if specified KeyCode is down.
			/// </summary>
			/// <param name="keyCode"></param>
			/// <returns></returns>
			bool IsKeyDown(int keyCode)
			{
				return glfwGetKey(Data::CORE.Window.currentContext, keyCode) == GLFW_PRESS;
			}

			/// <summary>
			/// Check if specified KeyCode is Up.
			/// </summary>
			/// <param name="keyCode"></param>
			/// <returns></returns>
			bool IsKeyUp(int keyCode)
			{
				return !IsKeyDown(keyCode);
			}
		}

		namespace IO
		{
			std::string GetCurrentDirectory()
			{
				char buff[260];
				char* ptr = _getcwd(buff, 260);
				std::string currentWorkingDir(buff);
				return currentWorkingDir;
			}

			auto GetFileNameFromPath(const char* path) -> std::string
			{
				if (path)
				{
					std::string fileName = std::string(path);
					fileName = fileName.substr(fileName.find_last_of("/\\") + 1);
					std::string::size_type const p(fileName.find_last_of("."));
					fileName = fileName.substr(0, p);
					return fileName;
				}
				External::Debug::DebugAPI::Error("Null Reference");
				return "";
			}
		}

		namespace Debug
		{
		}

		namespace Utilities
		{
			std::string GetTime()
			{
				// I C U
				// why did i comment ICU - 3/7/2022 - james.
				// I still have no clue why i wrote I C U - 3/17/2022 - james.
				// Still have 0 recollection of why i commented I C U - 3/23/2022 - james.
				// ¯\_(ツ)_/¯
				// ¯\_(ツ)_/¯
				// ¯\_(ツ)_/¯
				time_t now = time(nullptr);
				tm timeStruct{};
				char buffer[80];
				localtime_s(&timeStruct, &now);

				strftime(buffer, sizeof(buffer), "%Y-%m-%d.%X", &timeStruct);

				return buffer;
			}
		}
	}
	namespace External
	{
		namespace Graphics
		{
			std::function<void(int, int, unsigned, unsigned)> GraphicsAPI::Viewport_Pointer = nullptr;
		}

		namespace Debug
		{
			EX_FUNCTION_DEF(Debug, DebugAPI, const char*, void);
			EX_FUNCTION_DEF(Error, DebugAPI, const char*, void);
			EX_FUNCTION_DEF(Log, DebugAPI, const char*, void);
		}

		namespace Test
		{
			EX_FUNCTION_DEF(TestCall, TestAPI, void, void);
		}
	}
}