#include "Timing.h"
#include "Time.h"

Timing::Timing()
{
	setDay("---");
	setStart(Time());
	setDuration(Time());
}

Timing::Timing(const Timing &T)
{
	setDay(T.day);
	setStart(T.start);
	setDuration(T.duration);
}

Timing::Timing(string day, const Time &s, const Time &duration)
{
	setDay(day);
	setStart(s);
	setDuration(duration);
}

Timing::~Timing()
{

}

string Timing::getDay() const
{
	return day;
}

Time Timing::getStart() const
{
	return start;
}

Time Timing::getDuration() const
{
	return duration;
}

void Timing::setDay(const string d)
{
	day = d;
}

void Timing::setStart(const Time &s)
{
	start = s;
}

void Timing::setDuration(const Time &d)
{
	duration = d;
}

void Timing::display() const
{
	cout << "Jour : " << day;
	cout << ", debut : ";
	start.display();
	cout << ", duree : ";
	duration.display();
}
