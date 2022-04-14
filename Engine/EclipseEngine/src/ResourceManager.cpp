#include "ResourceManager.h"

namespace Eclipse
{
	namespace Engine
	{
		BatchContainer ResourceManager::m_Batches = {};

		

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
	}
}