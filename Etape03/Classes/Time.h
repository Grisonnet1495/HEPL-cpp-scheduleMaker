#ifndef TIME
#define TIME

#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

namespace planning
{
	class Time
	{
		friend Time operator+(int minutesNbr, Time T);

		private:
			int hour;
			int minute;
		public:
			Time();
			Time(const Time &T);
			Time(int h, int m);
			Time(int duree);
			~Time();

			int getHour() const;
			int getMinute() const;

			void setHour(int h);
			void setMinute(int m);

			void display() const;

			Time& operator=(const Time& T);
			Time operator+(int minutesNbr);
			Time operator+(const Time& T2);
	};
}

#endif
