#pragma once

/*
 *
 *	If I ever decide to make this a DLL.
 *
 */

#if defined(_WIN32)
#if defined(BUILD_LIBTYPE_SHARED)
#define ECAPI __declspec(dllexport)
#elif defined(USE_LIBTYPE_SHARED)
#define ECAPI __declspec(dllimport)
#endif
#endif
#ifndef ECAPI
#define ECAPI
#endif


#define NOT_IMPLEMENTED(message) External::Debug::DebugAPI::Error((std::string("Not Implemented: message") + #message).c_str());


/*
 *
 *	Used for external api linking.
 *
 */
#define EX_FUNCTION_DEC_nV(name, returnType, params, ...)\
				static ECAPI std::function<__VA_ARGS__(params)> name##_Pointer;\
				static inline ECAPI returnType name(params)\
				{\
					if (name##_Pointer)\
					{\
						name##_Pointer();\
					}\
				}
#define EX_FUNCTION_DEC_V(name, returnType, params, pname, ...)\
				static ECAPI std::function<__VA_ARGS__(params)> name##_Pointer;\
				static inline ECAPI returnType name(params pname)\
				{\
					if (name##_Pointer)\
					{\
						name##_Pointer(pname);\
					}\
				}

#define EX_FUNCTION_DEF(name, api, params, ...) std::function<__VA_ARGS__(params)> api::name##_Pointer = nullptr\

/*
 *
 *	For every item in collection, call item.function.
 *
 */
#define FFVCP(function, collection) \
	for(const auto& item : (collection))\
	{\
		item->function();\
	}

#define FFMCP(function, collection) \
	for(const auto& item : (collection))\
	{\
		item.second->function();\
	}


#include <iostream>

/*
	Custom to string wrapper.
*/
#define TO_STRING(message) #message
#define TOSTRING(message) std::string(#message)

#ifndef NDEBUG
#   define ASSERT(Expr, Msg) \
    Assert(#Expr, Expr, __FILE__, __LINE__, #Msg)
#else
#   define ASSERT(Expr, Msg)
#endif

inline void Assert(const char* expr_str, bool expr, const char* file, int line, const char* msg)
{
	if (!expr)
	{
		std::cerr << "Assert failed:\t" << msg << "\n"
			<< "Expected:\t" << expr_str << "\n"
			<< "Source:\t\t" << file << ", line " << line << "\n";
		abort();
	}
}
#define STATIC_ASSERT(condition, message) static_assert(condition, TO_STRING(STATIC_ASSERT: (message)))
#define IS_BASE_OF(base) static_assert(std::is_base_of<base,T>(), TO_STRING(T must be derived from: (base)))

// Custom Getter Macro inspired by C#.
#define GET(name, customCall) inline auto Get##name() const { customCall }
// Custom Setter Macro inspired by C#.
#define SET(name, type, customCall) inline void Set##name(const type##& value) { customCall }
#define SET_POINTER(name, type, customCall) inline void Set##name(type##* value) { customCall }

