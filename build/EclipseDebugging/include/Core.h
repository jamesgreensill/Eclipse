#pragma once
#include "EclipseEngine/include/EngineMacros.h"

namespace Eclipse
{
	namespace Debug
	{
		ECAPI auto Log(const char* str) -> void;
		ECAPI auto Debug(const char* str) -> void;
		ECAPI auto Error(const char* str) -> void;

		/*
		 *
		 *	Chosen convention
		 *	"FUNCTION NAME has not been implemented."
		 *
		 */
		ECAPI auto NotImplemented(const char* functionName) -> void;

#pragma region MACROS

#define NOT_IMPLEMENTED(x) Core::Debug::NotImplemented(#x);

#define E_ERROR(x) Core::Debug::Error(#x);
#define LOG(x) Core::Debug::Log(#x);
#define DEBUG(x) Core::Debug::Debug(#x);

#define INDEX_OUT_OF_BOUNDS() E_ERROR(Index is out of bounds.)
#define NULL_REF() E_ERROR(Instance is nullptr.)
#define MAP_EMPLACE_FAIL(x) E_ERROR(#x Instance is nullptr.)
#define NO_ACTIVE_CAMERAS() E_ERROR(There are no active cameras in this scene.);
	}
}
