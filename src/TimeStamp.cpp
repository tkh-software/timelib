#include <TimeLib/TimeStamp.hpp>
#include <time.h>
#include <iomanip>
#include <sstream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#define timegm _mkgmtime
#endif

namespace tl
{
	std::string unix2stamp(const Time& unixtime, const std::string& delimiter, const std::string& suffix, TimestampPrec prec)
	{
		char buff[28];
		time_t tt = unixtime.asSeconds();

		std::string format = "%Y-%m-%d";
		format += delimiter;
		format += "%H:%M:%S";

		tm* tmp = gmtime(&tt);
		strftime(buff, 28, format.c_str(), tmp);

		std::stringstream ss;
		ss << buff;
		if(prec == TimestampPrec::MILLISECONDS)
			ss << "." << std::setfill('0') << std::setw(3) << unixtime.asMilliseconds() - (unixtime.asSeconds() * 1000);
		else if(prec == TimestampPrec::MICROSECONDS)
			ss << "." << std::setfill('0') << std::setw(6) << unixtime.asMicroseconds() - (unixtime.asSeconds() * 1000000);
		else if (prec == TimestampPrec::NANOSECONDS)
			ss << "." << std::setfill('0') << std::setw(9) << unixtime.asNanoseconds() - (unixtime.asSeconds() * 1000000000);
		ss << suffix;

		return ss.str();
	}

	Time stamp2unix(const std::string& stamp, const std::string& delimiter, TimestampPrec prec)
	{
		struct std::tm tm;

		std::string format = "%Y-%m-%d";
		format += delimiter;
		format += "%H:%M:%S";

		std::istringstream ss(stamp);
		ss >> std::get_time(&tm, format.c_str());
		int64_t time = timegm(&tm);

		Time result = Time::seconds(time);

		size_t ppos = stamp.find_last_of('.');

		if (ppos != std::string::npos)
		{
			if (prec == TimestampPrec::MILLISECONDS)
				result += Time::milliseconds(std::stoll(stamp.substr(ppos + 1, 3)));
			else if (prec == TimestampPrec::MICROSECONDS)
				result += Time::microseconds(std::stoll(stamp.substr(ppos + 1, 6)));
			else if (prec == TimestampPrec::NANOSECONDS)
				result += Time::nanoseconds(std::stoll(stamp.substr(ppos + 1, 9)));
		}

		return result;
	}
}
