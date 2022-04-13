// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SUPPORT_GLFW_API_GUARD
#define SAPPHIRE_SUPPORT_GLFW_API_GUARD


/**
*	\file GLFW.hpp
*
*	\brief \b GLFW include support file.
*
*	\ingroup Support
*	\{
*/


#ifndef SA_GLFW

	/// Sapphire Engine enable GLFW preprocessor.
	#define SA_GLFW 0

#endif


#if SA_GLFW

	// Include Vulkan before GLFW (if enabled).
	#include <SA/Support/API/Vulkan.hpp>

	#include <GLFW/glfw3.h>

#endif


/** \} */

#endif // GUARD
