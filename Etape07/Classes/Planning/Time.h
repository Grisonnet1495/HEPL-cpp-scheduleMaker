#ifndef TIME_H
#define TIME_H

#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

namespace planning
{
	class Time
	{
		friend Time operator+(int minutesNbr, Time t);
		friend Time operator-(int minutesNbr, Time t);
		friend ostream& operator<<(ostream& s, const Time& t);
		friend istream& operator>>(istream& s, Time& t);

		private:
			int hour;
			int minute;
			int comparisonT(const Time& t);

		public:
			Time();
			Time(const Time& t);
			Time(int h, int m);
			Time(int duree);
			~Time();

			int getHour() const;
			int getMinute() const;

			void setHour(int h);
			void setMinute(int m);

			void display() const;

			Time& operator=(const Time& t);
			Time operator+(int minutesNbr);
			Time operator+(const Time& t2);
			Time operator-(int minutesNbr);
			Time operator-(const Time& t2);
			int operator<(const Time& t);
		    int operator>(const Time& t);
		    int operator==(const Time& t);
		    Time operator++();
		    Time operator++(int);
		    Time operator--();
		    Time operator--(int);
	};
}

#endif
