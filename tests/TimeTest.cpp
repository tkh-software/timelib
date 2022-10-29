#include <TimeLib/Time.hpp>
#include <gtest/gtest.h>


TEST(TimeTests, ConvertFromToNanoseconds) 
{
	tl::Time testTime = tl::Time::nanoseconds(1667086581888777666); //Sat Oct 29 2022 23:36:21 GMT+0000
	EXPECT_EQ(testTime.asNanoseconds(), 1667086581888777666);
}

TEST(TimeTests, ConvertFromToMicroseconds)
{
	tl::Time testTime = tl::Time::microseconds(1667086581888777); //Sat Oct 29 2022 23:36:21 GMT+0000
	EXPECT_EQ(testTime.asMicroseconds(), 1667086581888777);
}

TEST(TimeTests, ConvertFromToMilliseconds)
{
	tl::Time testTime = tl::Time::milliseconds(1667086581888); //Sat Oct 29 2022 23:36:21 GMT+0000
	EXPECT_EQ(testTime.asMilliseconds(), 1667086581888);
}

TEST(TimeTests, ConvertFromToSeconds)
{
	tl::Time testTime = tl::Time::seconds(1667086581); //Sat Oct 29 2022 23:36:21 GMT+0000
	EXPECT_EQ(testTime.asSeconds(), 1667086581);
}

TEST(TimeTests, ConvertFromToMinutes)
{
	tl::Time testTime = tl::Time::minutes(300);
	EXPECT_EQ(testTime.asMinutes(), 300);
}

TEST(TimeTests, ConvertFromToHours)
{
	tl::Time testTime = tl::Time::hours(300);
	EXPECT_EQ(testTime.asHours(), 300);
}

TEST(TimeTests, ConvertFromHoursToDays)
{
	tl::Time testTime = tl::Time::hours(72);
	EXPECT_EQ(testTime.asDays(), 3);
}