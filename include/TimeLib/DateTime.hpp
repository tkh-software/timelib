#ifndef TIMELIB_DATETIME_HPP
#define TIMELIB_DATETIME_HPP

#include "Time.hpp"

namespace tl
{
	class TIMELIB_API DateTime
	{
	public:
		
		int64_t year;
		int64_t month;
		int64_t day;
		int64_t hour;
		int64_t minute;
		int64_t second;

		int64_t year_day;
		int64_t week_day;

		static DateTime fromTime(const Time& time);
		Time toTime() const;
	};
}

#endif
