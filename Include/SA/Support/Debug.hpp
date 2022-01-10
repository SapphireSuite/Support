// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SUPPORT_DEBUG_GUARD
#define SAPPHIRE_SUPPORT_DEBUG_GUARD

/**
*	\file Support/Config.hpp
*
*	\brief <b>Debug</b> config file.
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
