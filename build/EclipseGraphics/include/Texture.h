#pragma once
#include <string>

#include "ShaderProgram.h"

namespace Eclipse
{
	namespace Rendering
	{
		enum Format : unsigned int
		{
			RED = 1,
			RG,
			RGB,
			RGBA
		};

		struct Texture
		{
			std::string m_fileName;
			unsigned int m_width;
			unsigned int m_height;
			unsigned int m_handle;
			unsigned int m_format;
			unsigned char* m_loadedPixels;
			void Bind(ShaderProgram* shader, unsigned int slot);
		};
	}
}
