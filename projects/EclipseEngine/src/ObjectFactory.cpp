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
			CreatorEntry* next = creatorList;
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