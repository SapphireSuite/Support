// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SUPPORT_MODULE_GUARD
#define SAPPHIRE_SUPPORT_MODULE_GUARD

#include <SA/Support/Platforms.hpp>

/**
*	\file ModuleAPI.hpp
*
*	\brief <b>API Module</b> support definition file.
*
*	Define API module import / export preprocessors.
*
*	\ingroup Support
*	\{
*/


#if SA_WIN

	/// Module export preprocessor.
	#define SA_MODUE_EXPORT __declspec(dllexport)

	/// Module import preprocessor.
	#define SA_MODUE_IMPORT __declspec(dllimport)

#elif SA_UNIX || SA_OSX || SA_ANDROID

	/// Module export preprocessor.
	#define SA_MODUE_EXPORT __attribute__((visibility("default")))

	/// Module import preprocessor.
	#define SA_MODUE_IMPORT

#endif


/** \} */


#endif // GUARD
