#include "Time.h"

using namespace planning;

// Constructeurs

Time::Time()
{
	#ifdef DEBUG
		cout << ">>> Appelle du constructeur par defaut de Time" << endl;
	#endif

	setHour(0);
	setMinute(0);
}

Time::Time(const Time &T)
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

	T.minute = (T.minute + minutesNbr) % 60;
	T.hour = (T.hour + minuteNbr / 60) % 24;

	return T; 
}

Time operator+(const Time& T2)
{
	Time T1(*this);

	T1.minute = (T1.minute + T2.minute) % 60;
	T1.hour = ((T1.hour + T2.minute / 60) + T2.hour) % 24;

	return T1; 
}

friend Time operator+(int minutesNbr, Time T)
{
	return T + minutesNbr;
}