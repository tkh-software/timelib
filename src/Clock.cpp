#include <TimeLib/Clock.hpp>
#include <chrono>

namespace tl
{
	Clock::Clock()
	{
		restart();
	}

	Time Clock::restart()
	{
		Time temp = getCurrTime() - _starttime;
		_starttime = getCurrTime();
		return temp;
	}

	Time Clock::getCurrTime()
	{
		Time temp = Time::nanoseconds(std::chrono::duration_cast<std::chrono::nanoseconds>
			(std::chrono::system_clock::now().time_since_epoch()).count());
		return temp;
	}

	Time Clock::getStartTime() const
	{
		return _starttime;
	}

	Time Clock::getElapsedTime() const
	{
		Time tmp = getCurrTime() - _starttime;
		return tmp;
	}
}
