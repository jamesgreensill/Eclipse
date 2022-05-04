#pragma once
#include <mutex>

namespace Eclipse
{
	namespace Engine
	{
		template <typename TBase, typename TType, typename ...TArgs>
		class EclipseFunction
		{
		public:
			void operator()(TArgs ... args)
			{
				Invoke(args...);
			}

			EclipseFunction& operator+=(TType* (TBase::* pointer)(TArgs...))
			{
				return Set(pointer);
			}

		private:
			TType* (TBase::* functionPointer)(TArgs...) = nullptr;
			bool m_safe = false;
			mutable std::mutex m_threadLock;

			void Clear()
			{
				functionPointer = nullptr;
			}

			EclipseFunction& Set(TType* (TBase::* pointer)(TArgs...)) {

				EclipseFunction function;
				if (pointer)
				{
					function.functionPointer = pointer;
				}
				return function;
			}

			void Invoke(TArgs... args)
			{
				std::lock_guard<std::mutex> lock(m_threadLock);
				if (m_safe)
				{
					if (functionPointer)
					{
						functionPointer(args...);
					}
					return;
				}
				functionPointer(args...);
			}
		};
		template<typename TBase, typename TType>
		class EclipseFunction<TBase, TType, void>
		{
		public:
			void operator()()
			{
				Invoke();
			}

			EclipseFunction& operator=(TType* (TBase::*pointer)())
			{
				return Set(pointer);
			}

		private:
			TType* (TBase::* functionPointer)() = nullptr;
			bool m_safe = false;
			mutable std::mutex m_threadLock;

			void Clear()
			{
				functionPointer = nullptr;
			}

			EclipseFunction& Set(TType* (TBase::* pointer)()) {

				EclipseFunction function;
				if (pointer)
				{
					function.functionPointer = pointer;
				}
				return function;
			}

			void Invoke()
			{
				std::lock_guard<std::mutex> lock(m_threadLock);
				if (m_safe)
				{
					if (functionPointer)
					{
						functionPointer();
					}
					return;
				}
				functionPointer();
			}
		};
	}
}
