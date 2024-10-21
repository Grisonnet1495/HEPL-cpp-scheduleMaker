#include "Time.h"

using namespace std;

namespace planning
{
	// Constructeurs

	Time::Time()
	{
		#ifdef DEBUG
			cout << ">>> Appelle du constructeur par defaut de Time" << endl;
		#endif

		setHour(0);
		setMinute(0);
	}

	Time::Time(const Time& t)
	{
		#ifdef DEBUG
			cout << ">>> Appelle du constructeur de copie de Time" << endl;
		#endif

		setHour(t.hour);
		setMinute(t.minute);
	}

	Time::Time(int h, int m)
	{
		#ifdef DEBUG
			cout << ">>> Appelle du constructeur d'initialisation 1 de Time" << endl;
		#endif

		setHour(h);
		setMinute(m);
	}

	Time::Time(int duree)
	{
		#ifdef DEBUG
			cout << ">>> Appelle du constructeur d'initialisation 2 de Time" << endl;
		#endif

		setHour(duree / 60);
		setMinute(duree % 60);
	}

	// Destructeur

	Time::~Time()
	{
		#ifdef DEBUG
			cout << ">>> Appelle du destructeur par defaut de Time" << endl;
		#endif
	}

	// Getters

	int Time::getHour() const
	{
		return hour;
	}

	int Time::getMinute() const
	{
		return minute;
	}

	// Setters

	void Time::setHour(int h)
	{
		if (h < 0 || h > 23) return;
		hour = h;
	}

	void Time::setMinute(int m)
	{
		if (m < 0 || m > 59) return;
		minute = m;
	}

	// Méthodes d'instances

	void Time::display() const
	{
		if (hour < 10) cout << "0";
		cout << hour << "h";
		if (minute < 10) cout << "0";
		cout << minute;
	}

	// Méthodes de surcharge d'opérateurs

	Time& Time::operator=(const Time& t)
	{
		hour = t.hour;
		minute = t.minute;

		return (*this);
	}

	Time Time::operator+(int minutesNbr)
	{
		Time t(*this);

		if (minutesNbr < 0) return t; 

		int minutesTotal = t.minute + minutesNbr;
		t.minute = minutesTotal % 60;
		t.hour = (t.hour + minutesTotal / 60) % 24;

		return t;
	}

	Time Time::operator+(const Time& t2)
	{
		Time t1(*this);

		int minutesTotal = t1.minute + t2.minute;
		t1.minute = minutesTotal % 60;
		t1.hour = ((t1.hour + minutesTotal / 60) + t2.hour) % 24;

		return t1; 
	}

	Time operator+(int minutesNbr, Time t)
	{
		return t + minutesNbr;
	}

	Time Time::operator-(int minutesNbr)
	{
		Time t(*this);

		if (minutesNbr < 0) return t;

		int totalMinutes = (t.hour * 60) + t.minute;

		totalMinutes -= minutesNbr;

		while (totalMinutes < 0)
	    {
	        totalMinutes += 1440; // Car 24 heures est égal à 1440 minutes.
	    }

	    t.minute = totalMinutes % 60;
	    t.hour = (totalMinutes / 60) % 24;

		return t;
	}

	Time Time::operator-(const Time& t2)
	{
		Time t1(*this);

	    int minutesTotal1 = t1.hour * 60 + t1.minute;
	    int minutesTotal2 = t2.hour * 60 + t2.minute;

	    int minutesTotal = minutesTotal1 - minutesTotal2;

	    while (minutesTotal < 0)
	    {
	        minutesTotal += 1440; // Car 24 heures est égal à 1440 minutes.
	    }

	    t1.minute = minutesTotal % 60;
	    t1.hour = (minutesTotal / 60) % 24;

	    return t1;
	}

	Time operator-(int minutesNbr, Time t)
	{
		return Time(minutesNbr) - t;
	}

	int Time::comparisonT(const Time& t)
	{
		if (hour < t.hour) return -1;
		if (hour > t.hour) return 1;
		// Si heures égales
		if (minute < t.minute) return -1;
		if (minute > t.minute) return 1;

		// Si minutes égales
		return 0;
	}

	int Time::operator<(const Time& t)
	{
		return comparisonT(t) == -1;
	}

	int Time::operator>(const Time& t)
	{
		return comparisonT(t) == 1;
	}

	int Time::operator==(const Time& t)
	{
		return comparisonT(t) == 0;
	}

	ostream& operator<<(ostream& s, const Time& t)
	{
		if (t.getHour() < 10) s << "0";
		s << t.getHour() << "h";
		if (t.getMinute() < 10) s << "0";
		s << t.getMinute(); 
		return s; 
	}

	istream& operator>>(istream& s, Time& t)
	{
		int h, m;
		char separator;

		s >> h >> separator >> m;

		while (separator != 'h' || h < 0 || h > 23 || m < 0 || m > 59)
		{
			cout << "Entree incorrecte. Veuillez entrer l'heure sous le format hh:h:mm (ex : 14h20)." << endl;
			while (s.get() != '\n');
			s >> h >> separator >> m;
		}
		
		t.setHour(h);
		t.setMinute(m);
		return s;
	}

	Time Time::operator++()
	{
		(*this) = (*this) + 30;

		return (*this);
	}

	Time Time::operator++(int)
	{
		Time Ttmp(*this);
		(*this) = (*this) + 30; 

		return Ttmp;
	}

	Time Time::operator--()
	{
		(*this) = (*this) - 30;

		return (*this);
	}

	Time Time::operator--(int)
	{
		Time Ttmp(*this);
		(*this) = (*this) - 30; 

		return Ttmp;
	}
}
