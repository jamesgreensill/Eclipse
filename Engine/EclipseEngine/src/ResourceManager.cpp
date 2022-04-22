#include "ResourceManager.h"

namespace Eclipse
{
	namespace Engine
	{
		BatchContainer ResourceManager::m_Batches = {};
		std::unordered_map<std::type_index, ResourceKey> ResourceManager::m_DefaultResources = {};

		bool ResourceManager::Free(ResourceKey& key)
		{
			// create top level local space pointer
			Resource* resource = nullptr;

			// Make sure the resourceId is valid.
			if (key.resourceId != INVALID_RESOURCE)
			{
				// retrieve the resource from the appropriate batch.
				resource = m_Batches[key.batchId][key.resourceId];
				// delete the resources memory.
				delete resource;
				// set the resourceID to invalid.
				key.resourceId = INVALID_RESOURCE;
				External::Debug::DebugAPI::Debug((std::string("Resource id of: ") + std::to_string(key.resourceId) + " was deleted.").c_str());
				return true;
			}
			External::Debug::DebugAPI::Debug((std::string("Resource id of: ") + std::to_string(key.resourceId) + " was invalid.").c_str());
			return false;
		}

		void ResourceManager::SetDefault(const ResourceKey& key)
		{
			if (m_DefaultResources.try_emplace(key.batchId, key).second)
			{
				External::Debug::DebugAPI::Debug((std::string(key.batchId.name()) + " was successfully implemented as a resource default.").c_str());
			}
			else
			{
				External::Debug::DebugAPI::Debug((std::string(key.batchId.name()) + " already has a default resource. Replacing now...").c_str());
				m_DefaultResources[key.batchId] = key;
			}
		}
	}
}