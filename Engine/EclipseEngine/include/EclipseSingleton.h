#pragma once
#include "BaseModel.h"

namespace Eclipse
{
	namespace Engine
	{
		template<typename T>
		class EclipseSingleton
		{
		public:
			static T& Instance()
			{
				static T Instance{ token{} };
				return Instance;
			}

			EclipseSingleton(const EclipseSingleton&) = delete;
			EclipseSingleton operator= (const EclipseSingleton) = delete;
		protected:
			struct token {};
			EclipseSingleton() {}
		};
	}
}
