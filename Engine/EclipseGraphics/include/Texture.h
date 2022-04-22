#pragma once
#include <EclipseEngine/include/Resource.h>

#include <string>

#include "ShaderProgram.h"

namespace Eclipse
{
	namespace Graphics
	{
		enum Format : unsigned int
		{
			RED = 1,
			RG,
			RGB,
			RGBA
		};

		struct Texture : Engine::Resource
		{
			std::string m_fileName = "none";
			unsigned int m_width = 0;
			unsigned int m_height = 0;
			unsigned int m_handle = 0;
			unsigned int m_format = 0;
			unsigned char* m_loadedPixels = nullptr;
			int m_composition = -1;

			void Bind(ShaderProgram* shader, unsigned int slot);

			bool Load(const Engine::ResourceDirectories& directories) override;
			bool Setup() override;
		};
	}
}
