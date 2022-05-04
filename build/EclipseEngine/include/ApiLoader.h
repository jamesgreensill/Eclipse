#pragma once
#include "API.h"
namespace Eclipse
{
	namespace Engine
	{
		class ApiLoader
		{
		public:

		// Templated function to hot-load an API.
			template<typename T>
			static void Load()
			{
				const auto api = dynamic_cast<API*>(new T());
				if (api)
				{
					api->LoadInterface();
				}
			}
		};
	}
}
