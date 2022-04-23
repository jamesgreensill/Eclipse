#pragma once
#include "typedefs.h"
#include "Resource.h"

#include <unordered_map>
#include <vector>
#include "Core.h"

namespace Eclipse
{
	namespace Engine
	{
		typedef std::unordered_map<ResourceID, Resource*> ResourceContainer;
		typedef std::unordered_map<BatchID, ResourceContainer> BatchContainer;

		class ResourceManager
		{
		public:

			static bool Free(ResourceKey& key);
			static void SetDefault(const ResourceKey& key);

			template<typename T>
			static T* Get(const ResourceKey& key)
			{
				// check if resourceId is valid.
				if (key.resourceId != INVALID_RESOURCE)
					return (T*)m_Batches[key.batchId][key.resourceId];
				return nullptr;
			}
			template<typename T>
			static bool LoadNonAlloc(const ResourceDirectories& directories, ResourceKey& key)
			{
				IS_BASE_OF(Resource);

				// get the batchId from type.
				const BatchID bid = typeid(T);
				if (m_Batches.try_emplace(bid, ResourceContainer{}).second)
				{
					// successfully placed into list.
					// i-e there was no element of typeid(T) the batches list.
					External::Debug::DebugAPI::Debug((std::string(bid.name()) + "was successfully implemented as a resource batch.").c_str());
				}
				else
				{
					// unable to place into list.
					// i-e typeid(T) already existed as an element in the batches list.
					External::Debug::DebugAPI::Debug((std::string(bid.name()) + "already exists in the batches list.").c_str());
				}

				// generate a resourceId from the size of the specific batch.
				ResourceID rid = static_cast<ResourceID>(m_Batches[bid].size());
				// create a new resource of type T();
				auto resource = (Resource*)new T();
				if (resource->Load(directories))
				{
					m_Batches[bid].emplace(rid, resource);
					key.resourceId = rid;
					key.batchId = bid;
					resource->key = key;
					return true;
				}
				return false;
			}

			template<typename T>
			static ResourceKey Load(const ResourceDirectories& directories)
			{
				IS_BASE_OF(Resource);

				ResourceKey key = {};

				// get the batchId from type.
				const BatchID bid = typeid(T);
				if (m_Batches.try_emplace(bid, ResourceContainer{}).second)
				{
					// successfully placed into list.
					// i-e there was no element of typeid(T) the batches list.
					External::Debug::DebugAPI::Debug((std::string(bid.name()) + " was successfully implemented as a resource batch.").c_str());
				}
				else
				{
					// unable to place into list.
					// i-e typeid(T) already existed as an element in the batches list.
					External::Debug::DebugAPI::Debug((std::string(bid.name()) + "already exists in the batches list.").c_str());
				}

				// generate a resourceId from the size of the specific batch.
				ResourceID rid = m_Batches[bid].size();
				// create a new resource of type T();
				auto resource = reinterpret_cast<Resource*>(new T());
				if (resource->Load(directories))
				{
					m_Batches[bid].emplace(rid, resource);
					key.resourceId = rid;
					key.batchId = bid;
					resource->key = key;
					return key;
				}
				return {};
			}


			/// <summary>
			/// This function will return the default resource for type T if one exists.
			/// </summary>
			template<typename T>
			static ResourceKey GetDefault()
			{
				// Get a type_id
				std::type_index id = typeid(T);
				// Find the id in the default resources.
				const auto it = m_DefaultResources.find(id);
				if (it != m_DefaultResources.end())
				{
					External::Debug::DebugAPI::Debug((std::string(id.name()) + " default resource was successfully fetched.").c_str());
					return it->second;
				}

				External::Debug::DebugAPI::Debug((std::string(id.name()) + " does not contain a default resource... returning invalid resource.").c_str());

				return ResourceKey
				{
					id, INVALID_RESOURCE,
				};
			}

		private:
			static BatchContainer m_Batches;
			static std::unordered_map<std::type_index, ResourceKey> m_DefaultResources;
		};
	}
}
