#pragma once
#include "EclipseEngine/include/EngineMacros.h"

namespace Eclipse
{
	namespace Debug
	{
		// Sends a formated log message to the console.
		ECAPI auto Log(const char* str) -> void;
		// Sends a formated debug log message to the console.
		ECAPI auto Debug(const char* str) -> void;
		// Sends a formated error log message to the console.
		ECAPI auto Error(const char* str) -> void;

		/*
		 *
		 *	Chosen convention
		 *	"FUNCTION NAME has not been implemented."
		 *
		 */
		ECAPI auto NotImplemented(const char* functionName) -> void;

#pragma region MACROS

// Static Assert to ensure a function that is not implemented is not called.
#define NOT_IMPLEMENTED(x) Core::Debug::NotImplemented(#x);

// Static Error Wrapper
#define E_ERROR(x) Core::Debug::Error(#x);
// Static Log Wrapper
#define LOG(x) Core::Debug::Log(#x);
// Static Debug Wrapper
#define DEBUG(x) Core::Debug::Debug(#x);

// Common Errors.
#define INDEX_OUT_OF_BOUNDS() E_ERROR(Index is out of bounds.)
#define NULL_REF() E_ERROR(Instance is nullptr.)
#define MAP_EMPLACE_FAIL(x) E_ERROR(#x Instance is nullptr.)
#define NO_ACTIVE_CAMERAS() E_ERROR(There are no active cameras in this scene.);
	}
}
