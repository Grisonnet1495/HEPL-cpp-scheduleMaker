#ifndef TIMING
#define TIMING

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Time.h"
using namespace std;

namespace planning
{
	class Timing
	{
		private:
			string day;
			Time start;
			Time duration;
		public:
			static const string MONDAY;
	        static const string TUESDAY;
	        static const string WEDNESDAY;
	        static const string THURSDAY;
	        static const string FRIDAY;
	        static const string SATURDAY;
	        static const string SUNDAY;
	        
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
}

#endif
