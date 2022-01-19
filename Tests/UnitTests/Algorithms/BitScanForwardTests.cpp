// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Support/Algorithms/BitScanForward.hpp>

namespace Sa::UT::BSF
{
	TEST(BitScanForward, BitScanForward)
	{
		EXPECT_EQ(BitScanForward(1 << 0), 0);
		EXPECT_EQ(BitScanForward(1 << 1), 1);
		EXPECT_EQ(BitScanForward(1 << 2), 2);
		EXPECT_EQ(BitScanForward(1 << 3), 3);
		EXPECT_EQ(BitScanForward(1 << 4), 4);
	}
}
