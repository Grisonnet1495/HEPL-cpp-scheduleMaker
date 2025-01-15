#ifndef TIMING_H
#define TIMING_H

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Time.h"
using namespace std;

namespace planning
{
	class Timing
	{
		// Opérateurs pour les flux
		friend ostream& operator<<(ostream& s, const Timing& t);
		friend istream& operator>>(istream& s, Timing& t);

		private:
			string day;
			Time start;
			Time duration;
			int comparisonT(const Timing& t2) const;
			int getDayNumber(const string d) const;

		public:
			// Constantes pour les jours de la semaine
			static const string MONDAY;
	        static const string TUESDAY;
	        static const string WEDNESDAY;
	        static const string THURSDAY;
	        static const string FRIDAY;
	        static const string SATURDAY;
	        static const string SUNDAY;
	        
			// Constructeurs et destructeur
			Timing();                    
			Timing(const Timing& t);           
			Timing(string day, const Time& s, const Time& duration);
			~Timing();

			// Getters
			string getDay() const;           
			Time getStart() const;        
			Time getDuration() const;      

			// Setters
			void setDay(const string d); 
			void setStart(const Time& s);   
			void setDuration(const Time& d);

			bool operator<(const Timing& t) const; 
		    bool operator>(const Timing& t) const;
		    bool operator==(const Timing& t) const;

			void display() const;
			const string toString() const;
			const string tuple() const;

			// Méthode pour vérifier si 2 timings se chevauchent
			bool intersect(const Timing& t) const;
	};
}

#endif
