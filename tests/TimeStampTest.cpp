#include <TimeLib/TimeStamp.hpp>
#include <gtest/gtest.h>


TEST(TimeStampTests, ConvertFromTime) 
{
	tl::Time testTime = tl::Time::seconds(1667086581); //Sat Oct 29 2022 23:36:21 GMT+0000
	std::string timestamp = tl::unix2stamp(testTime);

	EXPECT_EQ(timestamp, "2022-10-29T23:36:21");
}

TEST(TimeStampTests, ConvertFromTimeMaxPrec)
{
	tl::Time testTime = tl::Time::nanoseconds(1667086581888777666); //Sat Oct 29 2022 23:36:21 GMT+0000
	std::string timestamp = tl::unix2stamp(testTime, "T", "Z", tl::TimestampPrec::NANOSECONDS);

	EXPECT_EQ(timestamp, "2022-10-29T23:36:21.888777666Z");
}

TEST(TimeStampTests, ConvertToTime)
{
	std::string timestamp = "2022-10-29T23:36:21";
	tl::Time time = tl::stamp2unix(timestamp);

	EXPECT_EQ(time.asSeconds(), 1667086581);
}

TEST(TimeStampTests, ConvertToTimeMaxPrec)
{
	std::string timestamp = "2022-10-29T23:36:21.888777666Z";
	tl::Time time = tl::stamp2unix(timestamp, "T", tl::TimestampPrec::NANOSECONDS);

	EXPECT_EQ(time.asNanoseconds(), 1667086581888777666);
}