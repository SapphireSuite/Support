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
	constexpr bool Flags<EnumT>::Equals(EnumT _enum) const noexcept
	{
		return Equals(static_cast<BitsT>(_enum));
	}

	template <typename EnumT>
	constexpr bool Flags<EnumT>::Equals(BitsT _bits) const noexcept
	{
		return mBits == _bits;
	}


	template <typename EnumT>
	constexpr bool Flags<EnumT>::IsSet(EnumT _enum) const noexcept
	{
		return mBits & static_cast<BitsT>(_enum);
	}

	template <typename EnumT>
	constexpr bool Flags<EnumT>::AreSet(BitsT _bits) const noexcept
	{
		return (mBits & _bits) == _bits;
	}


	template <typename EnumT>
	constexpr bool Flags<EnumT>::operator==(EnumT _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	template <typename EnumT>
	constexpr bool Flags<EnumT>::operator!=(EnumT _rhs) const noexcept
	{
		return !Equals(_rhs);
	}

//}

//{ Setters

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::Set(EnumT _enum) noexcept
	{
		return Set(static_cast<BitsT>(_enum));
	}

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::Set(BitsT _bits) noexcept
	{
		mBits = _bits;

		return *this;
	}


	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::Add(EnumT _enum) noexcept
	{
		return Add(static_cast<BitsT>(_enum));
	}

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::Add(BitsT _bits) noexcept
	{
		mBits |= _bits;

		return *this;
	}

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::Remove(EnumT _enum) noexcept
	{
		return Remove(static_cast<BitsT>(_enum));
	}

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::Remove(BitsT _bits) noexcept
	{
		mBits &= ~_bits;

		return *this;
	}


	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::operator=(EnumT _rhs) noexcept
	{
		return Set(_rhs);
	}

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::operator=(BitsT _rhs) noexcept
	{
		return Set(_rhs);
	}
//}

//{ Operators

	template <typename EnumT>
	constexpr Flags<EnumT> Flags<EnumT>::operator~() const noexcept
	{
		return Flags(~mBits);
	}


	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::operator|=(EnumT _rhs) noexcept
	{
		return *this |= static_cast<BitsT>(_rhs);
	}

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::operator|=(BitsT _rhs) noexcept
	{
		mBits |= _rhs;

		return *this;
	}

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::operator&=(EnumT _rhs) noexcept
	{
		return *this &= static_cast<BitsT>(_rhs);
	}

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::operator&=(BitsT _rhs) noexcept
	{
		mBits &= _rhs;

		return *this;
	}

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::operator^=(EnumT _rhs) noexcept
	{
		return *this ^= static_cast<BitsT>(_rhs);
	}

	template <typename EnumT>
	Flags<EnumT>& Flags<EnumT>::operator^=(BitsT _rhs) noexcept
	{
		mBits ^= _rhs;

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
