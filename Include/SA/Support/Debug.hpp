// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SUPPORT_DEBUG_GUARD
#define SAPPHIRE_SUPPORT_DEBUG_GUARD

/**
*	\file Support/Debug.hpp
*
*	\brief \b Debug support definition file.
*
*	\ingroup Support
*	\{
*/

#if !defined(NDEBUG) || defined(_DEBUG)

	/// Sapphire Engine Debug preprocessor.
	#define SA_DEBUG 1

#else

	/// Sapphire Engine Debug preprocessor.
	#define SA_DEBUG 0

#endif


/** \} */

#endif // GUARD
