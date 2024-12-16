#include "Professor.h"

///////////////////////////////////////////
/////// Constructeur //////////////////////
///////////////////////////////////////////

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

///////////////////////////////////////////
/////// Destructeur ///////////////////////
///////////////////////////////////////////

Professor::~Professor()
{
	#ifdef DEBUG
      cout << ">>> Appelle du destructeur de Professor" << endl;
    #endif
}

///////////////////////////////////////////
/////// Setters ///////////////////////////
///////////////////////////////////////////

void Professor::setLastName(const string& l)
{
	lastName = l;
}

void Professor::setFirstName(const string& f)
{
	firstName = f;
}

///////////////////////////////////////////
/////// Getters ///////////////////////////
///////////////////////////////////////////

const string& Professor::getLastName() const
{
	return lastName;
}

const string& Professor::getFirstName() const
{
	return firstName;
}

///////////////////////////////////////////
/////// Méthodes d'instances //////////////
///////////////////////////////////////////

string Professor::toString() const
{
    return "[id=" + to_string(id) + "] " + lastName + " " + firstName;
}

string Professor::tuple() const
{
    return to_string(id) + ";" + lastName + ";" + firstName;
}

///////////////////////////////////////////
/////// Surcharge des opérateurs //////////
///////////////////////////////////////////

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
    s << p.toString();

    return s;
}
