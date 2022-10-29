#include <TimeLib/DateTime.hpp>
#include <gtest/gtest.h>


TEST(DateTimeTests, ConvertFromTime) 
{
	tl::Time testTime = tl::Time::seconds(1667086581); //Sat Oct 29 2022 23:36:21 GMT+0000
	tl::DateTime dateTime = tl::DateTime::fromTime(testTime);

	EXPECT_EQ(dateTime.year, 2022);
	EXPECT_EQ(dateTime.month, 10);
	EXPECT_EQ(dateTime.day, 29);
	EXPECT_EQ(dateTime.hour, 23);
	EXPECT_EQ(dateTime.minute, 36);
	EXPECT_EQ(dateTime.second, 21);
}

TEST(DateTimeTests, ConvertToTime)
{
	tl::DateTime dateTime; //Sat Oct 29 2022 23:36:21 GMT+0000
	dateTime.year = 2022;
	dateTime.month = 10;
	dateTime.day = 29;
	dateTime.hour = 23;
	dateTime.minute = 36;
	dateTime.second = 21;

	tl::Time time = dateTime.toTime();

	EXPECT_EQ(time.asSeconds(), 1667086581);
}