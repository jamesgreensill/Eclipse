#pragma once

#include "EclipseEvent.h"
#include "typedefs.h"

namespace Eclipse
{
	namespace Engine
	{
		struct Resource
		{
			ResourceKey key;

			virtual bool Load(const ResourceDirectories& directories) = 0;
			virtual bool Setup();

			template <typename ...TArgs>
			void LinkToCallback(EclipseEvent<TArgs...>& callback, bool condition)
			{
				if (condition)
				{
					Setup();
				}
				else callback += [=] (TArgs... args) { Setup(); };
			}
		};
	}
}
