#include "Classroom.h"

using namespace std;

// Constructeurs

Classroom::Classroom():Schedulable()
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur par defaut de Classroom" << endl;
    #endif

    setName("---");
    setSeatingCapacity(0);
}

Classroom::Classroom(const string& n, int s):Schedulable(i)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur d'initialisation de Classroom" << endl;
    #endif

    setName(n);
    setSeatingCapacity(s);
}

Classroom::Classroom(const Classroom& c):Schedulable(c)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur de copie de Classroom" << endl;
    #endif

    setName(c.name);
    setSeatingCapacity(c.seatingCapacity);
}

// Destructeur

Classroom::~Classroom()
{
	#ifdef DEBUG
      cout << ">>> Appelle du destructeur de Classroom" << endl;
    #endif
}

// Setters

void Classroom::setName(const string& n)
{
	name = n;
}

void Classroom::setSeatingCapacity(int s)
{
	seatingCapacity = s;
}

// Getters

const string& Classroom::getName() const
{
	return name;
}

int Classroom::getSeatingCapacity() const
{
	return seatingCapacity;
}

// Méthodes d'instances

string Classroom::toString() const
{
    return name + " (" + to_string(seatingCapacity) + ")";
}

string Classroom::tuple() const
{
    return to_string(id) + ";" + name + " (" + to_string(seatingCapacity) + ")";
}

// Méthodes de surcharge d'opérateurs

Classroom& Classroom::operator=(const Classroom& c)
{
    Schedulable::operator=(c);
    name = c.name;
    seatingCapacity = c.seatingCapacity;

    return (*this);
}

ostream& operator<<(ostream& s, const Classroom& c)
{
    s << "<Classroom>" << endl;
    s << "<id>" << endl;
    s << c.id << endl;
    s << "</id>" << endl;
    s << "<name>" << endl;
    s << c.name << endl;
    s << "</name>" << endl;
    s << "<seatingCapacity>" << endl;
    s << c.seatingCapacity << endl;
    s << "</seatingCapacity>" << endl;
    s << "</Classroom>";

    return s;
}

istream& operator>>(istream& s, Classroom& c)
{
    string sId, sName, sSeatingCapacity, tag;
    getline(s, tag);
    getline(s, tag);
    getline(s, sId);
    getline(s, tag);
    getline(s, tag);
    getline(s, sName);
    getline(s, tag);
    getline(s, tag);
    getline(s, sSeatingCapacity);
    getline(s, tag);
    getline(s, tag);

    c.setId(stoi(sId));
    c.setName(sName);
    c.setSeatingCapacity(stoi(sSeatingCapacity));

    return s;
}
