#ifndef TIMING
#define TIMING

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Time.h"
using namespace std;

class Timing
{
	private:
		string day;
		Time start;
		Time duration;
	public:
		Timing();
		Timing(const Timing &T);
		Timing(string day, const Time &s, const Time &duration);
		~Timing();

		string getDay() const;
		Time getStart() const;
		Time getDuration() const;

		void setDay(const string d);
		void setStart(const Time &s);
		void setDuration(const Time &d);

		void display() const;
};

#endif
