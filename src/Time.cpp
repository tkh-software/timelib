#include <TimeLib/Time.hpp>

namespace tl
{
	Time::Time()
	{
		_time = 0;
	}

	Time::Time(const Time & temp)
	{
		_time = temp.asNanoseconds();
	}

	Time::Time(int64_t nanos)
	{
		_time = nanos;
	}

	Time Time::hours(double amount)
	{
		return Time::minutes(amount*60);
	}

	Time Time::minutes(double amount)
	{
		return Time::seconds(amount*60);
	}

	Time Time::seconds(int64_t amount)
	{
		return Time::milliseconds(amount*1000);
	}

	Time Time::milliseconds(int64_t amount)
	{
		return Time::microseconds(amount*1000);
	}

	Time Time::microseconds(int64_t amount)
	{
		return Time(amount*1000);
	}

	Time Time::nanoseconds(int64_t amount)
	{
		return Time(amount);
	}

	double Time::asDays() const
	{
		return asHours() / 24.;
	}

	double Time::asHours() const
	{
		return asMinutes() / 60.;
	}

	double Time::asMinutes() const
	{
		return static_cast<double>(asSeconds()) / 60.;
	}

	int64_t Time::asSeconds() const
	{
		return asMilliseconds() / 1000;
	}

	int64_t Time::asMilliseconds() const
	{
		return asMicroseconds() / 1000;
	}

	int64_t Time::asMicroseconds() const
	{
		return _time / 1000;
	}

	int64_t Time::asNanoseconds() const
	{
		return _time;
	}

	Time &Time::operator=(const Time & temp)
	{
		_time = temp.asNanoseconds();
		return *this;
	}

	bool operator==(Time left, Time right)
	{
		return (left.asNanoseconds() == right.asNanoseconds());
	}

	bool operator!=(Time left, Time right)
	{
		return (left.asNanoseconds() != right.asNanoseconds());
	}

	bool operator>=(Time left, Time right)
	{
		return (left.asNanoseconds() >= right.asNanoseconds());
	}

	bool operator<=(Time left, Time right)
	{
		return (left.asNanoseconds() <= right.asNanoseconds());
	}

	bool operator>(Time left, Time right)
	{
		return (left.asNanoseconds() > right.asNanoseconds());
	}

	bool operator<(Time left, Time right)
	{
		return (left.asNanoseconds() < right.asNanoseconds());
	}

	Time & operator+=(Time & left, Time right)
	{
		return left = left + right;
	}

	Time & operator-=(Time & left, Time right)
	{
		return left = left - right;
	}

	Time & operator/=(Time & left, Time right)
	{
		return left = left / right;
	}

	Time & operator*=(Time & left, Time right)
	{
		return left = left * right;
	}

	Time operator/(Time left, Time right)
	{
		return Time(left.asNanoseconds() / right.asNanoseconds());
	}

	Time operator*(Time left, Time right)
	{
		return Time(left.asNanoseconds() * right.asNanoseconds());
	}

	Time operator+(Time left, Time right)
	{
		return Time(left.asNanoseconds() + right.asNanoseconds());
	}

	Time operator-(Time left, Time right)
	{
		return Time(left.asNanoseconds() - right.asNanoseconds());
	}
}
