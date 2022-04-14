#pragma once

#include "typedefs.h"

namespace Eclipse
{
	namespace Engine
	{
		struct Resource
		{
			ResourceKey key;
			virtual bool Load(const ResourceDirectories& directories) = 0;
		};
	}
}
