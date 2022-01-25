// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SUPPORT_INT_SIZE_GUARD
#define SAPPHIRE_SUPPORT_INT_SIZE_GUARD

#include <cstdint>

namespace Sa
{
	/**
	*	\brief \e Getter of the \c int type of the specified \b size (octet).
	*
	*	Helper template class to get the \c int type of the specified size.
	*
	*	\tparam size		Specified size.
	*
	*	\returns \b Type	Sized signed int type.
	*	\returns \b UType	Sized unsigned int type.
	*/
	template <uint8_t size>
	struct IntSize;


	/// \cond Internal

	/**
	*	\brief IntSize \e specialization for size 1 (octet).
	*
	*	\implements IntSize
	*/
	template <>
	struct IntSize<1>
	{
		/// Sized signed type.
		using Type = int8_t;

		/// Sized unsigned type.
		using UType = uint8_t;
	};

	/**
	*	\brief IntSize \e specialization for size 2 (octet).
	*
	*	\implements IntSize
	*/
	template <>
	struct IntSize<2>
	{
		/// Sized signed type.
		using Type = int16_t;

		/// Sized unsigned type.
		using UType = uint16_t;
	};

	/**
	*	\brief IntSize \e specialization for size 4 (octet).
	*
	*	\implements IntSize
	*/
	template <>
	struct IntSize<4>
	{
		/// Sized signed type.
		using Type = int32_t;

		/// Sized unsigned type.
		using UType = uint32_t;
	};

	/**
	*	\brief IntSize \e specialization for size 8 (octet).
	*
	*	\implements IntSize
	*/
	template <>
	struct IntSize<8>
	{
		/// Sized signed type.
		using Type = int64_t;

		/// Sized unsigned type.
		using UType = uint64_t;
	};

	/// \endcond Internal


	/**
	*	\brief Helper template alias of \e IntSize<size>::Type.
	*
	*	\tparam size	Specified size.
	*/
	template <uint8_t size>
	using IntOfSize = typename IntSize<size>::Type;

	/**
	*	\brief Helper template alias of \e IntSize<size>::UType.
	*
	*	\tparam size	Specified size.
	*/
	template <uint8_t size>
	using UIntOfSize = typename IntSize<size>::UType;
}

#endif // GUARD
