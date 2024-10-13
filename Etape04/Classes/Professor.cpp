#include "Professor.h"

// Constructeurs

Professor::Professor()
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur par defaut de Professor" << endl;
    #endif

    setLastName("---");
    setFirstName("---");
}

Professor::Professor(int i, const string& l, const string& f)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur d'initialisation de Professor" << endl;
    #endif

    setId(i);
    setLastName(l);
    setFirstName(f);
}

Professor::Professor(const Professor& p)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur de copie de Professor" << endl;
    #endif

    setId(p.id);
    setLastName(p.lastName);
    setFirstName(p.firstName);
}

// Destructeurs

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

const string Professor::getLastName() const
{
	return lastName;
}

const string Professor::getFirstName() const
{
	return firstName;
}

// Méthodes d'instances

string Professor::toString() const
{
    return lastName + " " + firstName;
}

string Professor::tuple() const
{
    return to_string(id) + ";" + lastName + ";" + firstName;
}

// Méthodes de surcharge d'opérateurs

ostream& operator<<(ostream& s, const Professor& p)
{
    s << p.toString();

    return s;
}
