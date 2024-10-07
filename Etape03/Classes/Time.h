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
		friend Time operator-(int minutesNbr, Time T);
		friend ostream& operator<<(ostream& s, const Time& T);
		friend istream& operator>>(istream& s, Time& T);

		private:
			int hour;
			int minute;
			int comparisonT(const Time& T);

		public:
			Time();
			Time(const Time& T);
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
			Time operator-(int minutesNbr);
			Time operator-(const Time& T2);
			int operator<(const Time& T);
		    int operator>(const Time& T);
		    int operator==(const Time& T);
		    Time operator++();
		    Time operator++(int);
		    Time operator--();
		    Time operator--(int);
	};
}

#endif
