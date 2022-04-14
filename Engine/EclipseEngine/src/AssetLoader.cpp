#include "AssetLoader.h"

namespace Eclipse
{
	namespace Engine
	{
		std::queue<AssetCall> AssetLoader::AssetCalls = {};
		
		void AssetLoader::Awake()
		{
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