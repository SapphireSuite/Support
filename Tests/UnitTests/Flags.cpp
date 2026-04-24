// Copyright (c) 2024 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Support/Flags.hpp>

namespace SA::UT::Flags
{
	enum class MyEnumFlag : uint8_t
	{
		MyFlag1 = (1 << 0),
		MyFlag2 = (1 << 1),
		MyFlag3 = (1 << 2),
		MyFlag4 = (1 << 3),
		MyFlag5 = (1 << 4),
	};

	SA_DEFINE_ENUM_CLASS_FLAGS(MyEnumFlag);


	TEST(Flags, FlagsAND)
	{
		constexpr uint8_t flags1 = MyEnumFlag::MyFlag1 & MyEnumFlag::MyFlag2;
		EXPECT_EQ((flags1), 0u);

		constexpr uint8_t flags2 = MyEnumFlag::MyFlag3 & 4u;
		EXPECT_EQ(flags2, 4u);

		constexpr uint8_t flags3 = 4u & MyEnumFlag::MyFlag3;
		EXPECT_EQ(flags3, 4u);

		uint8_t flags4 = 7u;
		flags4 &= MyEnumFlag::MyFlag1;
		EXPECT_EQ(flags4, 1u);
	}

	TEST(Flags, FlagsOR)
	{
		constexpr uint8_t flags1 = MyEnumFlag::MyFlag1 | MyEnumFlag::MyFlag2;
		EXPECT_EQ((flags1), 3u);

		constexpr uint8_t flags2 = MyEnumFlag::MyFlag3 | 3u;
		EXPECT_EQ(flags2, 7u);

		constexpr uint8_t flags3 = 3u | MyEnumFlag::MyFlag3;
		EXPECT_EQ(flags3, 7u);

		uint8_t flags4 = 6u;
		flags4 |= MyEnumFlag::MyFlag1;
		EXPECT_EQ(flags4, 7u);
	}

	TEST(Flags, FlagsXOR)
	{
		constexpr uint8_t flags1 = MyEnumFlag::MyFlag1 ^ MyEnumFlag::MyFlag2;
		EXPECT_EQ((flags1), 3u);

		constexpr uint8_t flags2 = MyEnumFlag::MyFlag3 ^ 4u;
		EXPECT_EQ(flags2, 0u);

		constexpr uint8_t flags3 = 4u ^ MyEnumFlag::MyFlag3;
		EXPECT_EQ(flags3, 0u);

		uint8_t flags4 = 6u;
		flags4 ^= MyEnumFlag::MyFlag2;
		EXPECT_EQ(flags4, 4u);
	}

	TEST(Flags, FlagsInv)
	{
		constexpr uint8_t flags1 = ~MyEnumFlag::MyFlag2;
		EXPECT_EQ((flags1), 0xFD);
	}

	TEST(Flags, FlagsCast)
	{
		constexpr uint8_t flags1 = +MyEnumFlag::MyFlag2;
		EXPECT_EQ((flags1), 2);
	}
}
