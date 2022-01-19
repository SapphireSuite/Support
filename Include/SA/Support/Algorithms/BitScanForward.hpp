// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SUPPORT_BIT_SCAN_FORWARD_GUARD
#define SAPPHIRE_SUPPORT_BIT_SCAN_FORWARD_GUARD

#include <cstdint>

#include <SA/Support/Compilers.hpp>

#if SA_MSVC

	#include <intrin.h>

#endif


/**
*	\file BitScanForward.hpp
*
*	\brief \b BitScanForward \e cross-platform implementation.
*
*	\ingroup Support_Algorithms
*	\{
*/

namespace Sa
{
	/**
	*	\brief \e Cross-platform \b BitScanForward implementation.
	* 
	*	\param[in] _mask	Mask to scan.
	* 
	*	\return Index of first set bit or -1 if no set bit found.
	*/
	inline uint32_t BitScanForward(uint32_t _mask)
	{
		if (!_mask)
			return ~uint32_t();

		unsigned long index = 0u;

#if SA_MSVC

		_BitScanForward64(&index, _mask);
#else

		// __builtin_ffs returns 1 + index if non zero.
		index = __builtin_ffs(_mask) - 1;
#endif

		return static_cast<uint32_t>(index);
	}
}

/** \} */

#endif // GUARD
