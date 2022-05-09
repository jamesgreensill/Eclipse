#include "Texture.h"

#include <glad/glad.h>
#include <stb_image.h>

#include "GraphicsModule.h"
#include "EclipseEngine/include/Engine.h"

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
			// TODO: Verify that there is one path.

			const std::string path = directories[0];

			if (m_handle != 0)
			{
				if (Engine::Engine::GetCondition("OpenGL.Load"))
				{
					glDeleteTextures(1, &m_handle);
				}
				m_handle = 0;
				m_width = 0;
				m_height = 0;
				m_fileName = "none";
			}

			int x = 0;
			int y = 0;
			int composition = 0;

			m_loadedPixels = stbi_load(path.c_str(), &x, &y, &composition, STBI_default);
			if (m_loadedPixels)
			{
				m_width = (unsigned int)x;
				m_height = (unsigned int)y;
				m_fileName = path;
				m_composition = composition;

				LinkToCallback(Graphics::GraphicsModule::OnOpenGLLoad, Engine::Engine::GetCondition("OpenGL.Load"));

				return true;
			}
			return false;
		}

		bool Texture::Setup()
		{
			// file loaded correctly if true.
			if (m_loadedPixels != nullptr)
			{
				glGenTextures(1, &m_handle);
				glBindTexture(GL_TEXTURE_2D, m_handle);


				// determine format value and load into openGL.
				switch (m_composition) {
				case STBI_grey:
					m_format = RED;
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, (int)m_width, (int)m_height,
						0, GL_RED, GL_UNSIGNED_BYTE, m_loadedPixels);
					break;
				case STBI_grey_alpha:
					m_format = RG;
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, (int)m_width, (int)m_height,
						0, GL_RG, GL_UNSIGNED_BYTE, m_loadedPixels);
					break;
				case STBI_rgb:
					m_format = RGB;
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)m_width, (int)m_height,
						0, GL_RGB, GL_UNSIGNED_BYTE, m_loadedPixels);
					break;
				case STBI_rgb_alpha:
					m_format = RGBA;
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (int)m_width, (int)m_height,
						0, GL_RGBA, GL_UNSIGNED_BYTE, m_loadedPixels);
					break;
				default:
					break;
				}

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glGenerateMipmap(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, m_handle);

				return true;
			}
			return false;
		}
	}
}