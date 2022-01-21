// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Support/Algorithms/DateTime.hpp>

namespace Sa::UT::DateTimeT
{
	TEST(DateTimeT, Constructors)
	{
		const DateTime d1;
		EXPECT_EQ(d1.second, 0u);
		EXPECT_EQ(d1.minute, 0u);
		EXPECT_EQ(d1.hour, 0u);
		EXPECT_EQ(d1.day, 0u);
		EXPECT_EQ(d1.month, 0u);
		EXPECT_EQ(d1.year, 0u);
		EXPECT_EQ(d1.weekday, 0u);

		const DateTime d2{ 45u, 10u, 2u, 17u, 12u, 2010u, 4u };
		EXPECT_EQ(d2.second, 45u);
		EXPECT_EQ(d2.minute, 10u);
		EXPECT_EQ(d2.hour, 2u);
		EXPECT_EQ(d2.day, 17u);
		EXPECT_EQ(d2.month, 12u);
		EXPECT_EQ(d2.year, 2010u);
		EXPECT_EQ(d2.weekday, 4u);

		tm t1{};
		t1.tm_sec = 45;
		t1.tm_min = 10;
		t1.tm_hour = 2;
		t1.tm_mday = 17;
		t1.tm_mon = 12 - 1;
		t1.tm_year = 2010 - 1900;
		t1.tm_wday = 4;
		const DateTime d3(t1);
		EXPECT_EQ(d2, d3);
	}

	TEST(DateTimeT, ToString)
	{
		const DateTime d1{ 45, 10, 2, 17, 12, 2010, 4 };
		EXPECT_EQ(ToString(d1), std::string("12.17.2010-2h10m45s"));
	}
}
