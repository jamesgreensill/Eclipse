#include <pch.h>
#include "Texture.h"

#include <glad/glad.h>

namespace Eclipse
{
	namespace Rendering
	{
		void Texture::Bind(ShaderProgram* shader, unsigned int slot)
		{
			glActiveTexture(GL_TEXTURE0 + slot);
			glBindTexture(GL_TEXTURE_2D, m_handle);
		}
	}
}
