#pragma once
#include <functional>
#include <queue>

#include "ResourceManager.h"

#include "typedefs.h"

/*

	DEPRECATED.

*/

namespace Eclipse
{
	namespace Engine
	{
		struct AssetCall
		{
			std::function<bool()> functionCall = nullptr;
		};

		class AssetLoader
		{
		public:
			static std::queue<AssetCall> AssetCalls;

			template<typename T>
			static void Load(ResourceDirectories directories, ResourceKey& key)
			{
				//AssetCall call =
				//{
				//	[&]
				//	{
				//		ResourceManager::Load<T>(directories, key);
				//	}
				//};
				//AssetCalls.emplace(call);
			}

			static void Awake();
		};
	}
}
