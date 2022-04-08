#include <pch.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Eclipse.h"

/*
 *
 *	Used for GetCurrentDir();
 *
 */
#include <direct.h>
 /*
  *
  *	Used for debugging purposes.
  *
  */

#include <termcolor/termcolor.hpp>

namespace Eclipse
{
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
		}

		static Data::CoreData CORE = { {},{},{} };

		namespace Window
		{
			GLFWwindow* InitWindow(int width, int height, const char* title, GLFWmonitor* monitor,
				GLFWwindow* window)
			{
				if (!glfwInit())
				{
					Debug::Log("GLFW failed to initialize.");
					return nullptr;
				}
				Debug::Log("GLFW initialized successfully.");

				glfwInitHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

				CORE.Window.currentContext = glfwCreateWindow(width, height, title, nullptr, nullptr);

				if (CORE.Window.currentContext == nullptr)
				{
					Debug::Log("Window failed to create.");
					return nullptr;
				}

				LoadCallbacks(CORE.Window.currentContext);

				Debug::Log("Setting to the current context.");
				glfwMakeContextCurrent(CORE.Window.currentContext);

				Debug::Log("Loading GLAD OpenGL loader.");
				gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

				glEnable(GL_DEPTH_TEST);

				/*
				 *
				 *	IMGUI
				 *
				 */
				IMGUI_CHECKVERSION();
				ImGui::CreateContext();
				ImGuiIO& io = ImGui::GetIO(); (void)io;
				ImGui_ImplGlfw_InitForOpenGL(CORE.Window.currentContext, true);
				ImGui_ImplOpenGL3_Init("#version 330");
				ImGui::StyleColorsDark();

				CORE.Window.screenWidth = width;
				CORE.Window.screenHeight = height;

				return CORE.Window.currentContext;
			}

			void CloseWindow()
			{
				ImGui_ImplOpenGL3_Shutdown();
				ImGui_ImplGlfw_Shutdown();
				ImGui::DestroyContext();

				glfwDestroyWindow(CORE.Window.currentContext);
				glfwTerminate();
			}

			bool IsWindowReady()
			{
				NOT_IMPLEMENTED(IsWindowReady())
					return false;
			}

			bool IsWindowFullscreen()
			{
				return CORE.Window.fullscreen == true;
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
					if (!CORE.Window.fullscreen)
					{
						glfwGetWindowPos(CORE.Window.currentContext, &CORE.Window.screenPosX, &CORE.Window.screenPosY);

						int monitorCount = 0;
						GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);

						const int monitorIndex = GetCurrentMonitor();

						GLFWmonitor* monitor = monitorIndex < monitorCount ? monitors[monitorIndex] : nullptr;

						if (!monitor)
						{
							SetFullscreen(false);
							return;
						}

						// set full screen.
						CORE.Window.fullscreen = flag;
						glfwSetWindowMonitor(CORE.Window.currentContext, monitor, 0, 0, CORE.Window.screenWidth, CORE.Window.screenHeight, GLFW_DONT_CARE);
					}
				}
				else
				{
					if (CORE.Window.fullscreen)
					{
						// set windowed.
						glfwSetWindowMonitor(CORE.Window.currentContext, nullptr, 0, 0, CORE.Window.screenWidth, CORE.Window.screenHeight, GLFW_DONT_CARE);

						CORE.Window.fullscreen = flag;
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
				return CORE.Window.screenWidth;
			}

			int GetScreenHeight()
			{
				return CORE.Window.screenHeight;
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
				int monitorCount;
				GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);
				GLFWmonitor* monitor = nullptr;

				// only one monitor.
				if (monitorCount == 1)
					return 0;

				if (IsWindowFullscreen())
				{
					monitor = glfwGetWindowMonitor(CORE.Window.currentContext);
					for (int i = 0; i < monitorCount; i++)
					{
						if (monitors[i] == monitor)
							return i;
					}
					return 0;
				}

				int x = 0, y = 0;

				glfwGetWindowPos(CORE.Window.currentContext, &x, &y);

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
				glfwSetInputMode(CORE.Window.currentContext, GLFW_CURSOR, show ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);

				CORE.Mouse.cursorHidden = !show;
			}

			bool IsCursorHidden()
			{
				return CORE.Mouse.cursorHidden == true;
			}

			bool IsCursorOnScreen()
			{
				NOT_IMPLEMENTED(IsCursorOnScreen())
					return false;
			}

			void SetWindowOpacity(float alpha)
			{
				if (CORE.Window.currentContext)
				{
					glfwSetWindowOpacity(CORE.Window.currentContext, alpha);
				}
			}

			float GetWindowOpacity()
			{
				if (CORE.Window.currentContext)
				{
					return glfwGetWindowOpacity(CORE.Window.currentContext);
				}
				return -1.0f;
			}

			auto MouseCallback(GLFWwindow* window, double xPosIn, double yPosIn) -> void
			{
				//Core::Debug::Debug((std::string("Mouse position to: X: ") + std::to_string(xPosIn) + std::string(" Y: ") + std::to_string(yPosIn)).c_str());

				CORE.Mouse.deltaMouseX = xPosIn - CORE.Mouse.lastMouseX;
				CORE.Mouse.deltaMouseY = CORE.Mouse.lastMouseY - yPosIn;

				CORE.Mouse.lastMouseX = xPosIn;
				CORE.Mouse.lastMouseY = yPosIn;
			}

			auto FrameBufferSizeCallback(GLFWwindow* window, int width, int height) -> void
			{
				//Core::Debug::Debug((std::string("Frame buffer resize to: WIDTH: ") + std::to_string(width) + std::string(" HEIGHT: ") + std::to_string(height)).c_str());

				CORE.Window.screenWidth = width;
				CORE.Window.screenHeight = height;
				Rendering::Viewport(0, 0, width, height);
			}

			auto WindowSizeCallback(GLFWwindow* window, int width, int height) -> void
			{
				//Core::Debug::Debug((std::string("Window resize to: WIDTH: ") + std::to_string(width) + std::string(" HEIGHT: ") + std::to_string(height)).c_str());
			}

			auto ScrollCallback(GLFWwindow* window, double xOffset, double yOffset) -> void
			{
				//Core::Debug::Debug("Scroll callback");

				CORE.Mouse.deltaScrollX = xOffset;
				CORE.Mouse.deltaScrollY = yOffset;
			}

			auto WindowFocusCallback(GLFWwindow* window, int focused) -> void
			{
				if (focused)
				{
					Core::Debug::Debug("Window is focused.");
				}
				else
				{
					Core::Debug::Debug("Window is not focused.");
				}
			}

			auto WindowRefreshCallback(GLFWwindow* window) -> void
			{
				E_ERROR(Frame Error)
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
			bool WindowShouldTerminate()
			{
				return (glfwWindowShouldClose(CORE.Window.currentContext) && CORE.Keyboard.exitKey != GLFW_PRESS);
			}
		}

		namespace Input
		{
			int GetExitKey()
			{
				return CORE.Keyboard.exitKey;
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
				CORE.Keyboard.exitKey = keyCode;
			}

			glm::vec2 GetMouse()
			{
				return { CORE.Mouse.lastMouseX, CORE.Mouse.lastMouseY };
			}

			int GetMouseY()
			{
				return static_cast<int>(CORE.Mouse.lastMouseY);
			}

			int GetMouseX()
			{
				return static_cast<int>(CORE.Mouse.lastMouseX);
			}

			bool IsMouseUp(int mouseCode)
			{
				return !IsMouseDown(mouseCode);
			}

			bool IsMouseDown(int mouseCode)
			{
				return glfwGetMouseButton(CORE.Window.currentContext, mouseCode) == GLFW_PRESS;
			}

			bool IsMouseReleased(int mouseCode)
			{
				NOT_IMPLEMENTED(IsMouseReleased(int mouseCode))
					return false;
			}

			glm::vec2 GetMouseDelta()
			{
				return { CORE.Mouse.deltaMouseX, CORE.Mouse.deltaMouseY };
			}

			glm::vec2 GetScrollDelta()
			{
				return { CORE.Mouse.deltaScrollX, CORE.Mouse.deltaScrollY };
			}

			float GetMouseDeltaX()
			{
				return static_cast<float>(CORE.Mouse.deltaMouseX);
			}

			float GetMouseDeltaY()
			{
				return static_cast<float>(CORE.Mouse.deltaMouseY);
			}

			float GetScrollDeltaY()
			{
				return static_cast<float>(CORE.Mouse.deltaScrollY);
			}

			float GetScrollDeltaX()
			{
				return static_cast<float>(CORE.Mouse.deltaScrollX);
			}

			/// <summary>
			/// Check if specified KeyCode is down.
			/// </summary>
			/// <param name="keyCode"></param>
			/// <returns></returns>
			bool IsKeyDown(int keyCode)
			{
				return glfwGetKey(CORE.Window.currentContext, keyCode) == GLFW_PRESS;
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

		namespace Rendering
		{
			void BeginDrawing()
			{
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glfwPollEvents();
				ImGui_ImplOpenGL3_NewFrame();
				ImGui_ImplGlfw_NewFrame();
				ImGui::NewFrame();
			}

			void  EndDrawing()
			{
				ImGui::Render();
				ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
				glfwSwapBuffers(CORE.Window.currentContext);
			}

			void ClearBackground(float r, float g, float b, float a)
			{
				glClearColor(r, g, b, a);
			}

			void  ClearBackground(Data::ECC color)
			{
				ClearBackground(static_cast<float>(color.r), static_cast<float>(color.g), static_cast<float>(color.b),
					static_cast<float>(color.a));
			}

			void GenBuffer(int size, unsigned int* vbo)
			{
				glGenBuffers(size, vbo);
			}

			void GenVertexArray(int size, unsigned int* vao)
			{
				glGenVertexArrays(size, vao);
			}

			void BindVertexArray(unsigned int vao)
			{
				glBindVertexArray(vao);
			}

			void BindBuffer(unsigned int target, unsigned buffer)
			{
				glBindBuffer(target, buffer);
			}

			void FillBufferData(unsigned int target, unsigned long long int size, const void* data,
				unsigned usage)
			{
				glBufferData(target, static_cast<long long>(size), data, usage);
			}

			void EnableVertexAttributeArray(unsigned int index)
			{
				glEnableVertexAttribArray(index);
			}

			void VertexAttributePointer(unsigned int index, int size, unsigned int type, char normalized,
				int stride,
				const void* pointer)
			{
				glVertexAttribPointer(index, size, type, normalized, stride, pointer);
			}

			void DrawElements(unsigned int mode, int count, unsigned int type, const void* indices)
			{
				glDrawElements(mode, count, type, indices);
			}

			void DrawArrays(unsigned int mode, int first, int count)
			{
				glDrawArrays(mode, first, count);
			}

			void GenTextures(int instance, unsigned int* textureId)
			{
				glGenTextures(instance, textureId);
			}

			void BindTexture(unsigned int target, unsigned int texture)
			{
				glBindTexture(target, texture);
			}

			void TexImage2D(unsigned int target, int level, int internalFormat, int width, int height,
				int border,
				unsigned format, unsigned type, const void* pixels)
			{
				glTexImage2D(target, level, internalFormat, width, height, border, format, type, pixels);
			}

			void GenerateMipMap(unsigned int target)
			{
				glGenerateMipmap(target);
			}

			void TexParameteri(unsigned target, unsigned pname, int param)
			{
				glTexParameteri(target, pname, param);
			}

			auto Viewport(int x, int y, unsigned width, unsigned height) -> void
			{
				glViewport(x, y, width, height);
			}

			auto FillBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) -> void
			{
				glBufferSubData(target, offset, size, data);
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
				NULL_REF()
					return "";
			}
		}

		namespace Debug
		{
			void Log(const char* str)
			{
				// TODO: Add a safety check to check if there is a console process.

				std::cout << termcolor::green << "[LOG] " << Utilities::GetTime() << termcolor::green << " " << str << termcolor::reset << std::endl;
			}

			void Debug(const char* str)
			{
				std::cout << termcolor::yellow << "[DEBUG] " << Utilities::GetTime() << termcolor::green << " " << str << termcolor::reset << std::endl;
			}

			void Error(const char* str)
			{
				std::cout << termcolor::red << "[ERROR] " << Utilities::GetTime() << " " << str << termcolor::reset << std::endl;
			}

			void NotImplemented(const char* functionName)
			{
				Error((std::string(functionName) + " has not been implemented.").c_str());
				throw std::invalid_argument(std::string(functionName) + " has not been implemented.");
			}
		}

		namespace Utilities
		{
			std::string GetTime()
			{
				// I C U
				// why did i comment ICU - 3/7/2022 - james.
				// I still have no clue why i wrote I C U - 3/17/2022 - james.
				// Still have 0 recollection of why i commented I C U - 3/23/2022 - james.

				time_t now = time(nullptr);
				tm timeStruct{};
				char buffer[80];
				localtime_s(&timeStruct, &now);

				strftime(buffer, sizeof(buffer), "%Y-%m-%d.%X", &timeStruct);

				return buffer;
			}
		}
	}
}