#ifndef TIMELIB_TIME_HPP
#define TIMELIB_TIME_HPP

#include <cstdint>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#define TIMELIB_API __declspec(dllexport)
#else
	#define TIMELIB_API
#endif

namespace tl
{
	class TIMELIB_API Time
	{
	private:
		int64_t _time;

	public:
		Time();
		Time(const Time& temp);
		Time(int64_t nanos);

		static Time hours(double amount);
		static Time minutes(double amount);
		static Time seconds(int64_t amount);
		static Time milliseconds(int64_t amount);
		static Time microseconds(int64_t amount);
		static Time nanoseconds(int64_t amount);

		double asDays() const;
		double asHours() const;
		double asMinutes() const;
		int64_t asSeconds() const;
		int64_t asMilliseconds() const;
		int64_t asMicroseconds() const;
		int64_t asNanoseconds() const;

		Time &operator =(const Time &temp);
	};

	TIMELIB_API bool operator ==(Time left, Time right);
	TIMELIB_API bool operator !=(Time left, Time right);
	TIMELIB_API bool operator >=(Time left, Time right);
	TIMELIB_API bool operator <=(Time left, Time right);
	TIMELIB_API bool operator >(Time left, Time right);
	TIMELIB_API bool operator <(Time left, Time right);
	TIMELIB_API Time& operator +=(Time &left, Time right);
	TIMELIB_API Time& operator -=(Time &left, Time right);
	TIMELIB_API Time& operator /=(Time &left, Time right);
	TIMELIB_API Time& operator *=(Time &left, Time right);
	TIMELIB_API Time operator /(Time left, Time right);
	TIMELIB_API Time operator *(Time left, Time right);
	TIMELIB_API Time operator +(Time left, Time right);
	TIMELIB_API Time operator -(Time left, Time right);
}

#endif
