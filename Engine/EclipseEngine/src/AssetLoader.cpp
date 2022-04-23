#include "AssetLoader.h"

namespace Eclipse
{
	namespace Engine
	{
		std::queue<AssetCall> AssetLoader::AssetCalls = {};
		
		void AssetLoader::Awake()
		{
			// loop through the queue until it is empty.
			while (!AssetCalls.empty())
			{
				const auto call = AssetCalls.front();
				if (call.functionCall)
				{
					call.functionCall();
				}
				AssetCalls.pop();
			}
		}
	}
}