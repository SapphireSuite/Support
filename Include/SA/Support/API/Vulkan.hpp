// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SUPPORT_VULKAN_API_GUARD
#define SAPPHIRE_SUPPORT_VULKAN_API_GUARD

/**
*	\file Vulkan.hpp
*
*	\brief \b vulkan.h support file.
*
*	\ingroup Support
*	\{
*/


#ifndef SA_VULKAN

	/// Sapphire Engine enable Vulkan preprocessor.
	#define SA_VULKAN 0

#endif


#if SA_VULKAN

	#include <vulkan/vulkan.h>

#endif


/**
*	Useful Documentations:
* 
*	https://vulkan-tutorial.com/
*	https://developer.nvidia.com/blog/vulkan-dos-donts/
*/


/** \} */

#endif // GUARD
