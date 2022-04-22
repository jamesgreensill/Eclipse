#include "Core.h"

#include <GLFW/glfw3.h>

#include "GraphicsModule.h"
#include "EclipseEngine/include/Engine.h"

namespace Eclipse
{
	namespace Graphics
	{
		auto StartOpenGLInitialization() -> void
		{
			gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

			glEnable(GL_DEPTH_TEST);
		}

		auto EndOpenGLInitialization() -> void
		{
			Engine::Engine::SetCondition("OpenGL.Load", true);
			GraphicsModule::OnOpenGLLoad.Invoke();
		}

		auto ClearScreen(unsigned int bitField)-> void
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		/*
		 *	To future james, I am sure you will forget this.
		 *	I think openGL is not being initalized properly.
		 *	Check orders of modules being loaded.
		 *	Reference working engine.
		 */
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
}
