// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Support/Variadics/Flags.hpp>

namespace Sa::UT::FlagsTests
{
	enum class TestFlags : uint8_t
	{
		None = 0u,

		F1 = 1u << 0u,
		F2 = 1u << 1u,
		F3 = 1u << 2u,
		F4 = 1u << 3u,
		F5 = 1u << 4u,
		F6 = 1u << 5u,
		F7 = 1u << 6u,
		F8 = 1u << 7u,

		Max = 0xFF
	};
	SA_DEFINE_ENUM_FLAGS(TestFlags);

	TEST(FlagsTests, DefinedFlags)
	{
		// OR.
		const uint8_t enumBitsOR = TestFlags::F2 | TestFlags::F3;
		EXPECT_EQ(enumBitsOR, (static_cast<uint8_t>(TestFlags::F2) | static_cast<uint8_t>(TestFlags::F3)));

		const uint8_t bitsOR = enumBitsOR | TestFlags::F4;
		EXPECT_EQ(bitsOR, (static_cast<uint8_t>(TestFlags::F2) |
			static_cast<uint8_t>(TestFlags::F3) |
			static_cast<uint8_t>(TestFlags::F4)));


		// AND.
		const uint8_t enumBitsAND = TestFlags::F2 & TestFlags::F2;
		EXPECT_EQ(enumBitsAND, static_cast<uint8_t>(TestFlags::F2));

		const uint8_t bitsAND = enumBitsOR & TestFlags::F3;
		EXPECT_EQ(bitsAND, static_cast<uint8_t>(TestFlags::F3));


		// XOR.
		const uint8_t enumBitsXOR = TestFlags::F2 ^ TestFlags::F3;
		EXPECT_EQ(enumBitsXOR, (static_cast<uint8_t>(TestFlags::F2) ^ static_cast<uint8_t>(TestFlags::F3)));

		const uint8_t bitsXOR = enumBitsXOR ^ TestFlags::F2;
		EXPECT_EQ(bitsXOR, static_cast<uint8_t>(TestFlags::F3));
	}

	TEST(FlagsTests, Constructors)
	{
		const Flags<TestFlags> f1;
		EXPECT_EQ(static_cast<uint8_t>(f1), 0u);

		const Flags<TestFlags> f2(TestFlags::F2);
		EXPECT_EQ(static_cast<uint8_t>(f2), static_cast<uint8_t>(TestFlags::F2));

		const Flags<TestFlags> f3(TestFlags::F2 | TestFlags::F3);
		EXPECT_EQ(static_cast<uint8_t>(f3), static_cast<uint8_t>(TestFlags::F2 | TestFlags::F3));
	}

	TEST(FlagsTests, Equals)
	{
		const Flags<TestFlags> f1(TestFlags::F1);
		const Flags<TestFlags> f2(TestFlags::F2);

		EXPECT_TRUE(f1.Equals(TestFlags::F1));
		EXPECT_FALSE(f1.Equals(TestFlags::F2));

		EXPECT_TRUE(f1.Equals(f1));
		EXPECT_FALSE(f1.Equals(f2));

		EXPECT_EQ(f1, TestFlags::F1);
		EXPECT_NE(f1, TestFlags::F2);

		EXPECT_EQ(f1, f1);
		EXPECT_NE(f1, f2);

		const Flags<TestFlags> f3(TestFlags::F1 | TestFlags::F3);
		EXPECT_TRUE(f3.IsSet(TestFlags::F1));
		EXPECT_FALSE(f3.IsSet(TestFlags::F2));
		EXPECT_TRUE(f3.AreSet(TestFlags::F1 | TestFlags::F3));
		EXPECT_FALSE(f3.AreSet(TestFlags::F2 | TestFlags::F3));
	}

	TEST(FlagsTests, Setters)
	{
		Flags<TestFlags> f1(TestFlags::F1);

		f1.Add(TestFlags::F6);
		EXPECT_EQ(f1, (TestFlags::F1 | TestFlags::F6));

		f1.Remove(TestFlags::F1);
		EXPECT_EQ(f1, TestFlags::F6);


		f1.Set(TestFlags::F7);
		EXPECT_EQ(f1, TestFlags::F7);

		f1.Set(TestFlags::F4 | TestFlags::F7);
		EXPECT_EQ(f1, TestFlags::F4 | TestFlags::F7);


		f1 = TestFlags::F7;
		EXPECT_EQ(f1, TestFlags::F7);

		f1 = TestFlags::F4 | TestFlags::F7;
		EXPECT_EQ(f1, TestFlags::F4 | TestFlags::F7);
	}

	TEST(FlagsTests, OperatorNot)
	{
		Flags<TestFlags> f1(TestFlags::F2);
		EXPECT_EQ(~f1, (~TestFlags::F2));
	}

	TEST(FlagsTests, OperatorOR)
	{
		Flags<TestFlags> f1(TestFlags::F1);
		f1 |= TestFlags::F2;
		EXPECT_EQ(f1, (TestFlags::F1 | TestFlags::F2));

		f1 |= (TestFlags::F1 | TestFlags::F3);
		EXPECT_EQ(f1, (TestFlags::F1 | TestFlags::F2 | TestFlags::F3));
	}

	TEST(FlagsTests, OperatorAND)
	{
		Flags<TestFlags> f1(TestFlags::F1 | TestFlags::F2);
		f1 &= TestFlags::F2;
		EXPECT_EQ(f1, TestFlags::F2);

		f1 &= (TestFlags::F1 | TestFlags::F2);
		EXPECT_EQ(f1, TestFlags::F2);
	}

	TEST(FlagsTests, OperatorXOR)
	{
		Flags<TestFlags> f1(TestFlags::F1);
		f1 ^= TestFlags::F2;
		EXPECT_EQ(f1, (TestFlags::F1 ^ TestFlags::F2));

		f1 ^= (TestFlags::F1 ^ TestFlags::F3);
		EXPECT_EQ(f1, (TestFlags::F2 ^ TestFlags::F3));
	}
}
