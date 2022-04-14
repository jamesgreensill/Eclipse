#include "Texture.h"

#include <glad/glad.h>

namespace Eclipse
{
	namespace Graphics
	{
		void Texture::Bind(ShaderProgram* shader, unsigned int slot)
		{
			glActiveTexture(GL_TEXTURE0 + slot);
			glBindTexture(GL_TEXTURE_2D, m_handle);
		}

		bool Texture::Load(const Engine::ResourceDirectories& directories)
		{
			return false;
		}
	}
}