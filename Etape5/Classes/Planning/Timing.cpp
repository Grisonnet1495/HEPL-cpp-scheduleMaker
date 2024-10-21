#include "Timing.h"
#include "Time.h"

namespace planning
{
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
		#ifdef DEBUG
			cout << ">>> Appelle du constructeur par defaut de Timing" << endl;
		#endif

		setDay("---");
		setStart(Time());
		setDuration(Time());
	}

	Timing::Timing(const Timing& t)
	{
		#ifdef DEBUG
			cout << ">>> Appelle du constructeur de copie de Timing" << endl;
		#endif

		setDay(t.day);
		setStart(t.start);
		setDuration(t.duration);
	}

	Timing::Timing(string day, const Time& s, const Time &duration)
	{
		#ifdef DEBUG
			cout << ">>> Appelle du constructeur d'initialisation de Timing" << endl;
		#endif

		setDay(day);
		setStart(s);
		setDuration(duration);
	}

	// Destructeur

	Timing::~Timing()
	{
		#ifdef DEBUG
			cout << ">>> Appelle du destructeur par defaut de Timing" << endl;
		#endif
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

	void Timing::setStart(const Time& s)
	{
		start.setHour(s.getHour());
		start.setMinute(s.getMinute());
	}

	void Timing::setDuration(const Time& d)
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

	// Méthodes de surcharge d'opérateurs

	int Timing::comparisonT(const Timing& t2)
	{
		Timing t1(*this);
		int dayNbr1 = 0, dayNbr2 = 0;

	    if (t1.day == Timing::MONDAY) dayNbr1 = 1;
	    else if (t1.day == Timing::TUESDAY) dayNbr1 = 2;
	    else if (t1.day == Timing::WEDNESDAY) dayNbr1 = 3;
	    else if (t1.day == Timing::THURSDAY) dayNbr1 = 4;
	    else if (t1.day == Timing::FRIDAY) dayNbr1 = 5;
	    else if (t1.day == Timing::SATURDAY) dayNbr1 = 6;
	    else if (t1.day == Timing::SUNDAY) dayNbr1 = 7;

	    if (t2.day == Timing::MONDAY) dayNbr2 = 1;
	    else if (t2.day == Timing::TUESDAY) dayNbr2 = 2;
	    else if (t2.day == Timing::WEDNESDAY) dayNbr2 = 3;
	    else if (t2.day == Timing::THURSDAY) dayNbr2 = 4;
	    else if (t2.day == Timing::FRIDAY) dayNbr2 = 5;
	    else if (t2.day == Timing::SATURDAY) dayNbr2 = 6;
	    else if (t2.day == Timing::SUNDAY) dayNbr2 = 7;

		if (dayNbr1 < dayNbr2) return -1;
		if (dayNbr1 > dayNbr2) return 1;
		// Si jours égaux
		if (t1.start < t2.start) return -1;
		if (t1.start > t2.start) return 1;
		// Si heures de début égales
		if (t1.duration < t2.duration) return -1;
		if (t1.duration > t2.duration) return 1;

		// Si durées égales
		return 0;
	}

	int Timing::operator<(const Timing& t)
	{
		return comparisonT(t) == -1;
	}

	int Timing::operator>(const Timing& t)
	{
		return comparisonT(t) == 1;
	}

	int Timing::operator==(const Timing& t)
	{
		return comparisonT(t) == 0;
	}
}
