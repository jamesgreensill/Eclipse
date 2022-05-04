#pragma once

namespace Eclipse
{
	namespace Engine
	{
		template<typename T>
		class ESingle
		{
		public:
			static T& Instance()
			{
				static T Instance{ token{} };
				return Instance;
			}

			ESingle(const ESingle&) = delete;
			ESingle operator= (const ESingle) = delete;
		protected:
			struct token {};
			ESingle() {}
		};
	}
}
