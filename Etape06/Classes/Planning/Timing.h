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
		friend ostream& operator<<(ostream& s, const Timing& t);
		friend istream& operator>>(istream& s, Timing& t);

		private:
			string day;
			Time start;
			Time duration;
			int comparisonT(const Timing& t2);

		public:
			static const string MONDAY;
	        static const string TUESDAY;
	        static const string WEDNESDAY;
	        static const string THURSDAY;
	        static const string FRIDAY;
	        static const string SATURDAY;
	        static const string SUNDAY;
	        
			Timing();
			Timing(const Timing& t);
			Timing(string day, const Time& s, const Time& duration);
			~Timing();

			string getDay() const;
			Time getStart() const;
			Time getDuration() const;

			void setDay(const string d);
			void setStart(const Time& s);
			void setDuration(const Time& d);
			int operator<(const Timing& t);
		    int operator>(const Timing& t);
		    int operator==(const Timing& t);

			void display() const;
			const string toString() const;
	};
}

#endif
