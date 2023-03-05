// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Support/Algorithms/BitScanForward.hpp>

namespace SA::UT::BSF
{
	TEST(BitScanForward, BitScanForward)
	{
		EXPECT_EQ(BitScanForward(1 << 0), 0u);
		EXPECT_EQ(BitScanForward(1 << 1), 1u);
		EXPECT_EQ(BitScanForward(1 << 2), 2u);
		EXPECT_EQ(BitScanForward(1 << 3), 3u);
		EXPECT_EQ(BitScanForward(1 << 4), 4u);
	}
}
