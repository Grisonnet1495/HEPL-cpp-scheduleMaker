#include "Timing.h"
#include "Time.h"
#include "TimingException.h"

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

		setDay("Lundi");
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

	Timing::Timing(string day, const Time& s, const Time& duration)
	{
		#ifdef DEBUG
			cout << ">>> Appelle du constructeur d'initialisation de Timing" << endl;
		#endif

		// Verifie si la duree n'est pas trop grande.
        Time t1(s);
        Time t2(duration);
        t1 = t1 + t2;

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
		if (d != MONDAY && d != TUESDAY && d != WEDNESDAY && d != THURSDAY && d != FRIDAY && d != SATURDAY && d != SUNDAY) throw TimingException("Jour invalide.", TimingException::INVALID_DAY);
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

	const string Timing::toString() const
	{
		string s;

		s = "Jour : " + day + ", debut : " + start.toString() + ", duree : " + duration.toString();

		return s;
	}

	const string Timing::tuple() const
	{
		string s;

		s = day + ";" + start.toString() + ";" + duration.toString();

		return s;
	}

	// Méthodes de surcharge d'opérateurs

	int Timing::comparisonT(const Timing& t2) const
	{
		Timing t1(*this);
		int dayNbr1 = getDayNumber(t1.day);
	    int dayNbr2 = getDayNumber(t2.day);

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

	int Timing::getDayNumber(const string d) const
	{
		if (d == MONDAY) return 1;
	    if (d == TUESDAY) return 2;
	    if (d == WEDNESDAY) return 3;
	    if (d == THURSDAY) return 4;
	    if (d == FRIDAY) return 5;
	    if (d == SATURDAY) return 6;
	    if (d == SUNDAY) return 7;

	    return 0;
	}

	bool Timing::operator<(const Timing& t) const
	{
		return comparisonT(t) == -1;
	}

	bool Timing::operator>(const Timing& t) const
	{
		return comparisonT(t) == 1;
	}

	bool Timing::operator==(const Timing& t) const
	{
		return comparisonT(t) == 0;
	}

	ostream& operator<<(ostream& s, const Timing& t)
	{
		s << "<Timing>" << endl;
		s << "<day>" << endl;
		s << t.day << endl;
		s << "</day>" << endl;
		s << "<start>" << endl;
		s << t.start << endl;
		s << "</start>" << endl;
		s << "<duration>" << endl;
		s << t.duration << endl;
		s << "</duration>" << endl;
		s << "</Timing>";

		return s;
	}

	istream& operator>>(istream& s, Timing& t)
	{
		string sDay, tag;
		Time start, duration;
		
		getline(s, tag);
		getline(s, tag);
		getline(s, sDay);
		getline(s, tag);
		getline(s, tag);
		s >> start;
		getline(s, tag);
		getline(s, tag);
		s >> duration;
		getline(s, tag);
		getline(s, tag);

		t.setDay(sDay);
		t.setStart(start);
		t.setDuration(duration);

		return s;
	}

	bool Timing::intersect(const Timing& t) const
	{
		Timing t2(*this);

		// Verifier si les jours sont egaux
	    if (t2.day != t.day) return false;

	    // Calculer l'heure de fin
	    Time t2End(t2.start);
	    Time tEnd(t.start);
	    t2End = t2End + t2.duration;
	    tEnd = tEnd + t.duration;

	    // Verifier si les plages horaires se chevauchent
	    return !(t2End <= t.start || tEnd <= t2.start);
	}
}
