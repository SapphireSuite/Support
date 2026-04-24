// Copyright (c) 2024 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SUPPORT_FLAGS_GUARD
#define SAPPHIRE_SUPPORT_FLAGS_GUARD

#include <cstdint>

/**
*	\file Flags.hpp
*
*	\brief \b Flags support file.
*
*	Define preprocessor for enum class to flag support.
*
*	\ingroup Support
*	\{
*/


namespace SA
{
	/// \cond Internal

	namespace Intl
	{
		template <uint32_t size>
		struct IntSizeT;

		template <>
		struct IntSizeT<sizeof(int8_t)>
		{
			using intT = int8_t;
			using uintT = uint8_t;
		};

		template <>
		struct IntSizeT<sizeof(int16_t)>
		{
			using intT = int16_t;
			using uintT = uint16_t;
		};

		template <>
		struct IntSizeT<sizeof(int32_t)>
		{
			using intT = int32_t;
			using uintT = uint32_t;
		};

		template <>
		struct IntSizeT<sizeof(int64_t)>
		{
			using intT = int64_t;
			using uintT = uint64_t;
		};

		#define __SA_EINT(EnumType) SA::Intl::IntSizeT<sizeof(EnumType)>::intT
		#define __SA_EUINT(EnumType) SA::Intl::IntSizeT<sizeof(EnumType)>::uintT
	}

	#define __SA_DEFINE_ENUM_CLASS_FLAGS_OP(EnumType, op)\
		inline constexpr __SA_EUINT(EnumType) operator op(EnumType _e1, EnumType _e2) {\
			return static_cast<__SA_EUINT(EnumType)>(_e1) op static_cast<__SA_EUINT(EnumType)>(_e2);\
		}\
		inline constexpr __SA_EUINT(EnumType) operator op(__SA_EUINT(EnumType) _flags, EnumType _e) {\
			return _flags op static_cast<__SA_EUINT(EnumType)>(_e);\
		}\
		inline constexpr __SA_EUINT(EnumType) operator op(EnumType _e, __SA_EUINT(EnumType) _flags) {\
			return static_cast<__SA_EUINT(EnumType)>(_e) op _flags;\
		}\
		inline __SA_EUINT(EnumType)& operator op##=(__SA_EUINT(EnumType)& _flags, EnumType _e) {\
			return _flags op##= static_cast<__SA_EUINT(EnumType)>(_e);\
		}
	

	/// \endcond

	#define SA_DEFINE_ENUM_CLASS_FLAGS(EnumType)\
		__SA_DEFINE_ENUM_CLASS_FLAGS_OP(EnumType, &)\
		__SA_DEFINE_ENUM_CLASS_FLAGS_OP(EnumType, |)\
		__SA_DEFINE_ENUM_CLASS_FLAGS_OP(EnumType, ^)\
		inline constexpr __SA_EUINT(EnumType) operator ~(EnumType _e){\
			return ~static_cast<__SA_EUINT(EnumType)>(_e);\
		}\
		inline constexpr __SA_EUINT(EnumType) operator +(EnumType _e){\
			return static_cast<__SA_EUINT(EnumType)>(_e);\
		}
}


/** \} */

#endif // SAPPHIRE_SUPPORT_FLAGS_GUARD
