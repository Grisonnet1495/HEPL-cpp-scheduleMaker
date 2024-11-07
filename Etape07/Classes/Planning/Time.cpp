#include "Time.h"
#include "../Exception/TimeException.h"

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
		if (h < 0 || h > 23) throw TimeException("Heure invalide.", TimeException::INVALID_HOUR);
		hour = h;
	}

	void Time::setMinute(int m)
	{
		if (m < 0 || m > 59) throw TimeException("Minute invalide.", TimeException::INVALID_MINUTE);
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
		int finalHour;

		if (minutesNbr < 0) return t; 

		int minutesTotal = (t.minute + minutesNbr);
		
		if ((finalHour = (t.hour + minutesTotal / 60)) > 23) throw TimeException("Resultat plus grand que 23h59.", TimeException::OVERFLOW);

		t.minute = minutesTotal % 60;
		t.hour = finalHour;

		return t;
	}

	Time Time::operator+(const Time& t2)
	{
		Time t1(*this);
		int finalHour;

		int minutesTotal = t1.minute + t2.minute;
		
		if ((finalHour = ((t1.hour + minutesTotal / 60) + t2.hour)) > 23) throw TimeException("Resultat plus grand que 23h59.", TimeException::OVERFLOW);

		t1.minute = minutesTotal % 60;
		t1.hour = finalHour;

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

		if (totalMinutes < 0) throw TimeException("Resultat plus petit que 0h00.", TimeException::OVERFLOW);

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

	    if (minutesTotal < 0) throw TimeException("Resulatat plus petit que 0h00.", TimeException::OVERFLOW);

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
		s << "<Time>" << endl;
		s << "<hour>" << endl;
		s << t.hour << endl;
		s << "</hour>" << endl;
		s << "<minute>" << endl;
		s << t.minute << endl;
		s << "</minute>" << endl;
		s << "</Time>";

		return s;
	}

	istream& operator>>(istream& s, Time& t)
	{
		string sHour, sMinute, tag;
		
		getline(s, tag);
		getline(s, tag);
		getline(s, sHour);
		getline(s, tag);
		getline(s, tag);
		getline(s, sMinute);
		getline(s, tag);
		getline(s, tag);

		t.setHour(stoi(sHour));
		t.setMinute(stoi(sMinute));

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
