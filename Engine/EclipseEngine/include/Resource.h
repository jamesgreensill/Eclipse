#pragma once

#include "EclipseEvent.h"
#include "typedefs.h"

namespace Eclipse
{
	namespace Engine
	{
		struct Resource
		{

			/// <summary>
			/// ResouceKey associated with this resource.
			/// </summary>
			ResourceKey key;

			/// <summary>
			/// Abstract load function that will be called when a resource is created through the resource manager.
			/// </summary>
			virtual bool Load(const ResourceDirectories& directories) = 0;

			/// <summary>
			/// Virtual Setup function that will be called optionally if the resource requires setting up.
			/// </summary>
			virtual bool Setup();


			/// <summary>
			/// This function will link the resource to an EclipseEvent<TArgs...> event.
			/// when this event is called, it will called setup.
			/// </summary>
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
