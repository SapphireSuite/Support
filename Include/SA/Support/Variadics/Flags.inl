// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

namespace Sa
{
//{ Constructors

	template <typename EnumT>
	constexpr Flags<EnumT>::Flags(EnumT _enum) noexcept : mBits{ static_cast<BitsT>(_enum) }
	{
	}

	template <typename EnumT>
	constexpr Flags<EnumT>::Flags(BitsT _bits) noexcept : mBits{ _bits }
	{
	}

//}


//{ Equals

	template <typename EnumT>
	constexpr bool Flags<EnumT>::Equals(Flags _other) const noexcept
	{
		return mBits == _other.mBits;
	}

	template <typename EnumT>
	constexpr bool Flags<EnumT>::operator==(Flags _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	template <typename EnumT>
	constexpr bool Flags<EnumT>::operator!=(Flags _rhs) const noexcept
	{
		return !(*this == _rhs);
	}


	template <typename EnumT>
	constexpr bool Flags<EnumT>::AreSet(Flags _flags) const noexcept
	{
		return (mBits & _flags.mBits) == _flags.mBits;
	}
//}

//{ Setters

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::Add(Flags _flags) noexcept
	{
		mBits |= _flags.mBits;

		return *this;
	}

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::Remove(Flags _flags) noexcept
	{
		mBits &= ~_flags.mBits;

		return *this;
	}

//}

//{ Operators

	template <typename EnumT>
	constexpr Flags<EnumT> Flags<EnumT>::operator~() const noexcept
	{
		return Flags(~mBits);
	}

	template <typename EnumT>
	constexpr Flags<EnumT> Flags<EnumT>::operator|(Flags _rhs) const noexcept
	{
		return mBits | _rhs.mBits;
	}

	template <typename EnumT>
	constexpr Flags<EnumT> Flags<EnumT>::operator&(Flags _rhs) const noexcept
	{
		return mBits & _rhs.mBits;
	}

	template <typename EnumT>
	constexpr Flags<EnumT> Flags<EnumT>::operator^(Flags _rhs) const noexcept
	{
		return mBits ^ _rhs.mBits;
	}


	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::operator|=(Flags _rhs)
	{
		mBits |= _rhs.mBits;

		return *this;
	}

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::operator&=(Flags _rhs)
	{
		mBits &= _rhs.mBits;

		return *this;
	}

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::operator^=(Flags _rhs)
	{
		mBits ^= _rhs.mBits;

		return *this;
	}


	template <typename EnumT>
	Flags<EnumT>::operator BitsT() const noexcept
	{
		return mBits;
	}

//}


	template <typename EnumT>
	std::string ToString(Flags<EnumT> _flags)
	{
		typename Flags<EnumT>::BitsT bits = static_cast<typename Flags<EnumT>::BitsT>(_flags);

		std::string binaryStr;
		const size_t bitCount = sizeof(EnumT) * 8;

		for (size_t i = 1u; i <= bitCount; ++i)
		{
			// Parse bits
			if (bits & (1 << (bitCount - i)))
				binaryStr.append("1");
			else
				binaryStr.append("0");

			// Add spaces every 4 bits (and not at the end.)
			if (i % 4 == 0 && i != bitCount)
				binaryStr.append(" ");
		}

		return std::to_string(bits) + " {" + binaryStr + '}';
	}
}
