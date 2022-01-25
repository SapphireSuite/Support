// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SUPPORT_FLAGS_GUARD
#define SAPPHIRE_SUPPORT_FLAGS_GUARD

#include <SA/Support/Variadics/IntSize.hpp>

/**
*	\file Flags.hpp
*
*	\brief \b Definition of Sapphire \b Flags type.
*
*	\ingroup Support_Variadics
*	\{
*/

namespace Sa
{
	/**
	*	\brief \e Template class for \b bit-flags enum management.
	*
	*	\tparam EnumT		EnumT type.
	*/
	template <typename EnumT>
	class Flags
	{
	public:
		/// Enum as bits type.
		using BitsT = UIntOfSize<sizeof(EnumT)>;

	private:

		/// bit-flags value.
		BitsT mBits = 0;

	public:


//{ Constructors

		/// \b Default constructor.
		Flags() = default;

		/**
		*	\brief <b>EnumT value</b> constructor.
		*
		*	\param[in] _enum	Enum value to assign to the handle.
		*/
		constexpr Flags(EnumT _enum) noexcept;

		/**
		*	\brief <b>Bits value</b> constructor.
		*
		*	\param[in] _bits	Bits value to assign to the handle.
		*/
		constexpr Flags(BitsT _bits) noexcept;

//}


//{ Equals

		/**
		*	\brief Perform \b equal operation between Flags.
		*
		*	\param[in] _other		Other flags.
		*
		*	\return result of equal operation.
		*/
		constexpr bool Equals(Flags _other) const noexcept;

		/**
		*	\brief Perform \b equal operation between Flags.
		*
		*	\param[in] _rhs		Other flags.
		*
		*	\return result of equal operation.
		*/
		constexpr bool operator==(Flags _rhs) const noexcept;

		/**
		*	\brief Perform \b not \b equal operation between Flags.
		*
		*	\param[in] _rhs		Other flags.
		*
		*	\return result of equal operation.
		*/
		constexpr bool operator!=(Flags _rhs) const noexcept;

		/**
		*	\brief \e Getter of bool if <b>all bit values</b> from flags are currently set.
		*
		*	\param[in] _flags	Flag bit values to check with.
		*
		*	\return true if bit values are set, otherwise false.
		*/
		constexpr bool AreSet(Flags _flags) const noexcept;

//}


//{ Setters

		/**
		*	\brief Add flag values to the current bit flags.
		*
		*	\param[in] _enum	Enum value to add.
		*
		*	\return this.
		*/
		Flags& Add(Flags _flags) noexcept;

		/**
		*	\brief Remove flag values to the current bit flags.
		*
		*	\param[in] _enum	Enum value to add.
		*
		*	\return this.
		*/
		Flags& Remove(Flags _flags) noexcept;

//}


//{ Operators

		/**
		*	\brief Perform operator \b not on current bit flags.
		*
		*	\return result of not operation.
		*/
		constexpr Flags operator~() const noexcept;

		/**
		*	\brief Perform \b OR operation.
		*
		*	\param[in] _rhs		Right operand.
		*
		*	\return OR result.
		*/
		constexpr Flags operator|(Flags _rhs) const noexcept;

		/**
		*	\brief Perform \b AND operation.
		*
		*	\param[in] _rhs		Right operand.
		*
		*	\return AND result.
		*/
		constexpr Flags operator&(Flags _rhs) const noexcept;

		/**
		*	\brief Perform \b XOR operation.
		*
		*	\param[in] _rhs		Right operand.
		*
		*	\return XOR result.
		*/
		constexpr Flags operator^(Flags _rhs) const noexcept;


		/**
		*	\brief Perform \b OR and \b assign operations.
		*
		*	\param[in] _rhs		Right operand.
		*
		*	\return this instance.
		*/
		Flags& operator|=(Flags _rhs);

		/**
		*	\brief Perform \b AND and \b assign operations.
		*
		*	\param[in] _rhs		Right operand.
		*
		*	\return this instance.
		*/
		Flags& operator&=(Flags _rhs);

		/**
		*	\brief Perform \b XOR and \b assign operations.
		*
		*	\param[in] _rhs		Right operand.
		*
		*	\return this instance.
		*/
		Flags& operator^=(Flags _rhs);


		/**
		*	\brief \e Cast operator to BitsT to get bit flags.
		*
		*	\return bit flags.
		*/
		explicit operator BitsT() const noexcept;
//}
	};

	template <typename EnumT>
	std::string ToString(Flags<EnumT> _flags);


	/**
	*	\brief Define flag operators for enum type.
	* 
	*	\param[in] _enumType	Type of enum.
	*/
	#define SA_DEFINE_ENUM_FLAGS(_enumType)\
	inline constexpr Sa::UIntOfSize<sizeof(_enumType)> operator|(_enumType _lhs, _enumType _rhs) noexcept\
	{\
		return static_cast<Sa::UIntOfSize<sizeof(_enumType)>>(_lhs) | static_cast<Sa::UIntOfSize<sizeof(_enumType)>>(_rhs);\
	}\
	\
	inline constexpr Sa::UIntOfSize<sizeof(_enumType)> operator|(Sa::UIntOfSize<sizeof(_enumType)> _lhs, _enumType _rhs) noexcept\
	{\
		return _lhs | static_cast<Sa::UIntOfSize<sizeof(_enumType)>>(_rhs);\
	}\
	\
	inline constexpr Sa::UIntOfSize<sizeof(_enumType)> operator&(_enumType _lhs, _enumType _rhs) noexcept\
	{\
		return static_cast<Sa::UIntOfSize<sizeof(_enumType)>>(_lhs) & static_cast<Sa::UIntOfSize<sizeof(_enumType)>>(_rhs);\
	}\
	inline constexpr Sa::UIntOfSize<sizeof(_enumType)> operator&(Sa::UIntOfSize<sizeof(_enumType)> _lhs, _enumType _rhs) noexcept\
	{\
		return _lhs & static_cast<Sa::UIntOfSize<sizeof(_enumType)>>(_rhs);\
	}\
	\
	inline constexpr Sa::UIntOfSize<sizeof(_enumType)> operator^(_enumType _lhs, _enumType _rhs) noexcept\
	{\
		return static_cast<Sa::UIntOfSize<sizeof(_enumType)>>(_lhs) ^ static_cast<Sa::UIntOfSize<sizeof(_enumType)>>(_rhs);\
	}\
	\
	inline constexpr Sa::UIntOfSize<sizeof(_enumType)> operator^(Sa::UIntOfSize<sizeof(_enumType)> _lhs, _enumType _rhs) noexcept\
	{\
		return _lhs ^ static_cast<Sa::UIntOfSize<sizeof(_enumType)>>(_rhs);\
	}\
	inline constexpr Sa::UIntOfSize<sizeof(_enumType)> operator~(_enumType _enum) noexcept\
	{\
		return ~static_cast<Sa::UIntOfSize<sizeof(_enumType)>>(_enum);\
	}
}

#include <SA/Support/Variadics/Flags.inl>


/** \} */

#endif // GUARD
