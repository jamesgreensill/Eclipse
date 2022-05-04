#pragma once
#include <string>
#include <typeindex>
#include <unordered_map>
#include <vector>

namespace Eclipse
{
	namespace Engine
	{

// Resource Identifier
		typedef unsigned int ResourceID;
		// Batch Identifier
		typedef std::type_index BatchID;
		// Directories Parameter for Resource Loading.
		typedef std::vector<std::string> ResourceDirectories;
		// Resource Access Key.

// Invalid Resource Code.
#define INVALID_RESOURCE (Eclipse::Engine::ResourceID)-1

		typedef struct ResourceKey
		{
			// Batch Identifier
			BatchID batchId = typeid(this);
			// Resource Identifier
			ResourceID resourceId = INVALID_RESOURCE;
		}ResourceKey;
#define INVALID_RESOURCE_KEY Eclipse::Engine::ResourceKey({typeid(this), INVALID_RESOURCE})
	}
}
