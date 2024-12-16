#include "Professor.h"

// Constructeurs

Professor::Professor():Schedulable()
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur par defaut de Professor" << endl;
    #endif

    setLastName("---");
    setFirstName("---");
}

Professor::Professor(int id, const string& l, const string& f):Schedulable(id)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur d'initialisation de Professor" << endl;
    #endif

    setLastName(l);
    setFirstName(f);
}

Professor::Professor(const Professor& p):Schedulable(p)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur de copie de Professor" << endl;
    #endif

    setLastName(p.lastName);
    setFirstName(p.firstName);
}

// Destructeur

Professor::~Professor()
{
	#ifdef DEBUG
      cout << ">>> Appelle du destructeur de Professor" << endl;
    #endif
}

// Setters

void Professor::setLastName(const string& l)
{
	lastName = l;
}

void Professor::setFirstName(const string& f)
{
	firstName = f;
}

// Getters

const string& Professor::getLastName() const
{
	return lastName;
}

const string& Professor::getFirstName() const
{
	return firstName;
}

// Méthodes d'instances

string Professor::toString() const
{
    return "[id=" + to_string(id) + "] " + lastName + " " + firstName;
}

string Professor::tuple() const
{
    return to_string(id) + ";" + lastName + ";" + firstName;
}

// Méthodes de surcharge d'opérateurs

Professor& Professor::operator=(const Professor& p)
{
    Schedulable::operator=(p);
    lastName = p.lastName;
    firstName = p.firstName;

    return (*this);
}

bool Professor::operator<(const Professor& p) const
{
    if (lastName != p.lastName) return lastName < p.lastName;
    if (firstName != p.firstName) return firstName < p.firstName;
    return id < p.id;
}

ostream& operator<<(ostream& s, const Professor& p)
{
    s << "<Professor>" << endl;
    s << "<id>" << endl;
    s << p.id << endl;
    s << "</id>" << endl;
    s << "<lastName>" << endl;
    s << p.lastName << endl;
    s << "</lastName>" << endl;
    s << "<firstName>" << endl;
    s << p.firstName << endl;
    s << "</firstName>" << endl;
    s << "</Professor>";

    return s;
}

istream& operator>>(istream& s, Professor& p)
{
    string sId, sLastName, sFirstName, tag;
    getline(s, tag);
    getline(s, tag);
    getline(s, sId);
    getline(s, tag);
    getline(s, tag);
    getline(s, sLastName);
    getline(s, tag);
    getline(s, tag);
    getline(s, sFirstName);
    getline(s, tag);
    getline(s, tag);

    c.setId(stoi(sId));
    c.setLastName(sLastName);
    c.setFirstName(sFirstName);

    return s;
}
