#pragma once
#include "API.h"

#include "Core.h"

namespace Eclipse
{
	namespace Engine
	{
		class ApiLoader
		{
		public:

			// Template function to hot-load an API.
			template<typename T>
			static void Load()
			{
				const auto api = dynamic_cast<API*>(new T());
				if (api)
				{
					External::Debug::DebugAPI::Log("Loaded API: " + std::string(typeid(T).name()));
					api->LoadInterface();
				}
			}
		};
	}
}
