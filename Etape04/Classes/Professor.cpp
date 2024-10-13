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

Professor::Professor(const string& l, const string& f)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur d'initialisation de Professor" << endl;
    #endif

    setLastName(l);
    setFirstName(f);
}

Professor::Professor(const Professor& p)
{
	#ifdef DEBUG
      cout << ">>> Appelle du constructeur de copie de Professor" << endl;
    #endif

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
