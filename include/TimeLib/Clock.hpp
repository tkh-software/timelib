#ifndef TIMELIB_CLOCK_HPP
#define TIMELIB_CLOCK_HPP

#include "Time.hpp"

namespace tl
{
	class TIMELIB_API Clock
	{
	private:
		Time _starttime;

	public:
		Clock();
		Time restart();
		static Time getCurrTime();
		Time getStartTime() const;
		Time getElapsedTime() const;
	};
}

#endif