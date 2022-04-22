#pragma once
#include "glad.h"

#include <EclipseEngine/include/EngineMacros.h>

namespace Eclipse
{
	namespace Graphics
	{
		ECAPI auto StartOpenGLInitialization() -> void;
		ECAPI auto EndOpenGLInitialization() -> void;

		ECAPI auto ClearScreen(unsigned int) -> void;

		/// <summary>
		/// Drawing Functions
		/// </summary>
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
}
