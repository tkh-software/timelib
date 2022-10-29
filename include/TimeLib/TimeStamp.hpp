#ifndef TIMELIB_TIMESTAMP_HPP
#define TIMELIB_TIMESTAMP_HPP

#include "Time.hpp"
#include <string>

namespace tl
{
	enum class TimestampPrec : short
	{
		SECONDS,
		MILLISECONDS,
		MICROSECONDS,
		NANOSECONDS
	};

	TIMELIB_API std::string unix2stamp(const Time& unixtime, const std::string& delimiter = "T", const std::string& suffix = "", TimestampPrec prec = TimestampPrec::SECONDS);
	TIMELIB_API Time stamp2unix(const std::string& stamp, const std::string& delimiter = "T", TimestampPrec prec = TimestampPrec::SECONDS);
}

#endif
