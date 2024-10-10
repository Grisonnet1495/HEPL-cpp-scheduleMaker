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

	Timing::Timing(const Timing &T)
	{
		#ifdef DEBUG
			cout << ">>> Appelle du constructeur de copie de Timing" << endl;
		#endif

		setDay(T.day);
		setStart(T.start);
		setDuration(T.duration);
	}

	Timing::Timing(string day, const Time &s, const Time &duration)
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

	void Timing::setStart(const Time &s)
	{
		start.setHour(s.getHour());
		start.setMinute(s.getMinute());
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
}
