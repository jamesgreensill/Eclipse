#include <pch.h>
#include "ObjectFactory.h"
#include "Object.h"

namespace Eclipse
{
	namespace Engine
	{
		CreatorEntry* ObjectFactory::creatorList = nullptr;

		int ObjectFactory::RegisterCreator(std::type_index type, Object* (*constructor)())
		{
			// get the next entry position.
			CreatorEntry* next = creatorList;
			// create the new entry.
			auto tmp = new CreatorEntry{
				next,type,constructor
			};
			creatorList = tmp;
			if (tmp)
				return 1;
			return 0;
		}
	}
}