#include "Time.h"

using namespace std;

// Constructeurs
namespace planning
{
	Time::Time()
	{
		#ifdef DEBUG
			cout << ">>> Appelle du constructeur par defaut de Time" << endl;
		#endif

		setHour(0);
		setMinute(0);
	}

	Time::Time(const Time& T)
	{
		#ifdef DEBUG
			cout << ">>> Appelle du constructeur de copie de Time" << endl;
		#endif

		setHour(T.hour);
		setMinute(T.minute);
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
		cout << hour << "h" << minute;
	}

	// Méthodes de surcharge d'opérateurs

	Time& Time::operator=(const Time& T)
	{
		hour = T.hour;
		minute = T.minute;

		return (*this);
	}

	Time Time::operator+(int minutesNbr)
	{
		Time T(*this);

		if (minutesNbr < 0) return T; 

		int minutesTotal = T.minute + minutesNbr;
		T.minute = minutesTotal % 60;
		T.hour = (T.hour + minutesTotal / 60) % 24;

		return T;
	}

	Time Time::operator+(const Time& T2)
	{
		Time T1(*this);

		int minutesTotal = T1.minute + T2.minute;
		T1.minute = minutesTotal % 60;
		T1.hour = ((T1.hour + minutesTotal / 60) + T2.hour) % 24;

		return T1; 
	}

	Time operator+(int minutesNbr, Time T)
	{
		return T + minutesNbr;
	}

	Time Time::operator-(int minutesNbr)
	{
		Time T(*this);

		if (minutesNbr < 0) return T;

		int totalMinutes = (T.hour * 60) + T.minute;

		totalMinutes -= minutesNbr;

		while (totalMinutes < 0)
	    {
	        totalMinutes += 1440; // Car 24 heures est égal à 1440 minutes.
	    }

	    T.minute = totalMinutes % 60;
	    T.hour = (totalMinutes / 60) % 24;

		return T;
	}

	Time Time::operator-(const Time& T2)
	{
		Time T1(*this);

	    int minutesTotal1 = T1.hour * 60 + T1.minute;
	    int minutesTotal2 = T2.hour * 60 + T2.minute;

	    int minutesTotal = minutesTotal1 - minutesTotal2;

	    while (minutesTotal < 0)
	    {
	        minutesTotal += 1440; // Car 24 heures est égal à 1440 minutes.
	    }

	    T1.minute = minutesTotal % 60;
	    T1.hour = (minutesTotal / 60) % 24;

	    return T1;
	}

	Time operator-(int minutesNbr, Time T)
	{
		return T + minutesNbr;
	}

	int Time::comparisonT(const Time& T)
	{
		if (hour < T.hour) return -1;
		if (hour > T.hour) return 1;
		// Si heures égales
		if (minute < T.minute) return -1;
		if (minute > T.minute) return 1;

		// Si minutes égales
		return 0;
	}

	int Time::operator<(const Time& T)
	{
		return comparisonT(T) == -1;
	}

	int Time::operator>(const Time& T)
	{
		return comparisonT(T) == 1;
	}

	int Time::operator==(const Time& T)
	{
		return comparisonT(T) == 0;
	}

	ostream& operator<<(ostream& s, const Time& T)
	{
		s << T.getHour() << "h" << T.getMinute(); 
		return s; 
	}

	istream& operator>>(istream& s, Time& T)
	{
		int h, m;
		char separator;

		s >> h >> separator >> m;

		while (separator != 'h' || h < 0 || h > 23 || m < 0 || m > 59)
		{
			cout << "Entree incorrecte. Veuillez entrer l'heure sous le format hh:h:mm (ex : 14h20)." << endl;
			s.sync();
			s >> h >> separator >> m;
		}
		
		T.setHour(h);
		T.setMinute(m);
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