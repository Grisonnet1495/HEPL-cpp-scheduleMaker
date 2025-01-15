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
		// Opérateurs pour ajouter/soustraire des minutes à un temps
		friend Time operator+(int minutesNbr, Time t);
		friend Time operator-(int minutesNbr, Time t);

		// Opérateurs pour les flux (affichage/lecture)
		friend ostream& operator<<(ostream& s, const Time& t);
		friend istream& operator>>(istream& s, Time& t);

	private:
		int hour;
		int minute;

		// Méthode pour comparer deux objets Time
		int comparisonT(const Time& t) const;

	public:
      	// Constructeurs et destructeur		
		Time();
		Time(const Time& t);    
		Time(int h, int m);       
		Time(int duree);          
		~Time();                 

		// Getters
		int getHour() const;      
		int getMinute() const;    

		// Setters
		void setHour(int h);      
		void setMinute(int m);     

		void display() const;   
		const string toString() const; 

		// Opérateurs d'affectation et d'arithmétique
		Time& operator=(const Time& t);
		Time operator+(int minutesNbr);
		Time operator+(const Time& t2);
		Time operator-(int minutesNbr);
		Time operator-(const Time& t2);

		// Opérateurs de comparaison
		bool operator<(const Time& t) const;
		bool operator<=(const Time& t) const;
		bool operator>(const Time& t) const;
		bool operator>=(const Time& t) const;
		bool operator==(const Time& t) const;

		// Opérateurs d'incrémentation/décrémentation
		Time operator++();
		Time operator++(int);
		Time operator--();
		Time operator--(int);
	};
}

#endif
