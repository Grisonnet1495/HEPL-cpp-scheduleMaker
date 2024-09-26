#ifndef TIME
#define TIME

#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

class Time
{
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
};

#endif
