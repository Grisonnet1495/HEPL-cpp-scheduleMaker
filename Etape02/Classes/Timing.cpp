#include "Timing.h"
#include "Time.h"

using namespace planning;

const string Timing::MONDAY = "Lundi";
const string Timing::TUESDAY = "Mardi";
const string Timing::WEDNESDAY = "Mercredi";
const string Timing::THURSDAY = "Jeudi";
const string Timing::FRIDAY = "Vendredi";
const string Timing::SATURDAY = "Samedi";
const string Timing::SUNDAY = "Dimanche";

// Constructeurs

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

// Destructeur

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

// Méthodes d'instances

void Timing::display() const
{
	cout << "Jour : " << day;
	cout << ", debut : ";
	start.display();
	cout << ", duree : ";
	duration.display();
}
